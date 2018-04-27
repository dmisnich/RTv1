/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 13:17:15 by dmisnich          #+#    #+#             */
/*   Updated: 2018/04/12 13:17:16 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_discrim	find_cylindre(t_object *obj, t_sdl *sdl)
{
	t_discrim	tsp;
	t_vector	oc;
	float		param[3];

	obj->n = vector_norm(&obj->n);
	// printf("n_x: %f\n", obj->n.x);
	// printf("n_y: %f\n", obj->n.y);
	// printf("n_z: %f\n", obj->n.z);

	// printf("n_x: %f\n", obj->pos.x);
	// printf("n_y: %f\n", obj->pos.y);
	// printf("n_z: %f\n", obj->pos.z);
	sdl->ray.dir = vector_norm(&sdl->ray.dir);
	oc = vector_sub(&sdl->camera.cam, &obj->pos);
	param[0] = vector_dot(&sdl->ray.dir, &sdl->ray.dir) - pow(vector_dot(&sdl->ray.dir, &obj->n), 2);
	param[1] = 2.0 * vector_dot(&sdl->ray.dir, &oc) - vector_dot(&sdl->ray.dir, &obj->n) * vector_dot(&oc, &obj->n);
	param[2] = vector_dot(&oc, &oc) - pow(vector_dot(&oc, &obj->n), 2) - pow(obj->radius, 2);
	printf("n_a: %f\n", param[0]);
	printf("n_b: %f\n", param[1]);
	printf("n_c: %f\n", param[2]);
	tsp = find_solve_discrim(param[0], param[1], param[2]);
	return (tsp);
}

t_discrim	find_solve_discrim(float a, float b, float c)
{
	t_discrim	tsp;
	float discrim;

	discrim = (b * b) - (4 * a * c);
	if (discrim < 0 && discrim > -0.0001)
		discrim = 0;
	// if (discrim == 0)
	// {
	// 	tsp.x1 = -0.5 * b / a;
	// 	tsp.x2 = 0;
	// }
	if (discrim < 0)
		return ((t_discrim){-1, -1});
	tsp.x1 = (-b + sqrtf(discrim) / 2.0 * a);
	tsp.x2 = (-b - sqrtf(discrim) / 2.0 * a);
	// printf("x1: %f\n", tsp.x1);
	// printf("x2: %f\n", tsp.x2);
	return (tsp);
}

// t_discrim	find_cylindre(t_object *obj, t_sdl *sdl)
// {
// 	t_discrim	tsp;
// 	t_vector	oc;
// 	float		discrim;
// 	float		a;
// 	float		b;
// 	float		c;

// 	// printf("x: %f\n", sdl->obj->pos.x);
// 	// printf("y: %f\n", sdl->obj->pos.y);
// 	// printf("z: %f\n", sdl->obj->pos.z);
// 	obj->n = vector_norm(&obj->n);
// 	sdl->ray.dir = vector_norm(&sdl->ray.dir);
// 	oc = vector_sub(&sdl->camera.cam, &obj->pos);
// 	a = vector_dot(&sdl->ray.dir, &sdl->ray.dir) - (vector_dot(&sdl->ray.dir, &obj->n)) * (vector_dot(&sdl->ray.dir, &obj->n));
// 	b = 2.0 * vector_dot(&oc, &sdl->ray.dir) - (vector_dot(&sdl->ray.dir, &obj->n)) * (vector_dot(&oc, &obj->n));
// 	c = vector_dot(&oc, &oc) - (vector_dot(&oc, &obj->n) * vector_dot(&oc, &obj->n)) - obj->radius * obj->radius;
// 	discrim = b * b - (4 * a * c);
// 	if (discrim < 0 && discrim > -0.0001)
// 		discrim = 0;
// 	if (discrim < 0)
// 		return((t_discrim){-1, -1});
// 	tsp.x1 = (-b + sqrt(discrim) / (2.0 * a));
// 	tsp.x2 = (-b - sqrt(discrim) / (2.0 * a));
// 	// printf("x1: %f\n", tsp.x1);
// 	// printf("x2: %f\n", tsp.x2);
// 	return (tsp);
// }



	// v3 = vector_sub(&sdl->camera.cam, &obj->pos);
	// tmp = vector_dot(&v3, &obj->n);
	// ttt = vector_mult_scal(&obj->n, tmp);
	// v2 = vector_sub(&v3, &ttt);
	// tmp2 = vector_dot(&sdl->ray.dir, &obj->n);
	// ttt2 = vector_mult_scal(&obj->n, tmp2);
	// v1 = vector_sub(&v3, &ttt2);
	// param[0] = vector_dot(&v1, &v1);
	// param[1] = 2 * vector_dot(&v1, &v2);
	// param[2] = vector_dot(&v2, &v2) - pow(obj->radius, 2);





