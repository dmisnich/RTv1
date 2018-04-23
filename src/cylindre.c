/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:17:15 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/12 13:17:16 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_discrim	finde_cylindre(t_object *obj, t_sdl *sdl)
{
	t_discrim	tsp;
	t_vector	oc;
	float		discrim;
	float		a;
	float		b;
	float		c;
	t_vector n;

	n.x = 1;
	n.y = 1;
	n.z = 1;

	n = vector_norm(&n);
	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	a = vector_dot(&sdl->ray.dir, &sdl->ray.dir) - (vector_dot(&sdl->ray.dir, &n)) * (vector_dot(&sdl->ray.dir, &n));
	b = 2 * vector_dot(&oc, &sdl->ray.dir) - (vector_dot(&sdl->ray.dir, &n)) * (vector_dot(&oc, &n));;
	c = vector_dot(&oc, &oc) - (vector_dot(&oc, &n) * vector_dot(&oc, &n)) - obj->radius * obj->radius;
	discrim = b * b - (4 * a * c);
	if (discrim < 0)
		return((t_discrim){-1, -1});
	tsp.x1 = (-b + sqrt(discrim) / (2.0 * a));
	tsp.x2 = (-b - sqrt(discrim) / (2.0 * a));
	// printf("x1: %f\n", tsp.x1);
	// printf("x2: %f\n", tsp.x2);
	return (tsp);
}

