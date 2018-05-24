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
	protect_obj(&sdl);
	protect_light(&sdl);
	keykey = SDL_GetKeyboardState(NULL);
	raycaster(&sdl);
	SDL_UpdateWindowSurface(sdl.win);
	while (!sdl.done)
	{
		SDL_PollEvent(&sdl.event);
		key_1(&sdl, keykey);
		key_2(&sdl, keykey);
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
	else if (!(ft_strcmp(av, "scene_6")))
		init_scene_6(sdl);
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
