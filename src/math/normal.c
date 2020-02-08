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
	sub(&ray->x, &sphere->p, &ray->n);
	norm(&ray->n);
}

void 	plane_normal(t_obj *plane, t_ray *ray)
{
	t_vec nl;

	if (dot(&ray->d, &ray->d) > 0)
		minus(&plane->d, &ray->n);
	else
		ray->n = plane->d;
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->d) < 0)
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

	sub(&ray->o, &cylinder->p, &oc);
	m = (dot(&ray->d, &cylinder->d) * ray->dist) + dot(&oc, &cylinder->d);
	nmulti(&cylinder->d, m, &a);
	sub(&ray->x, &cylinder->p, &b);
	sub(&a, &b, &ray->n);
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->d) < 0)
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

	sub(&ray->o, &cone->p, &oc);
	m = (dot(&ray->d, &cone->d) * ray->dist) + dot(&oc, &cone->d);
	nmulti(&cone->d, m, &a);
	sub(&cone->p, &cone->p, &b);
	sum(&a, &b, &ac);
	len_ac = len(&ac);
	radius = len_ac * cone->a;
	k = radius / m;
	koef = (1 + k * k) * m;
	nmulti(&cone->d, koef, &d);
	sub(&ray->x, &cone->p, &c);
	sub(&c, &d, &ray->n);
	nl = *norm(&ray->n);
	if (dot(&nl, &ray->d) < 0)
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

	divide3(1, &ray->d, &rev_o);
	vec(box->p.x + box->ca, box->p.y + box->cb, box->p.z + box->cc, &p);
	if (rev_o.x >= 0)
	{
		min[0] = (box->p.x - ray->o.x) * rev_o.x;
		max[0] = (p.x - ray->o.x) * rev_o.x;
	}
	else
	{
		min[0] = (p.x - ray->o.x) * rev_o.x;
		max[0] = (box->p.x - ray->o.x) * rev_o.x;
	}
	if (rev_o.y >= 0)
	{
		min[1] = (box->p.y - ray->o.y) * rev_o.y;
		max[1] = (p.y - ray->o.y) * rev_o.y;
	}
	else
	{
		min[1] = (p.y - ray->o.y) * rev_o.y;
		max[1] = (box->p.y - ray->o.y) * rev_o.y;
	}
	if (rev_o.z >= 0)
	{
		min[2] = (box->p.z - ray->o.z) * rev_o.z;
		max[2] = (p.z - ray->o.z) * rev_o.z;
	}
	else
	{
		min[2] = (p.z - ray->o.z) * rev_o.z;
		max[2] = (box->p.z - ray->o.z) * rev_o.z;
	}
	check_box(ray, min, max, rev_o);
}
