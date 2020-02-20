/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:03:21 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_ray(t_vec o, t_vec d, int depth, t_ray *dest)
{
	dest->origin = o;
	dest->direction = d;
	dest->depth = depth;
}

void 	prepare_ray(t_render *rt, t_radiance *target, t_cam *cam)
{
	double u1;
	double u2;
	double dx;
	double dy;

	u1 = 2.0 * erand48(rt->xseed);
	u2 = 2.0 * erand48(rt->xseed);
	dx = (u1 < 1.0f) ? sqrt(u1) - 1.0 : 1.0 - sqrt(2.0 - u1);
	dy = (u2 < 1.0f) ? sqrt(u2) - 1.0 : 1.0 - sqrt(2.0 - u2);
	nmulti(&cam->cx, (((rt->sx + 0.5 + dx) / 2.0 + rt->x) / WIDTH - 0.5), &target->a);
	nmulti(&cam->cy, (((rt->sy + 0.5 + dy) / 2.0 + rt->y) / HEIGHT - 0.5), &target->b);
	sum(&target->a, &target->b, &target->ab);
	sum(&target->ab, &cam->gaze, &target->d);
	// nmulti(&target->d, 130.0, &target->d_t);
	veccp(&cam->eye, &target->eye_t);
	// sum(&cam->eye, &target->d, &target->eye_t);
}

void	init_cam(t_cam *cam)
{
	vec(0, 0, 0, &cam->eye);
	vec(0, 0, -1, &cam->gaze);
	norm(&cam->gaze);
	cam->fov = 30 * M_PI / 180;
	vec(WIDTH * cam->fov / HEIGHT, 0.0, 0.0, &cam->cx);
	cross(&cam->cx, &cam->gaze, &cam->cy);
	norm(&cam->cy);
	nmulti_(&cam->cy, cam->fov);
}

void	eval(t_ray *r, double t, t_vec *dest)
{
	t_vec dt;

	nmulti(&r->direction, t, &dt);
	sum(&r->origin, &dt, dest);
}

void	printr(t_ray *r)
{
	ft_printf("o: [%f %f %f]\nd: [%f %f %f]\n",
	r->origin.x, r->origin.y, r->origin.z, r->direction.x, r->direction.y, r->direction.z);
}

void	printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
