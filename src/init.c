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
	sdl->camera.cam.x = 0.5;
	sdl->camera.cam.y = 2.5;
	sdl->camera.cam.z = -50.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_1;
	sdl->scene->max_obj = 4;
	sdl->max.max_spot = 3;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 6);
	help1_init_scene_1(&sdl->scene->obj);
	help2_init_scene_1(&sdl->scene->obj);
}

void	init_scene_2(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 1.0;
	sdl->camera.cam.z = -15.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_2;
	sdl->scene->max_obj = 1;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 2);

	sdl->scene->obj[0].name = CYLINDRE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].n.x = 0.0;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 0;
	sdl->scene->obj[0].color.b = 255;
	sdl->scene->obj[0].specular = 100;
}

void	init_scene_3(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 4.0;
	sdl->camera.cam.z = -40.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_3;
	sdl->scene->max_obj = 2;
	sdl->max.max_spot = 3;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 2);
	help1_init_scene_3(&sdl->scene->obj);
}

void	init_scene_4(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 1.0;
	sdl->camera.cam.z = -40.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_4;
	sdl->scene->max_obj = 4;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 4);
	help1_init_scene_4(&sdl->scene->obj);
	help2_init_scene_4(&sdl->scene->obj);
}

void	init_scene_5(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 1.0;
	sdl->camera.cam.z = -20.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_5;
	sdl->scene->max_obj = 5;
	sdl->max.max_spot = 2;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 5);
	sdl->scene->obj[0].name = SPHERE;
	sdl->scene->obj[0].radius = 1.0;
	sdl->scene->obj[0].pos.x = -4.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].color.r = 255;
	sdl->scene->obj[0].color.g = 90;
	sdl->scene->obj[0].color.b = 90;
	sdl->scene->obj[0].specular = 100;

	sdl->scene->obj[1].name = SPHERE;
	sdl->scene->obj[1].radius = 1.0;
	sdl->scene->obj[1].pos.x = -2.0;
	sdl->scene->obj[1].pos.y = 0.0;
	sdl->scene->obj[1].pos.z = 0.0;
	sdl->scene->obj[1].color.r = 200;
	sdl->scene->obj[1].color.g = 55;
	sdl->scene->obj[1].color.b = 255;
	sdl->scene->obj[1].specular = 100;

	sdl->scene->obj[2].name = SPHERE;
	sdl->scene->obj[2].radius = 1.0;
	sdl->scene->obj[2].pos.x = 0.0;
	sdl->scene->obj[2].pos.y = 0.0;
	sdl->scene->obj[2].pos.z = 0.0;
	sdl->scene->obj[2].color.r = 0;
	sdl->scene->obj[2].color.g = 34;
	sdl->scene->obj[2].color.b = 255;
	sdl->scene->obj[2].specular = 100;

	sdl->scene->obj[3].name = SPHERE;
	sdl->scene->obj[3].radius = 1.0;
	sdl->scene->obj[3].pos.x = 2.0;
	sdl->scene->obj[3].pos.y = 0.0;
	sdl->scene->obj[3].pos.z = 0.0;
	sdl->scene->obj[3].color.r = 145;
	sdl->scene->obj[3].color.g = 255;
	sdl->scene->obj[3].color.b = 0;
	sdl->scene->obj[3].specular = 100;

	sdl->scene->obj[4].name = SPHERE;
	sdl->scene->obj[4].radius = 1.0;
	sdl->scene->obj[4].pos.x = 4.0;
	sdl->scene->obj[4].pos.y = 0.0;
	sdl->scene->obj[4].pos.z = 0.0;
	sdl->scene->obj[4].color.r = 255;
	sdl->scene->obj[4].color.g = 130;
	sdl->scene->obj[4].color.b = 0;
	sdl->scene->obj[4].specular = 100;

}

void	init_scene_6(t_sdl *sdl)
{
	sdl->camera.cam.x = 0.0;
	sdl->camera.cam.y = 4.0;
	sdl->camera.cam.z = -45.0;

	sdl->scene = (t_scene *)malloc(sizeof(t_scene));
	sdl->scene->name = SCENE_4;
	sdl->scene->max_obj = 16;
	sdl->max.max_spot = 3;
	sdl->scene->obj = (t_object *)malloc(sizeof(t_object) * 16);

	sdl->scene->obj[0].name = PLANE;
	sdl->scene->obj[0].pos.x = 0.0;
	sdl->scene->obj[0].pos.y = 0.0;
	sdl->scene->obj[0].pos.z = 0.0;
	sdl->scene->obj[0].color.r = 92;
	sdl->scene->obj[0].color.g = 92;
	sdl->scene->obj[0].color.b = 92;
	sdl->scene->obj[0].n.x = 0.0;
	sdl->scene->obj[0].n.y = 1.0;
	sdl->scene->obj[0].n.z = 0.0;

	sdl->scene->obj[1].name = PLANE;
	sdl->scene->obj[1].pos.x = 0.0;
	sdl->scene->obj[1].pos.y = 8.0;
	sdl->scene->obj[1].pos.z = 0.0;
	sdl->scene->obj[1].color.r = 92;
	sdl->scene->obj[1].color.g = 92;
	sdl->scene->obj[1].color.b = 92;
	sdl->scene->obj[1].n.x = 0.0;
	sdl->scene->obj[1].n.y = -1.0;
	sdl->scene->obj[1].n.z = 0.0;

	sdl->scene->obj[2].name = PLANE;
	sdl->scene->obj[2].pos.x = 0.0;
	sdl->scene->obj[2].pos.y = 0.0;
	sdl->scene->obj[2].pos.z = 20.0;
	sdl->scene->obj[2].color.r = 0;
	sdl->scene->obj[2].color.g = 110;
	sdl->scene->obj[2].color.b = 200;
	sdl->scene->obj[2].n.x = 0.0;
	sdl->scene->obj[2].n.y = 0.0;
	sdl->scene->obj[2].n.z = 1.0;

	sdl->scene->obj[3].name = SPHERE;
	sdl->scene->obj[3].radius = 1.0;
	sdl->scene->obj[3].pos.x = 0.0;
	sdl->scene->obj[3].pos.y = 2.0;
	sdl->scene->obj[3].pos.z = -10.0;
	sdl->scene->obj[3].color.r = 255;
	sdl->scene->obj[3].color.g = 130;
	sdl->scene->obj[3].color.b = 0;
	sdl->scene->obj[3].specular = 100;

	sdl->scene->obj[4].name = CYLINDRE;
	sdl->scene->obj[4].radius = 1.0;
	sdl->scene->obj[4].pos.x = -5.0;
	sdl->scene->obj[4].pos.y = 0.0;
	sdl->scene->obj[4].pos.z = 10.0;
	sdl->scene->obj[4].n.x = 0.0;
	sdl->scene->obj[4].n.y = 1.0;
	sdl->scene->obj[4].n.z = 0.0;
	sdl->scene->obj[4].color.r = 0;
	sdl->scene->obj[4].color.g = 230;
	sdl->scene->obj[4].color.b = 255;
	sdl->scene->obj[4].specular = 100;

	sdl->scene->obj[5].name = CYLINDRE;
	sdl->scene->obj[5].radius = 1.0;
	sdl->scene->obj[5].pos.x = 5.0;
	sdl->scene->obj[5].pos.y = 0.0;
	sdl->scene->obj[5].pos.z = 10.0;
	sdl->scene->obj[5].n.x = 0.0;
	sdl->scene->obj[5].n.y = 1.0;
	sdl->scene->obj[5].n.z = 0.0;
	sdl->scene->obj[5].color.r = 0;
	sdl->scene->obj[5].color.g = 230;
	sdl->scene->obj[5].color.b = 255;
	sdl->scene->obj[5].specular = 100;

	sdl->scene->obj[6].name = CYLINDRE;
	sdl->scene->obj[6].radius = 1.0;
	sdl->scene->obj[6].pos.x = -5.0;
	sdl->scene->obj[6].pos.y = 0.0;
	sdl->scene->obj[6].pos.z = -15.0;
	sdl->scene->obj[6].n.x = 0.0;
	sdl->scene->obj[6].n.y = 1.0;
	sdl->scene->obj[6].n.z = 0.0;
	sdl->scene->obj[6].color.r = 0;
	sdl->scene->obj[6].color.g = 230;
	sdl->scene->obj[6].color.b = 255;
	sdl->scene->obj[6].specular = 100;

	sdl->scene->obj[7].name = CYLINDRE;
	sdl->scene->obj[7].radius = 1.0;
	sdl->scene->obj[7].pos.x = 5.0;
	sdl->scene->obj[7].pos.y = 0.0;
	sdl->scene->obj[7].pos.z = -15.0;
	sdl->scene->obj[7].n.x = 0.0;
	sdl->scene->obj[7].n.y = 1.0;
	sdl->scene->obj[7].n.z = 0.0;
	sdl->scene->obj[7].color.r = 0;
	sdl->scene->obj[7].color.g = 230;
	sdl->scene->obj[7].color.b = 255;
	sdl->scene->obj[7].specular = 100;
	scene_6_sphere1_up1(&sdl->scene->obj);
	scene_6_sphere1_down1(&sdl->scene->obj);
	scene_6_sphere1_up2(&sdl->scene->obj);
	scene_6_sphere1_down2(&sdl->scene->obj);
	
}

void	init_light(t_sdl *sdl)
{
	sdl->light = (t_light *)malloc(sizeof(t_light) * 5);

	sdl->light[0].type = AMBIENT;
	sdl->light[0].intensity = 0.2;

	sdl->light[1].type = POINT;
	sdl->light[1].intensity = 0.4;
	sdl->light[1].pos.x = -10.0;
	sdl->light[1].pos.y = 4.0;
	sdl->light[1].pos.z = -26.0;

	sdl->light[2].type = POINT;
	sdl->light[2].intensity = 0.4;
	sdl->light[2].pos.x = 10.0;
	sdl->light[2].pos.y = 4.0;
	sdl->light[2].pos.z = -26.0;

	sdl->light[3].type = POINT;
	sdl->light[3].intensity = 0.3;
	sdl->light[3].pos.x = -7.0;
	sdl->light[3].pos.y = 2.0;
	sdl->light[3].pos.z = -55.0;

	sdl->light[4].type = POINT;
	sdl->light[4].intensity = 0.3;
	sdl->light[4].pos.x = 7.0;
	sdl->light[4].pos.y = 2.0;
	sdl->light[4].pos.z = -25.0;
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
