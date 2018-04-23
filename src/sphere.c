/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:13:44 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/11 11:13:46 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_discrim	finde_sphere(t_object *obj, t_sdl *sdl)
{
	t_discrim	tsp;
	t_vector	oc;
	float		discrim;
	float		a;
	float		b;
	float		c;
	
	// printf("test\n");
	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	a = vector_dot(&sdl->ray.dir, &sdl->ray.dir);
	b = 2 * vector_dot(&oc, &sdl->ray.dir);
	c = vector_dot(&oc, &oc) - obj->radius * obj->radius;
	discrim = b * b - (4 * a * c);
	if (discrim < 0)
		return((t_discrim){-1, -1});
	tsp.x1 = (-b + sqrt(discrim) / (2.0 * a));
	tsp.x2 = (-b - sqrt(discrim) / (2.0 * a));
	return (tsp);
}
