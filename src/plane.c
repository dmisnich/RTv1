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
	float test;
	// float dist;
	t_discrim	tsp;
	t_vector	n;
	t_vector	t;

	n.x = 0;
	n.y = 1;
	n.z = 0;
	n = vector_norm(&n);
	x = vector_sub(&sdl->camera.cam, &obj->pos);

	test = vector_dot(&sdl->ray.dir, &n);
	if (test == 0)
		return ((t_discrim){0, 0});
	tsp.x1 = -vector_dot(&x, &n) / test;
	tsp.x2 = 0.0;
	return (tsp);
}
