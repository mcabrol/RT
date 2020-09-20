/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 16:21:58 by judrion          ###   ########.fr       */
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
	t_vec		vec[7];
	double		doub[5];

	sub(&ray->origin, &cone->position, &vec[4]);
	doub[0] = (dot(&ray->direction, &cone->direction) * ray->distance) + \
	dot(&vec[4], &cone->direction);
	nmulti(&cone->direction, doub[0], &vec[2]);
	sub(&cone->position, &cone->position, &vec[3]);
	sum(&vec[2], &vec[3], &vec[1]);
	doub[1] = len(&vec[1]);
	doub[2] = doub[1] * cone->angle;
	doub[4] = doub[2] / doub[0];
	doub[3] = (1 + doub[4] * doub[4]) * doub[0];
	nmulti(&cone->direction, doub[3], &vec[6]);
	sub(&ray->x, &cone->position, &vec[5]);
	sub(&vec[5], &vec[6], &ray->n);
	vec[0] = *norm(&ray->n);
	if (dot(&vec[0], &ray->direction) < 0)
		ray->n = vec[0];
	else
		minus(&vec[0], &ray->n);
}
