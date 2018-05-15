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

t_object		*find_cone(t_object *obj, t_sdl *sdl)
{
	t_vector	oc;
	float		discrim;
	float		param[3];

	obj->n = vector_norm(&obj->n);
	sdl->ray.dir = vector_norm(&sdl->ray.dir);
	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	param[0] = vector_dot(&sdl->ray.dir, &sdl->ray.dir)
	- (1 + obj->tan * obj->tan) * (vector_dot(&sdl->ray.dir, &obj->n))
	* (vector_dot(&sdl->ray.dir, &obj->n));
	param[1] = 2 * vector_dot(&oc, &sdl->ray.dir) - (1 + obj->tan * obj->tan)
	* (vector_dot(&sdl->ray.dir, &obj->n)) * (vector_dot(&oc, &obj->n) * 2);
	param[2] = vector_dot(&oc, &oc) - (1 + obj->tan * obj->tan) *
	(vector_dot(&oc, &obj->n) * vector_dot(&oc, &obj->n));
	return (find_solve_discrim(sdl, param, obj));
}
