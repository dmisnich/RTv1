/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:37:09 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/09 13:37:13 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		light(t_sdl *sdl, int i, t_object *obj, t_discrim tsp)
{
	t_vector p;
	t_vector tmp;
	t_vector p1;
	t_vector norm;
	t_vector oc;
	float	m;
	p1 = vector_mult_scal(&sdl->ray.dir, sdl->closest_sphere);
	p = vector_add(&sdl->camera.cam, &p1);
	norm = vector_sub(&p, &sdl->scene->obj[i].pos);
	norm = vector_mult_scal(&norm, 1.0 / vector_len(&norm));
	// oc = vector_sub(&sdl->camera.cam, &obj->pos);
	// m = (vector_dot(&sdl->ray.dir, &obj->n) * tsp.x1 + vector_dot(&oc, &obj->n));
	// tmp = vector_mult_scal(&obj->n, m);
	// tmp2 = vector_sub()
	return (findelight(&p, &norm, sdl));
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
			{
				l = vector_sub(&sdl->light[i].pos, p);
			}
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
