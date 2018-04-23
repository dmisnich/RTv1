/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:21:32 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/23 14:21:34 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_discrim	finde_cone(t_object *obj, t_sdl *sdl)
{
	t_discrim	tsp;
	t_vector	oc;
	float		discrim;
	float		a;
	float		b;
	float		c;

	obj->n = vector_norm(&obj->n);
	sdl->ray.dir = vector_norm(&sdl->ray.dir);
	int m = vector_len(&obj->n);
	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	a = vector_dot(&sdl->ray.dir, &sdl->ray.dir)
	- (1 + obj->radius * obj->radius) * (vector_dot(&sdl->ray.dir, &obj->n)) * (vector_dot(&sdl->ray.dir, &obj->n));
	b = 2 * vector_dot(&oc, &sdl->ray.dir) - (1 + obj->radius * obj->radius) * (vector_dot(&sdl->ray.dir, &obj->n)) * (vector_dot(&oc, &obj->n));;
	c = vector_dot(&oc, &oc) - (1 + obj->radius * obj->radius) * (vector_dot(&oc, &obj->n) * vector_dot(&oc, &obj->n));
	discrim = b * b - (4 * a * c);
	if (discrim < 0)
		return((t_discrim){-1, -1});
	tsp.x1 = (-b + sqrt(discrim) / (2.0 * a));
	tsp.x2 = (-b - sqrt(discrim) / (2.0 * a));
	return (tsp);
}