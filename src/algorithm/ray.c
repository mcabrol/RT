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

void		init_ray(t_vec o, t_vec d, t_ray *dest)
{
	dest->origin = o;
	dest->direction = d;
	dest->depth = 0;
}

void		prepare_ray(t_render *render, t_radiance *target, t_scene *scene)
{
	double	u1;
	double	u2;
	double	dx;
	double	dy;

	u1 = 2.0 * erand48(render->xseed);
	u2 = 2.0 * erand48(render->xseed);
	dx = (u1 < 1.0) ? (sqrt(u1) - 1.0) : (1.0 - sqrt(2.0 - u1));
	dy = (u2 < 1.0) ? (sqrt(u2) - 1.0) : (1.0 - sqrt(2.0 - u2));
	nmulti(&scene->cam.cx, (dx + (double)render->x), &target->a);
	nmulti(&scene->cam.cy, (dy + (double)render->y), &target->b);
	sum(&target->a, &target->b, &target->ab);
	sum(&scene->cam.point, &target->ab, &target->direction);
	sub_(&target->direction, &scene->cam.position);
	veccp(&scene->cam.position, &target->origin);
	norm(&target->direction);
}

void		eval(t_ray *r, double distance, t_vec *dest)
{
	nmulti(&r->direction, distance, dest);
	sum_(dest, &r->origin);
}
