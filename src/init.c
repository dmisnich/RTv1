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
	sdl->camera.cam.y = 0.0;
	sdl->camera.cam.z = -20.0;
}

void	init_scene_1(t_sdl *sdl)
{
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));

	sdl->scene->name = SCENE_1;
	sdl->scene->max_obj = 4;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 5);
	help1_init_scene_1(&sdl->scene->obj);
	help2_init_scene_1(&sdl->scene->obj);
}

void	init_scene_2(t_sdl *sdl)
{
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_2;
	sdl->scene->max_obj = 1;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 1);
	sdl->scene->obj[0].name = SPHERE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = -10.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 0;
	sdl->scene->obj[0].color.b = 0;
}

void	init_scene_3(t_sdl *sdl)
{
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_3;
	sdl->scene->max_obj = 1;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 1);
	sdl->scene->obj[0].name = CONE;
	sdl->scene->obj[0].tan = 0.3;
	sdl->scene->obj[0].pos.x = -1.0;
	sdl->scene->obj[0].pos.y = 1.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].n.x = -0.2;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 0;
	sdl->scene->obj[0].color.b = 255;
}

void	init_scene_4(t_sdl *sdl)
{
	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_4;
	sdl->scene->max_obj = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 2);
	sdl->scene->obj[0].name = CYLINDRE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].n.x = 0.0;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;
	sdl->scene->obj[0].color.r = 0;
	sdl->scene->obj[0].color.g = 137;
	sdl->scene->obj[0].color.b = 5;
}

void	init_light(t_sdl *sdl)
{
	sdl->light = (t_light *)malloc(sizeof(t_light) * 3);

	sdl->light[0].type = AMBIENT;
	sdl->light[0].intensity = 0.3;

	// sdl->light[1].type = POINT;
	// sdl->light[1].intensity = 0.9;
	// sdl->light[1].pos.x = 1.0;
	// sdl->light[1].pos.y = 0.0;
	// sdl->light[1].pos.z = 0.0;

	sdl->light[1].type = DIR;
	sdl->light[1].intensity = 0.6;
	sdl->light[1].pos.x = 20.0;
	sdl->light[1].pos.y = 0.0;
	sdl->light[1].pos.z = 1.0;
}

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error\n");
	sdl->win = SDL_CreateWindow("RTv1", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	sdl->surface = SDL_GetWindowSurface(sdl->win);
	sdl->vp.w = 0.5;
	sdl->vp.h = 0.5;
	sdl->vp.dist = 0.5;
}
