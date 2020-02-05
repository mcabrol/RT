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
