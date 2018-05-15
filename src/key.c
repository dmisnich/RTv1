/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:29:36 by dmisnich          #+#    #+#             */
/*   Updated: 2018/05/15 13:29:38 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				key(t_sdl *sdl, const Uint8	*keykey)
{
	int				hook;

	hook = 0;
	if (sdl->event.type == SDL_QUIT || (sdl->event.type == SDL_KEYDOWN
		&& sdl->event.key.keysym.sym == SDLK_ESCAPE))
		sdl->done = 1;
		
	if (keykey[SDL_SCANCODE_UP])
	{
		hook = UP;
		cam_move(sdl, hook);
	}
	if (keykey[SDL_SCANCODE_DOWN])
	{
		hook = DOWN;
		cam_move(sdl, hook);
	}
	if (keykey[SDL_SCANCODE_RIGHT])
	{
		hook = RIGHT;
		cam_move(sdl, hook);
	}
	if (keykey[SDL_SCANCODE_LEFT])
	{
		hook = LEFT;
		cam_move(sdl, hook);
	}
	if (keykey[SDL_SCANCODE_R])
	{
		hook = PLUS;
		cam_move(sdl, hook);
	}
	if (keykey[SDL_SCANCODE_E])
	{
		hook = MINUS;
		cam_move(sdl, hook);
	}
}
