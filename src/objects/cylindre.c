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

t_object	*find_cylindre(t_object *obj, t_sdl *sdl)
{
	t_discrim	tsp;
	t_vector	oc;
	float		param[3];

	obj->n = vector_norm(&obj->n);

	sdl->ray.dir = vector_norm(&sdl->ray.dir);

	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	param[0] = vector_dot(&sdl->ray.dir, &sdl->ray.dir) - pow(vector_dot(&sdl->ray.dir, &obj->n), 2);
	param[1] = 2.0 * vector_dot(&sdl->ray.dir, &oc) - vector_dot(&sdl->ray.dir, &obj->n) * (vector_dot(&oc, &obj->n) * 2);
	param[2] = vector_dot(&oc, &oc) - pow(vector_dot(&oc, &obj->n), 2) - pow(obj->radius, 2);
	return (find_solve_discrim(sdl, param[0], param[1], param[2], obj));
}
