/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:49:20 by dmisnich          #+#    #+#             */
/*   Updated: 2018/03/28 11:49:23 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIDTH		900
# define HEIGHT		900
# define AMBIENT	1
# define POINT		10
# define DIR		3

// # define RDIST		sdl->plane[0].dist

# define SPHERE		1
# define PLANE		2
# define CYLINDRE   3
# define CONE		4


# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../Frameworks/SDL2.framework/Headers/SDL.h"



typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_discrim
{
	float		x1;
	float		x2;
}				t_discrim;

typedef	struct s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct s_light
{
	int			type;
	float		intensity;
	t_vector	pos;
	t_vector	dir;
}				t_light;

typedef struct s_viewport
{
	float		h;
	float		w;
	float		dist;	
}				t_viewport;

typedef struct	s_cylindre
{
	float		radius;
	t_vector	pos;
	t_color		color;
}				t_cylindre;


typedef	struct	s_cam
{
	t_vector	cam;
}				t_cam;

typedef	struct	s_ray
{
	t_vector	dir;
}				t_ray;

typedef	struct	s_object
{
	float		radius;
	float		tan;
	int			name;
	t_color		color;
	t_vector	pos;
	t_vector	n;
}				t_object;

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*surface;
	SDL_Event		event;
	unsigned int	*buff;
	t_viewport		vp;
	t_ray			ray;
	t_cam			camera;
	t_object		*obj;
	t_cylindre		*cylindre;
	t_light			*light;
	float			closest_sphere;
	float			dist;

}				t_sdl;

void				init_camera(t_sdl *sdl);
void				init_sdl(t_sdl *sdl);
void				init_sphare(t_sdl *sdl);
void				init_plane(t_sdl *sdl);
void				init_cylindre(t_sdl *sdl);
void				init_figure(t_sdl *sdl);
void				draw(t_sdl *sdl);
t_vector			change_coords(t_sdl *sdl, int x, int y);

int					parse_obj(t_sdl *sdl);

int					ray_tracer_obj( t_sdl *sdl);
int					ray_tracer_cy(t_vector *org, t_vector *direction, float min, float max, t_sdl *sdl);

t_discrim			find_sphere(t_object *obj, t_sdl *sdl);
t_discrim			find_cylindre(t_object *obj, t_sdl *sdl);
t_discrim			find_cone(t_object *obj, t_sdl *sdl);
t_discrim			find_plane(t_object *obj, t_sdl *sdl);

t_vector			vector_sub(t_vector *v1, t_vector *v2);
t_vector			vector_add(t_vector *v1, t_vector *v2);
t_vector			vector_mult(t_vector *v1, t_vector *v2);
t_vector			vector_mult_scal(t_vector *v, float value);
t_vector			vector_div(t_vector *v, float value);
t_vector			vector_norm(t_vector *v);

float				vector_dot(t_vector *v1, t_vector *v2);
float				vector_len(t_vector *v);

unsigned int		color(t_sdl *sdl, int i, float value);
unsigned int		color_p(t_sdl *sdl);
float				findelight(t_vector *p, t_vector *norm, t_sdl *sdl);
void				init_light(t_sdl *sdl);

t_discrim	find_solve_discrim(float a, float b, float c);

#endif

