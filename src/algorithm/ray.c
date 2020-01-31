/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 17:50:19 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_camera(t_render *render)
{
	double 	fov;
	t_vec	c1;

	fov = 0.5135;
	vec(50, 52, 295.6, &render->camera.position);
	vec(0.0, -0.042612, -1.0, &render->camera.direction);
	norm(&render->camera.direction);
	vec(WIDTH * fov / HEIGHT, 0.0, 0.0, &render->cx);
	cross(&render->cx, &render->camera.direction, &c1);
	norm(&c1);
	nmulti(&c1, fov, &render->cy);
}

void 	prepare_ray(t_render *render)
{
	t_vec 	d;
	t_vec 	d130;
	t_vec	n;
	t_vec 	a;
	t_vec 	b;
	t_vec 	ab;

	render->rand = 2.0 * erand48(render->xseed);
	render->dx = render->rand < 1.0f ? (sqrt(render->rand) - 1.0) : (1.0 - sqrt(2.0 - render->rand));
	render->rand = 2.0 * erand48(render->xseed);
	render->dy = render->rand < 1.0f ? (sqrt(render->rand) - 1.0) : (1.0 - sqrt(2.0 - render->rand));

	nmulti(&render->cx, (((render->sx + 0.5 + render->dx) / 2.0 + render->x) / WIDTH - 0.5), &a);
	nmulti(&render->cy, (((render->sy + 0.5 + render->dy) / 2.0 + render->y) / HEIGHT - 0.5), &b);

	sum(&a, &b, &ab);
	sum(&ab, &render->camera.direction, &d);
	nmulti(&d, 130.0, &d130);
	sum(&render->camera.position, &d130, &n);
	norm(&d);

	render->ray[0] = n;
	render->ray[1] = d;
}

void	printr(t_vec origin, t_vec direction)
{
	ft_printf("o: [%+f %+f %+f]\nd: [%+f %+f %+f]\n",
	origin.x, origin.y, origin.z, direction.x, direction.y, direction.z);
}

void	printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
