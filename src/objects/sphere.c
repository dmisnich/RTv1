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

t_object	*find_sphere(t_object *obj, t_sdl *sdl)
{
	t_discrim	tsp;
	t_vector	oc;
	float		discrim;
	float		a;
	float		b;
	float		c;

	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	a = vector_dot(&sdl->ray.dir, &sdl->ray.dir);
	b = 2 * vector_dot(&oc, &sdl->ray.dir);
	c = vector_dot(&oc, &oc) - obj->radius * obj->radius;
	return (find_solve_discrim(sdl, a, b, c, obj));
}
