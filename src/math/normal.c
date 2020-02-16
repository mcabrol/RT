/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 18:58:00 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	sphere_normal(t_obj *sphere, t_ray *ray)
{
	sub(&ray->x, &sphere->position, &ray->n);
	norm(&ray->n);
}

void 	plane_normal(t_obj *plane, t_ray *ray)
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

void 	cylinder_normal(t_obj *cylinder, t_ray *ray)
{
	double	m;
	t_vec	oc;
	t_vec	a;
	t_vec	b;
	t_vec	nl;

	sub(&ray->origin, &cylinder->position, &oc);
	m = (dot(&ray->direction, &cylinder->direction) * ray->distance) + dot(&oc, &cylinder->direction);
	nmulti(&cylinder->direction, m, &a);
	sub(&ray->x, &cylinder->position, &b);
	sub(&a, &b, &ray->n);
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->direction) < 0)
		ray->n = nl;
	else
		minus(&nl, &ray->n);
}

void 	cone_normal(t_obj *cone, t_ray *ray)
{
	t_vec		nl;
	t_vec   	ac;
	t_vec   	a;
	t_vec 		b;
	t_vec		oc;
	double		m;
	t_vec		c;
	t_vec		d;
	double 		len_ac;
	double		radius;
	double		koef;
	double		k;

	sub(&ray->origin, &cone->position, &oc);
	m = (dot(&ray->direction, &cone->direction) * ray->distance) + dot(&oc, &cone->direction);
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

void		box_normal(t_obj *box, t_ray *ray)
{
	double			min[3];
	double			max[3];
	t_vec			rev_o;
	t_vec			p;

	divide3(1, &ray->direction, &rev_o);
	vec(box->position.x + box->a, box->position.y + box->b, box->position.z + box->c, &p);
	if (rev_o.x >= 0)
	{
		min[0] = (box->position.x - ray->origin.x) * rev_o.x;
		max[0] = (p.x - ray->origin.x) * rev_o.x;
	}
	else
	{
		min[0] = (p.x - ray->origin.x) * rev_o.x;
		max[0] = (box->position.x - ray->origin.x) * rev_o.x;
	}
	if (rev_o.y >= 0)
	{
		min[1] = (box->position.y - ray->origin.y) * rev_o.y;
		max[1] = (p.y - ray->origin.y) * rev_o.y;
	}
	else
	{
		min[1] = (p.y - ray->origin.y) * rev_o.y;
		max[1] = (box->position.y - ray->origin.y) * rev_o.y;
	}
	if (rev_o.z >= 0)
	{
		min[2] = (box->position.z - ray->origin.z) * rev_o.z;
		max[2] = (p.z - ray->origin.z) * rev_o.z;
	}
	else
	{
		min[2] = (p.z - ray->origin.z) * rev_o.z;
		max[2] = (box->position.z - ray->origin.z) * rev_o.z;
	}
	check_box(ray, min, max, rev_o);
}
