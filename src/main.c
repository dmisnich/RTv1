/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:53:05 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/28 11:53:06 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					main(int argc, char **argv)
{
	t_sdl			sdl;
	const Uint8		*keykey;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (!(parser_av(&sdl, argv[1])))
		return (0);
	init_sdl(&sdl);
	init_light(&sdl);
	keykey = SDL_GetKeyboardState(NULL);
	raycaster(&sdl);
	SDL_UpdateWindowSurface(sdl.win);
	while (!sdl.done)
	{
		// raycaster(&sdl);
		// SDL_UpdateWindowSurface(sdl.win);
		SDL_PollEvent(&sdl.event);
		key(&sdl, keykey);
	}
	SDL_DestroyWindow(sdl.win);
	SDL_Quit();
}

void				cam_move(t_sdl *sdl, int hook)
{
	if (hook == UP)
		sdl->camera.cam.y = sdl->camera.cam.y + 0.5;
	if (hook == DOWN)
		sdl->camera.cam.y = sdl->camera.cam.y - 0.5;
	if (hook == LEFT)
		sdl->camera.cam.x = sdl->camera.cam.x - 0.5;
	if (hook == RIGHT)
		sdl->camera.cam.x = sdl->camera.cam.x + 0.5;
	if (hook == PLUS)
		sdl->camera.cam.z = sdl->camera.cam.z + 0.5;
	if (hook == MINUS)
		sdl->camera.cam.z = sdl->camera.cam.z - 0.5;
}

int					parser_av(t_sdl *sdl, char *av)
{
	if (!(ft_strcmp(av, "scene_1")))
		init_scene_1(sdl);
	else if (!(ft_strcmp(av, "scene_2")))
		init_scene_2(sdl);
	else if (!(ft_strcmp(av, "scene_3")))
		init_scene_3(sdl);
	else if (!(ft_strcmp(av, "scene_4")))
		init_scene_4(sdl);
	else if (!(ft_strcmp(av, "scene_5")))
		init_scene_5(sdl);
	else
	{
		ft_putstr("forbidden name\n");
		return (0);
	}
	return (1);
}

t_vector			find_ray_diraction(t_sdl *sdl, int x, int y)
{
	t_vector		res;

	res.y = ((float)y) * sdl->vp.h / HEIGHT;
	res.x = ((float)x) * sdl->vp.w / WIDTH;
	res.z = 1.0;
	res = vector_norm(&res);
	return (res);
}

unsigned int		color_test(t_color *color_obj, float value)
{
	t_color			color;
	unsigned int	c;

	color.r = color_obj->r * value;
	color.g = color_obj->g * value;
	color.b = color_obj->b * value;
	if (color.r > 255)
		color.r = 255;
	if (color.g > 255)
		color.g = 255;
	if (color.b > 255)
		color.b = 255;
	c = (color.r << 16) + (color.g << 8) + color.b;
	return (c);
}

unsigned int		color(t_sdl *sdl, int i, float value)
{
	t_color			color;
	unsigned int	c;

	color.r = sdl->scene->obj[i].color.r * value;
	color.g = sdl->scene->obj[i].color.g * value;
	color.b = sdl->scene->obj[i].color.b * value;
	c = (color.r << 16) + (color.g << 8) + color.b;
	return (c);
}
