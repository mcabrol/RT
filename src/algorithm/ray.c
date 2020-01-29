/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:40:33 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_camera(t_render *render)
{
	t_vec	direction;
	double	half_width;
	double	half_height;
	double	aspect_ratio;
	t_vec	c1;
	t_vec	c2;
	t_vec	coef;
	t_vec	d1;
	t_vec	d2;
	t_vec	t;
	t_vec	v1;
	t_vec	v2;

	vec(0.0, 0.0, 800.0, &render->camera.position);
	vec(0.0, 0.0, -1.0, &render->camera.direction);
	norm(&render->camera.direction);

	half_width = tan(0.261799f);
	aspect_ratio = HEIGHT / WIDTH;
	half_height = aspect_ratio * half_width;
	vec(0.0, 0.0, 0.0, &render->cx);
	vec(0.0, 1.0, 0.0, &direction);
	cross(&render->camera.direction, &direction, &c1);
	cross(&render->cx, &render->camera.direction, &c2);
	render->cx = *norm(&c1);
	render->cy = *norm(&c2);
	minus_(&render->cy);

	sub(&render->camera.position, &render->camera.direction, &coef);
	nmulti(&render->cy, half_height, &d1);
	nmulti(&render->cx, half_width, &d2);
	sub(&coef, &d1, &t);
	sub(&t, &d2, &render->bottom_left);

	nmulti(&render->cx, 2 * half_width, &v1);
	nmulti(&render->cy, 2 * half_height, &v2);

	ndivide(&v1, WIDTH, &render->cx);
	ndivide(&v2, HEIGHT, &render->cy);
}

void 	prepare_ray(t_render *render, unsigned int seed)
{
	double d1;
	double d2;
	t_vec m1;
	t_vec m2;
	t_vec p1;
	t_vec p2;

	render->rand = 2 * rand_ri(&seed);
	render->dx = render->rand < 1 ? (sqrt(render->rand) - 1) : (1 - sqrt(2 - render->rand));
	render->rand = 2 * rand_ri(&seed);
	render->dy = render->rand < 1 ? (sqrt(render->rand) - 1) : (1 - sqrt(2 - render->rand));

	d1 = render->x + render->dx;
	d2 = render->y + render->dy;
	nmulti(&render->cx, d1, &m1);
	nmulti(&render->cy, d2, &m2);
	sum(&m1, &m2, &p1);
	sum(&render->bottom_left, &p1, &p2);
	sub(&p2, &render->camera.position, &render->ray[1]);
	norm(&render->ray[1]);
	render->ray[0] = render->camera.position;
}

void	printr(t_vec origin, t_vec direction)
{
	ft_printf("o: [%f %f %f]\nd: [%f %f %f]\n",
	origin.x, origin.y, origin.z, direction.x, direction.y, direction.z);
}

void	printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
