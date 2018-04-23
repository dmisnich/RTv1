/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:40:10 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/11 14:40:11 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_discrim		finde_plane(t_object *obj, t_sdl *sdl, float min, float max)
{
	t_vector	x;
	float		res;
	t_discrim	tsp;

	obj->n = vector_norm(&obj->n);
	x = vector_sub(&sdl->camera.cam, &obj->pos);
	res = vector_dot(&sdl->ray.dir, &obj->n);
	if (res == 0)
		return ((t_discrim){0, 0});
	tsp.x1 = -vector_dot(&x, &obj->n) / res;
	tsp.x2 = 0.0;
	return (tsp);
}
