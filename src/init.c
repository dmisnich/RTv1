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

void	init_scene_1(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 2.0;
	sdl->camera.cam.z = -40.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_1;
	sdl->scene->max_obj = 5;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 6);
	help1_init_scene_1(&sdl->scene->obj);
	help2_init_scene_1(&sdl->scene->obj);
}

void	init_scene_2(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 10.0;
	sdl->camera.cam.z = -50.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_2;
	sdl->scene->max_obj = 5;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 5);

	sdl->scene->obj[0].name = CYLINDRE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = -5.0;
	sdl->scene->obj[0].n.x = 1.0;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 0;
	sdl->scene->obj[0].color.b = 255;
	sdl->scene->obj[0].specular = 500;

	sdl->scene->obj[1].name = CONE;
	sdl->scene->obj[1].tan = 0.5;
	sdl->scene->obj[1].pos.x = 0.0;
	sdl->scene->obj[1].pos.y = 0.0;
	sdl->scene->obj[1].pos.z = -5.0;
	sdl->scene->obj[1].n.x = 0.0;
	sdl->scene->obj[1].n.y = 1.0;
	sdl->scene->obj[1].n.z = 0.0;
	sdl->scene->obj[1].color.r = 255;
	sdl->scene->obj[1].color.g = 0;
	sdl->scene->obj[1].color.b = 255;
	sdl->scene->obj[1].specular = 500;

	sdl->scene->obj[2].name = PLANE;
	sdl->scene->obj[2].pos.x = 0.0;
	sdl->scene->obj[2].pos.y = 0.0;
	sdl->scene->obj[2].pos.z = 0.0;
	sdl->scene->obj[2].color.r = 139;
	sdl->scene->obj[2].color.g = 139;
	sdl->scene->obj[2].color.b = 139;
	sdl->scene->obj[2].n.x = 0.0;
	sdl->scene->obj[2].n.y = 1.0;
	sdl->scene->obj[2].n.z = 0.0;

	sdl->scene->obj[3].name = PLANE;
	sdl->scene->obj[3].pos.x = 0.0;
	sdl->scene->obj[3].pos.y = 0.0;
	sdl->scene->obj[3].pos.z = 0.0;
	sdl->scene->obj[3].color.r = 69;
	sdl->scene->obj[3].color.g = 200;
	sdl->scene->obj[3].color.b = 200;
	sdl->scene->obj[3].n.x = 0.0;
	sdl->scene->obj[3].n.y = 0.0;
	sdl->scene->obj[3].n.z = 1.0;
}

void	init_scene_3(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 0.0;
	sdl->camera.cam.z = -40.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_3;
	sdl->scene->max_obj = 1;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 1);
	sdl->scene->obj[0].name = CONE;
	sdl->scene->obj[0].tan = 0.3;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].n.x = 0.0;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 0;
	sdl->scene->obj[0].color.b = 255;
	sdl->scene->obj[0].specular = 500;
}

void	init_scene_4(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 0.0;
	sdl->camera.cam.z = -20.0;

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
	sdl->scene->obj[0].specular = 500;

	sdl->scene->obj[1].name = SPHERE;
	sdl->scene->obj[1].radius = 1.5 ;
	sdl->scene->obj[1].pos.x = 1.0;
	sdl->scene->obj[1].pos.y = 0.0;
	sdl->scene->obj[1].pos.z = 0.0;
	sdl->scene->obj[1].color.r = 178;
	sdl->scene->obj[1].color.g = 255;
	sdl->scene->obj[1].color.b = 56;
	sdl->scene->obj[1].specular = 500;
}


void	init_scene_5(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 0.0;
	sdl->camera.cam.z = -22.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_5;
	sdl->scene->max_obj = 5;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 5);
	sdl->scene->obj[0].name = SPHERE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = -4.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 90;
	sdl->scene->obj[0].color.b = 90;
	sdl->scene->obj[0].specular = 300;

	sdl->scene->obj[1].name = SPHERE;
	sdl->scene->obj[1].radius = 1.0;
	sdl->scene->obj[1].pos.x = -2.0;
	sdl->scene->obj[1].pos.y = 0.0;
	sdl->scene->obj[1].pos.z = 0.0;
	sdl->scene->obj[1].color.r = 200;
	sdl->scene->obj[1].color.g = 55;
	sdl->scene->obj[1].color.b = 255;
	sdl->scene->obj[1].specular = 300;

	sdl->scene->obj[2].name = SPHERE;
	sdl->scene->obj[2].radius = 1.0;
	sdl->scene->obj[2].pos.x = 0.0;
	sdl->scene->obj[2].pos.y = 0.0;
	sdl->scene->obj[2].pos.z = 0.0;
	sdl->scene->obj[2].color.r = 0;
	sdl->scene->obj[2].color.g = 34;
	sdl->scene->obj[2].color.b = 255;
	sdl->scene->obj[2].specular = 300;

	sdl->scene->obj[3].name = SPHERE;
	sdl->scene->obj[3].radius = 1.0;
	sdl->scene->obj[3].pos.x = 2.0;
	sdl->scene->obj[3].pos.y = 0.0;
	sdl->scene->obj[3].pos.z = 0.0;
	sdl->scene->obj[3].color.r = 145;
	sdl->scene->obj[3].color.g = 255;
	sdl->scene->obj[3].color.b = 0;
	sdl->scene->obj[3].specular = 300;

	sdl->scene->obj[4].name = SPHERE;
	sdl->scene->obj[4].radius = 1.0;
	sdl->scene->obj[4].pos.x = 4.0;
	sdl->scene->obj[4].pos.y = 0.0;
	sdl->scene->obj[4].pos.z = 0.0;
	sdl->scene->obj[4].color.r = 255;
	sdl->scene->obj[4].color.g = 130;
	sdl->scene->obj[4].color.b = 0;
	sdl->scene->obj[4].specular = 300;

}


void	init_light(t_sdl *sdl)
{
	sdl->light = (t_light *)malloc(sizeof(t_light) * 3);

	sdl->light[0].type = AMBIENT;
	sdl->light[0].intensity = 0.2;

	sdl->light[1].type = POINT;
	sdl->light[1].intensity = 0.6;
	sdl->light[1].pos.x = -2.0;
	sdl->light[1].pos.y = 1.0;
	sdl->light[1].pos.z = -16.0;

}

void	init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error\n");
	sdl->win = SDL_CreateWindow("RTv1", 500, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	sdl->surface = SDL_GetWindowSurface(sdl->win);
	sdl->vp.w = 0.5;
	sdl->vp.h = 0.5;
	sdl->vp.dist = 0.5;
	sdl->done = 0;
}
