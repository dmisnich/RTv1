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

t_vector	g_tmp[4];
t_vector	g_p[2];
t_vector	g_norm;
t_vector	g_oc;
t_vector	g_k;
float		g_m;
float		g_res;
float		g_dot;

float		sphere_normal(t_object *ret, t_sdl *sdl)
{
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_norm = vector_sub(&g_p[1], &ret->pos);
	g_norm = vector_mult_scal(&g_norm, 1.0 / vector_len(&g_norm));
	g_norm = vector_norm(&g_norm);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		cylindre_normal(t_object *ret, t_sdl *sdl)
{
	g_oc = vector_sub(&sdl->camera.cam, &ret->pos);
	g_m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest)
	+ vector_dot(&g_oc, &ret->n);
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_tmp[0] = vector_mult_scal(&ret->n, g_m);
	g_tmp[1] = vector_sub(&g_p[1], &ret->pos);
	g_tmp[2] = vector_sub(&g_tmp[0], &g_tmp[1]);
	g_norm = vector_norm(&g_tmp[2]);
	g_norm = vector_mult_scal(&g_norm, -1);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		plane_normal(t_object *ret, t_sdl *sdl)
{
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_norm = vector_norm(&ret->n);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}

float		cone_normal(t_object *ret, t_sdl *sdl)
{
	g_oc = vector_sub(&sdl->camera.cam, &ret->pos);
	g_m = (vector_dot(&sdl->ray.dir, &ret->n) * sdl->closest)
	+ vector_dot(&g_oc, &ret->n);
	g_p[0] = vector_mult_scal(&sdl->ray.dir, sdl->closest);
	g_p[1] = vector_add(&sdl->camera.cam, &g_p[0]);
	g_res = 1 + pow(ret->tan, 2);
	g_tmp[0] = vector_mult_scal(&ret->n, g_m);
	g_tmp[1] = vector_mult_scal(&g_tmp[0], g_res);
	g_tmp[2] = vector_sub(&g_p[1], &ret->pos);
	g_norm = vector_sub(&g_tmp[2], &g_tmp[1]);
	g_norm = vector_norm(&g_norm);
	g_dot = vector_dot(&g_norm, &sdl->ray.dir);
	if (g_dot < 0)
		g_norm = g_norm;
	else
		g_norm = vector_mult_scal(&g_norm, -1);
	return (findelight(&g_p[1], &g_norm, sdl, ret));
}
