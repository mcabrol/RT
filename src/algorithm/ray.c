/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/10 18:27:08 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_ray(t_vec o, t_vec d, int depth, t_ray *dest)
{
	dest->origin = o;
	dest->direction = d;
	dest->depth = depth;
}

void		prepare_ray(t_render *render, t_radiance *target, t_scene *scene)
{
	double 	u1;
	double 	u2;
	double 	dx;
	double 	dy;

	u1 = 2.0 * erand48(render->xseed);
	u2 = 2.0 * erand48(render->xseed);
	dx = (u1 < 1.0f) ? sqrt(u1) - 1.0 : 1.0 - sqrt(2.0 - u1);
	dy = (u2 < 1.0f) ? sqrt(u2) - 1.0 : 1.0 - sqrt(2.0 - u2);
	nmulti(&scene->cam.cx, (render->sx + dx + render->x) / scene->width, &target->a);
	nmulti(&scene->cam.cy, (render->sy + dy + render->y) / scene->height, &target->b);
	sum(&target->a, &target->b, &target->ab);
	sum(&scene->cam.point, &target->ab, &target->direction);
	sub_(&target->direction, &scene->cam.position);
	veccp(&scene->cam.position, &target->origin);
	norm(&target->direction);
}

void		eval(t_ray *r, double t, t_vec *dest)
{
	t_vec dt;

	nmulti(&r->direction, t, &dt);
	sum(&r->origin, &dt, dest);
}

void		printr(t_ray *r)
{
	ft_printf("o: [%f %f %f]\nd: [%f %f %f]\n", r->origin.x,
												r->origin.y,
												r->origin.z,
												r->direction.x,
												r->direction.y,
												r->direction.z);
}

void		printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
