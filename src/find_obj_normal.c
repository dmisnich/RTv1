/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:27:27 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/11 12:27:29 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	tmp[4];
t_vector	p[2];
t_vector	norm;
t_vector	oc;
t_vector	k;
float		m;
float		res;
float		dot;

float		sphere_normal(t_object *ret, t_sdl *sdl)
{
	p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	p[1] = vector_add(&sdl->camera.cam, &p[0]);
	norm = vector_sub(&p[1], &ret->pos);
	norm = vector_mult_scal(&norm, 1.0 / vector_len(&norm));
	norm = vector_norm(&norm);
	dot = vector_dot(&norm, &sdl->ray.dir);
	if (dot < 0)
		norm = norm;
	else
		norm = vector_mult_scal(&norm, -1);
	return (findelight(&p[1], &norm, sdl));
}

float		cylindre_normal(t_object *ret, t_sdl *sdl)
{
	oc = vector_sub(&sdl->camera.cam, &ret->pos);
	m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest) + vector_dot(&oc, &ret->n);
	p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	p[1] = vector_add(&sdl->camera.cam, &p[0]);
	tmp[0] = vector_mult_scal(&ret->n, m);
	tmp[1] = vector_sub(&p[1], &ret->pos);
	tmp[2] = vector_sub(&tmp[0], &tmp[1]);
	norm = vector_norm(&tmp[2]);
	norm = vector_mult_scal(&norm, -1);
	dot = vector_dot(&norm, &sdl->ray.dir);
	if (dot < 0)
		norm = norm;
	else
		norm = vector_mult_scal(&norm, -1);
	return (findelight(&p[1], &norm, sdl));
}

float		plane_normal(t_object *ret, t_sdl *sdl)
{
	p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	p[1] = vector_add(&sdl->camera.cam, &p[0]);
	norm = vector_norm(&ret->n);
	dot = vector_dot(&norm, &sdl->ray.dir);
	if (dot < 0)
		norm = norm;
	else
		norm = vector_mult_scal(&norm, -1);
	return (findelight(&p[1], &norm, sdl));
}

float		cone_normal(t_object *ret, t_sdl *sdl)
{
	oc = vector_sub(&sdl->camera.cam, &ret->pos);
	m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest) + vector_dot(&oc, &ret->n);

	//psrt 1

	p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	p[1] = vector_add(&sdl->camera.cam, &p[0]);

	//part 2

	res = 1 + pow(ret->tan, 2);
	tmp[0] = vector_mult_scal(&ret->n, m);
	tmp[1] = vector_mult_scal(&tmp[0], res);
	tmp[2] = vector_sub(&p[1], &ret->pos);
	norm = vector_sub(&tmp[2], &tmp[1]);
	norm = vector_norm(&norm);
	dot = vector_dot(&norm, &sdl->ray.dir);
	if (dot < 0)
		norm = norm;
	else
		norm = vector_mult_scal(&norm, -1);
	return (findelight(&p[1], &norm, sdl));
}
