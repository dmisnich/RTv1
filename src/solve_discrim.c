/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_discrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:36:04 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/09 13:36:05 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	*find_solve_discrim(t_sdl *sdl, float a, float b, float c, t_object *obj)
{
	t_discrim	tsp;
	float		discrim;

	discrim = (b * b) - (4 * a * c);
	if (discrim > 0)
	{
		if ((tsp.x1 = (-b + sqrtf(discrim)) / (2.0 * a)))
			obj->dist = tsp.x1;
		if ((tsp.x2 = (-b - sqrtf(discrim)) / (2.0 * a)) && tsp.x2 < tsp.x1)
			obj->dist = tsp.x2;
		return (obj);
	}
	return (NULL);
}
