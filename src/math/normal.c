/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 17:14:08 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	normal(t_ray *ray, t_obj *shape)
{
	if (shape->type == SPHERE)
		sphere_normal(shape, ray);
	else if (shape->type == PLANE)
		plane_normal(shape, ray);
	else if (shape->type == CYLINDER)
		cylinder_normal(shape, ray);
	else if (shape->type == CONE)
		cone_normal(shape, ray);
	else if (shape->type == BOX)
		box_normal(shape, ray);
}

void	sphere_normal(t_obj *sphere, t_ray *ray)
{
	sub(&ray->x, &sphere->position, &ray->n);
	norm(&ray->n);
}

void	plane_normal(t_obj *plane, t_ray *ray)
{
	t_vec nl;

	if (dot(&ray->direction, &ray->direction) > 0)
		minus(&plane->direction, &ray->n);
	else
		ray->n = plane->direction;
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->direction) < 0)
		ray->n = nl;
	else
		minus(&nl, &ray->n);
}

void	cylinder_normal(t_obj *cylinder, t_ray *ray)
{
	double	m;
	t_vec	oc;
	t_vec	a;
	t_vec	b;
	t_vec	nl;

	sub(&ray->origin, &cylinder->position, &oc);
	m = (dot(&ray->direction, &cylinder->direction) * ray->distance) + \
	dot(&oc, &cylinder->direction);
	nmulti(&cylinder->direction, m, &a);
	sub(&ray->x, &cylinder->position, &b);
	sub(&a, &b, &ray->n);
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->direction) < 0)
		ray->n = nl;
	else
		minus(&nl, &ray->n);
}

void	cone_normal(t_obj *cone, t_ray *ray)
{
	t_vec		nl;
	t_vec		ac;
	t_vec		a;
	t_vec		b;
	t_vec		oc;
	double		m;
	t_vec		c;
	t_vec		d;
	double		len_ac;
	double		radius;
	double		koef;
	double		k;

	sub(&ray->origin, &cone->position, &oc);
	m = (dot(&ray->direction, &cone->direction) * ray->distance) + \
	dot(&oc, &cone->direction);
	nmulti(&cone->direction, m, &a);
	sub(&cone->position, &cone->position, &b);
	sum(&a, &b, &ac);
	len_ac = len(&ac);
	radius = len_ac * cone->angle;
	k = radius / m;
	koef = (1 + k * k) * m;
	nmulti(&cone->direction, koef, &d);
	sub(&ray->x, &cone->position, &c);
	sub(&c, &d, &ray->n);
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->direction) < 0)
		ray->n = nl;
	else
		minus(&nl, &ray->n);
}
