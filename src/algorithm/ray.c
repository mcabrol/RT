/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/02 15:26:02 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_ray(t_vec o, t_vec d, int depth, t_ray *dest)
{
	dest->origin = o;
	dest->direction = d;
	dest->depth = depth;
}

void 	prepare_ray(t_render *render, t_radiance *target, t_scene *scene)
{
	double u1;
	double u2;
	double dx;
	double dy;

	u1 = 2.0 * erand48(render->xseed);
	u2 = 2.0 * erand48(render->xseed);
	dx = (u1 < 1.0f) ? sqrt(u1) - 1.0 : 1.0 - sqrt(2.0 - u1);
	dy = (u2 < 1.0f) ? sqrt(u2) - 1.0 : 1.0 - sqrt(2.0 - u2);
	nmulti(&scene->cam.cx, (((render->sx + 0.5 + dx) / 2.0 + render->x) / scene->width - 0.5), &target->a);
	nmulti(&scene->cam.cy, (((render->sy + 0.5 + dy) / 2.0 + render->y) / scene->height - 0.5), &target->b);
	sum(&target->a, &target->b, &target->ab);
	sum(&target->ab, &scene->cam.direction, &target->d);
	veccp(&scene->cam.position, &target->eye_t);
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
												r->origin.x,
												r->origin.y,
												r->origin.z,
												r->direction.x,
												r->direction.y,
												r->direction.z);
}

void	printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
