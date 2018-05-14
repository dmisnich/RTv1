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

	if (argc != 2)
	{
		printf("error\n");
		return (0);
	}
	init_sdl(&sdl);
	if (!(parser_av(&sdl, argv[1])))
		return (0);
	init_light(&sdl);
	raycaster(&sdl);
	SDL_UpdateWindowSurface(sdl.win);
	while (1)
	{
		if (!SDL_PollEvent(&sdl.event))
		{
			if (sdl.event.type == SDL_QUIT || (sdl.event.type == SDL_KEYDOWN
				&& sdl.event.key.keysym.sym == SDLK_ESCAPE))
				break ;
		}
	}
	SDL_DestroyWindow(sdl.win);
	SDL_Quit();
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
		printf("forbidden name\n");
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
