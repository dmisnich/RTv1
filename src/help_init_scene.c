/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_init_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:42:17 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/03 14:42:28 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	help1_init_scene_1(t_object **obj)
{
	(*obj)[1].name = SPHERE;
	(*obj)[1].radius = 1.0;
	(*obj)[1].pos.x = -2.0;
	(*obj)[1].pos.y = -1.0;
	(*obj)[1].pos.z = -2.0;
	(*obj)[1].color.r = 255;
	(*obj)[1].color.g = 0;
	(*obj)[1].color.b = 0;
	(*obj)[0].specular = 500;
	(*obj)[0].name = CYLINDRE;
	(*obj)[0].radius = 1.0;
	(*obj)[0].pos.x = 1.0;
	(*obj)[0].pos.y = 0.0;
	(*obj)[0].pos.z = -2.0;
	(*obj)[0].n.x = 0.0;
	(*obj)[0].n.y = 1.0;
	(*obj)[0].n.z = 0.0;
	(*obj)[0].color.r = 0;
	(*obj)[0].color.g = 137;
	(*obj)[0].color.b = 5;
	(*obj)[0].specular = 500;
}

void	help2_init_scene_1(t_object **obj)
{
	(*obj)[3].name = PLANE;
	(*obj)[3].pos.x = 0.0;
	(*obj)[3].pos.y = 0.0;
	(*obj)[3].pos.z = 0.0;
	(*obj)[3].color.r = 0;
	(*obj)[3].color.g = 100;
	(*obj)[3].color.b = 200;
	(*obj)[3].n.x = 0.0;
	(*obj)[3].n.y = 0.0;
	(*obj)[3].n.z = 1.0;
	(*obj)[0].specular = 500;
	(*obj)[2].name = PLANE;
	(*obj)[2].pos.x = 0.0;
	(*obj)[2].pos.y = -1.0;
	(*obj)[2].pos.z = 0.0;
	(*obj)[2].color.r = 139;
	(*obj)[2].color.g = 139;
	(*obj)[2].color.b = 139;
	(*obj)[2].n.x = 0.0;
	(*obj)[2].n.y = 1.0;
	(*obj)[2].n.z = 0.0;
	(*obj)[0].specular = 500;
}
