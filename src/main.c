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

int		main(int argc, char **argv)
{
	t_sdl	sdl;
	
	init_sdl(&sdl);
	init_camera(&sdl);
	init_figure(&sdl);
	init_light(&sdl);

	while (1)
	{
		if (!SDL_PollEvent(&sdl.event))
		{
			if (sdl.event.type == SDL_QUIT || (sdl.event.type == SDL_KEYDOWN && sdl.event.key.keysym.sym == SDLK_ESCAPE))
				break;
			draw(&sdl);
			SDL_UpdateWindowSurface(sdl.win);
		}
	}
	SDL_DestroyWindow(sdl.win);
    SDL_Quit();
}

// void	parse(char **av)
// {
	
// }

t_vector	change_coords(t_sdl *sdl, int x, int y)
{
	t_vector res;

	res.y = ((float)y) * sdl->vp.h / HEIGHT;
	res.x = ((float)x) * sdl->vp.w / WIDTH;
	res.z = 1.0;
	res = vector_norm(&res);
	return (res);
}

unsigned int		color(t_sdl *sdl, int i, float value)
{
	t_color			color;
	unsigned int	c;

	color.r = sdl->obj[i].color.r * value;
	color.g = sdl->obj[i].color.g * value;
	color.b = sdl->obj[i].color.b * value;
	c = (color.r << 16) + (color.g << 8) + color.b;
	return (c);
}
