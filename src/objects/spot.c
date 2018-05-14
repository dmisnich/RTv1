/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:37:09 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/09 13:37:13 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			g_i;
float		g_res;
// float		g_res_dot;
float		g_n_dot;
// float		g_r_dot_v;
float		g_len_norm;
// t_vector	g_r[4];
t_vector	g_l;
// t_vector	g_v;

float		findelight(t_vector *p, t_vector *norm, t_sdl *sdl, t_object *ret)
{
	g_i = 0;
	g_res = 0.0;
	// g_v = vector_mult_scal(&sdl->ray.dir, -1);
	g_len_norm = vector_len(norm);
	while (g_i < 2)
	{
		if (sdl->light[g_i].type == AMBIENT)
		{
			g_res += sdl->light[g_i].intensity;
		}
		else
		{
			if (sdl->light[g_i].type == POINT)
			{
				g_l = vector_sub(&sdl->light[g_i].pos, p);
			}
			else
				g_l = sdl->light[g_i].pos;
			g_n_dot = vector_dot(norm, &g_l);
			if (g_n_dot > 0)
				g_res += (sdl->light[g_i].intensity * g_n_dot) /
			(g_len_norm * vector_len(&g_l));
			// if (ret->specular != -1)
			// {
			// 	g_r[0] = vector_mult_scal(norm, 2);
			// 	g_res_dot = vector_dot(norm, &g_l);
			// 	g_r[1] = vector_mult_scal(&g_r[0], g_res_dot);
			// 	g_r[2] = vector_sub(&g_r[1], &g_l);
			// 	g_r_dot_v = vector_dot(&g_r[2], &g_v);
			// 	if (g_r_dot_v > 0)
			// 		g_res += (sdl->light[g_i].intensity * pow(g_r_dot_v /
			// 			vector_len(&g_r[2]) * vector_len(&g_v), ret->specular));
			// }
		}
		g_i++;
	}
	return (g_res);
}
