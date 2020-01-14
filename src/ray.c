/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	ray(t_vec o, t_vec d, double tmin, double tmax, int depth)
{
	t_ray ray;

	ray.o = o;
	ray.d = d;
	ray.tmin = tmin;
	ray.tmax = tmax;
	ray.depth = depth;
	return (ray);
}

void	init_cam(t_cam *cam)
{
	vec(50, 52, 295.6, &cam->eye);
	vec(0, -0.042612, -1, &cam->gaze);
	norm(&cam->gaze);
	cam->fov = 0.5135;
	vec(WIDTH * cam->fov / HEIGHT, 0.0, 0.0, &cam->cx);
	cross(&cam->cx, &cam->gaze, &cam->cy);
	norm(&cam->cy);
	nmulti_(&cam->cy, cam->fov);
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
