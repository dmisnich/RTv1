/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:52:36 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/03 12:52:38 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void	init_camera(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 1.0;
	sdl->camera.cam.z = -3.0;
}

void	init_figure(t_sdl *sdl)
{
	sdl->obj = (t_object *)malloc(sizeof(t_object) * 5);
	sdl->obj[0].name = SPHERE;
	sdl->obj[0].radius = 1;
	sdl->obj[0].pos.x = 0.0;
	sdl->obj[0].pos.y = 2.0;
	sdl->obj[0].pos.z = 10.0;
	sdl->obj[0].color.r = 255;
	sdl->obj[0].color.g = 0;
	sdl->obj[0].color.b = 0;

	sdl->obj[1].name = SPHERE;
	sdl->obj[1].radius = 1;
	sdl->obj[1].pos.x = 0.0;
	sdl->obj[1].pos.y = 0.0;
	sdl->obj[1].pos.z = 10.0;
	sdl->obj[1].color.r = 255;
	sdl->obj[1].color.g = 255;
	sdl->obj[1].color.b = 0;

	sdl->obj[2].name = SPHERE;
	sdl->obj[2].radius = 1;
	sdl->obj[2].pos.x = 0.0;
	sdl->obj[2].pos.y = -2.0;
	sdl->obj[2].pos.z = 10.0;
	sdl->obj[2].color.r = 0;
	sdl->obj[2].color.g = 255;
	sdl->obj[2].color.b = 0;

	sdl->obj[3].name = PLANE;
	sdl->obj[3].pos.x = 0.0;
	sdl->obj[3].pos.y = -1.0;
	sdl->obj[3].pos.z = 10.0;
	sdl->obj[3].color.r = 139;
	sdl->obj[3].color.g = 139;
	sdl->obj[3].color.b = 139;

	sdl->obj[4].name = CYLINDRE;
	sdl->obj[4].radius = 1;
	sdl->obj[4].pos.x = 0.0;
	sdl->obj[4].pos.y = 0.0;
	sdl->obj[4].pos.z = 7.0;
	sdl->obj[4].color.r = 0;
	sdl->obj[4].color.g = 255;
	sdl->obj[4].color.b = 0;
}

void	init_light(t_sdl *sdl)
{
	sdl->light = (t_light *)malloc(sizeof(t_light) * 3);

	sdl->light[0].type = AMBIENT;
	sdl->light[0].intensity = 0.7;

	// sdl->light[1].type = POINT;
	// sdl->light[1].intensity = 0.9;
	// sdl->light[1].pos.x = 0.0;
	// sdl->light[1].pos.y = 1.0;
	// sdl->light[1].pos.z = -25.0;

	sdl->light[1].type = DIR;
	sdl->light[1].intensity = 0.0;
	sdl->light[1].pos.x = 0.0;
	sdl->light[1].pos.y = 0.0;
	sdl->light[1].pos.z = 25.0;
}

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error\n");
	sdl->win = SDL_CreateWindow("RTv1", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	sdl->surface = SDL_GetWindowSurface(sdl->win);
	sdl->vp.w = 1.0;
	sdl->vp.h = 1.0;
	sdl->vp.dist = 1.0;
}
