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

void	raycaster(t_sdl *sdl)
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
			sdl->ray.dir = find_ray_diraction(sdl, x - (WIDTH / 2), (HEIGHT / 2) - y);
			sdl->ray.dir = vector_norm(&sdl->ray.dir);
			color = ray_tracer_obj(sdl);
			sdl->buff[x + y * WIDTH] = color;
			x++;
		}
		y++;
	}
}

int		draw_scene(t_sdl *sdl)
{
	t_discrim tsp;
	t_object *obj;
	t_object *ret;
	t_color	 color;
	float dist;
	int i;

	i = 0;
	sdl->closest = INFINITY;
	while (i < sdl->scene->max_obj)
	{
		if (sdl->scene->obj[i].name == SPHERE && (obj = find_sphere(&sdl->scene->obj[i], sdl)) != NULL)
		{
			if (sdl->closest > obj->dist)
			{
				sdl->closest = obj->dist;
				color = obj->color;
				ret = obj;
			}
		}
		if (sdl->scene->obj[i].name == PLANE && (obj = find_plane(&sdl->scene->obj[i], sdl)) != NULL)
		{
		 	if (sdl->closest > obj->dist)
			{
				sdl->closest = obj->dist;
				color = obj->color;
				ret = obj;
			}
		}
		if (sdl->scene->obj[i].name == CYLINDRE && (obj = find_cylindre(&sdl->scene->obj[i], sdl)) != NULL)
		{
			if (sdl->closest > obj->dist)
			{
				sdl->closest = obj->dist;
				color = obj->color;
				ret = obj;
			}
		}
		if (sdl->scene->obj[i].name == CONE && (obj = find_cone(&sdl->scene->obj[i], sdl)) != NULL)
		{
			if (sdl->closest > obj->dist)
			{
				sdl->closest = obj->dist;
				color = obj->color;
				ret = obj;
			}
		}
		i++;
	}
	if (sdl->closest == INFINITY)
		return (0);
	float cl = find_normal(ret, sdl);
	return (color_test(&color, cl));
}

float	find_normal(t_object *ret, t_sdl *sdl)
{
	// t_vector p[2];
	// t_vector norm;
	// t_vector oc;
	// float	m;
	// t_vector tmp[3];

	if (ret->name == SPHERE)
		return (sphere_normal(ret, sdl));
	if (ret->name == PLANE)
		return (plane_normal(ret, sdl));
	if (ret->name == CYLINDRE)
		return (cylindre_normal(ret, sdl));
	if (ret->name == CONE)
		return (cone_normal(ret, sdl));
	return (0);
}

int		ray_tracer_obj( t_sdl *sdl)
{
	if (sdl->scene->name == SCENE_1)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_2)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_3)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_4)
		return (draw_scene(sdl));
	if (sdl->scene->name == SCENE_5)
		return (draw_scene(sdl));
	return (0);
}
