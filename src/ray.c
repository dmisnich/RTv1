/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:53:25 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/03 12:53:28 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(t_sdl *sdl)
{
	int x;
	int y;
	int color;

	sdl->buff = sdl->surface->pixels;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			sdl->ray.dir = change_coords(sdl, x - (WIDTH / 2), (HEIGHT / 2) - y);
			color = ray_tracer_obj(sdl, 0, 10000000);
			sdl->buff[x + y * WIDTH] = color;
			x++;
		}
		y++;
	}
}

int		ray_tracer_obj( t_sdl *sdl, float min, float max)
{
	t_discrim tsp;
	t_vector p;
	t_vector p1;
	t_vector norm;
	int i = 4;

	sdl->closest_sphere = 0;
	while (i < 5)
	{
		if (sdl->obj[i].name == SPHERE)
			tsp = finde_sphere(&sdl->obj[i], sdl);
		if (sdl->obj[i].name == PLANE)
		 	tsp = finde_plane(&sdl->obj[i], sdl, 0, 10000000);
		// if (sdl->obj[i].name == CYLINDRE)
		//  	tsp = finde_cylindre(&sdl->obj[i], sdl);
		if (tsp.x1 > 0 && tsp.x1 > sdl->closest_sphere && tsp.x1 > min && tsp.x1 < max)
		{
			sdl->closest_sphere = tsp.x1;
			break ;
		}
		if (tsp.x2 > 0 && tsp.x2 > sdl->closest_sphere && min < tsp.x2 && tsp.x2 < max)
		{
			sdl->closest_sphere = tsp.x2;
			break ;
		}
		i++;
	}
	if (sdl->closest_sphere == 0)
		return (0);
	p1 = vector_mult_scal(&sdl->ray.dir, sdl->closest_sphere);
	p = vector_add(&sdl->camera.cam, &p1);
	norm = vector_sub(&p, &sdl->obj[i].pos);
	norm = vector_mult_scal(&norm, 1.0 / vector_len(&norm));
	float cl = findelight(&p, &norm, sdl);
	return (color(sdl, i, cl));
}

float		findelight(t_vector *p, t_vector *norm, t_sdl *sdl)
{
	int i;
	float res;
	float n_dot;
	float len_norm;
	t_vector l;


	i = 0;
	res = 0.0;
	len_norm = vector_len(norm);
	while (i < 2)
	{
		if (sdl->light[i].type == AMBIENT)
		{
			res += sdl->light[i].intensity;
		}
		else
		{
			if (sdl->light[i].type == POINT)
				l = vector_sub(&sdl->light[i].pos, p);
			else
				l = sdl->light[i].pos;
			n_dot = vector_dot(norm, &l);
			if (n_dot > 0)
				res += (sdl->light[i].intensity * n_dot) / (len_norm * vector_len(&l));
		}
		i++;
	}
	return (res);
}
