/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 14:56:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ray(t_vec o, t_vec d, double tmin, double tmax, int depth, t_ray *dest)
{
	dest->o = o;
	dest->d = d;
	dest->tmin = tmin;
	dest->tmax = tmax;
	dest->depth = depth;
}

void 	prepare_ray(t_rtv1 *rtv1, t_target *target)
{
	double u1;
	double u2;
	double dx;
	double dy;

	u1 = 2.0 * erand48(rtv1->rt.xseed);
	u2 = 2.0 * erand48(rtv1->rt.xseed);
	dx = (u1 < 1.0f) ? sqrt(u1) - 1.0 : 1.0 - sqrt(2.0 - u1);
	dy = (u2 < 1.0f) ? sqrt(u2) - 1.0 : 1.0 - sqrt(2.0 - u2);
	nmulti(&rtv1->camera.cx, (((rtv1->rt.sx + 0.5 + dx) / 2.0 + rtv1->rt.x) / WIDTH - 0.5), &target->a);
	nmulti(&rtv1->camera.cy, (((rtv1->rt.sy + 0.5 + dy) / 2.0 + rtv1->rt.y) / HEIGHT - 0.5), &target->b);
	sum(&target->a, &target->b, &target->ab);
	sum(&target->ab, &rtv1->camera.gaze, &target->d);
	nmulti(&target->d, 130.0, &target->d_t);
	sum(&rtv1->camera.eye, &target->d_t, &target->eye_t);
}

void	init_cam(t_rtv1 *rtv1)
{
	vec(50, 52, 295.6, &rtv1->camera.eye);
	vec(0, -0.042612, -1, &rtv1->camera.gaze);
	norm(&rtv1->camera.gaze);
	rtv1->camera.fov = 0.5135;
	vec(WIDTH * rtv1->camera.fov / HEIGHT, 0.0, 0.0, &rtv1->camera.cx);
	cross(&rtv1->camera.cx, &rtv1->camera.gaze, &rtv1->camera.cy);
	norm(&rtv1->camera.cy);
	nmulti_(&rtv1->camera.cy, rtv1->camera.fov);
}

void	eval(t_ray *r, double t, t_vec *dest)
{
	t_vec dt;

	nmulti(&r->d, t, &dt);
	sum(&r->o, &dt, dest);
}

void	printr(t_ray *r)
{
	ft_printf("o: [%f %f %f]\nd: [%f %f %f]\n",
	r->o.x, r->o.y, r->o.z, r->d.x, r->d.y, r->d.z);
}

void	printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
