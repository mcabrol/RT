/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:54:01 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:03:29 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	plane_normal(t_radiance *radiance, t_vec *origin, t_vec *direction, t_object *obj)
{
	t_vec 	tmp;

	nmulti(direction, radiance->distance, &tmp);
	sum(origin, &tmp, &radiance->x);
	if (dot(direction,direction) > 0)
		minus(&obj->direction, &radiance->n);
	else
		radiance->n = obj->direction;
	radiance->nl = *norm(&radiance->n);
	if (dot(&radiance->nl, direction) < 0)
		radiance->n = radiance->nl;
	else
		minus(&radiance->nl, &radiance->n);
}

void	sphere_normal(t_radiance *radiance, t_vec *origin, t_vec *direction, t_object *obj)
{
	t_vec 	tmp;

	nmulti(direction, radiance->distance, &tmp);
	sum(origin, &tmp, &radiance->x);
	sub(&radiance->x, &obj->position, &radiance->n);
	radiance->nl = *norm(&radiance->n);
	if (dot(&radiance->nl, direction) < 0)
		radiance->n = radiance->nl;
	else
		minus(&radiance->nl, &radiance->n);
}

void 	cylinder_normal(t_radiance *radiance, t_vec *origin, t_vec *direction, t_object *obj)
{
	double	m;
	t_vec 	tmp;
	t_vec	oc;
	t_vec	a;
	t_vec	b;

	nmulti(direction, radiance->distance, &tmp);
	sum(origin, &tmp, &radiance->x);

	sub(origin, &obj->position, &oc);

	m = (dot(direction, &obj->direction) * radiance->distance) + dot(&oc, &obj->direction);

	nmulti(&obj->direction, m, &a);
	sub(&radiance->x, &obj->position, &b);
	sub(&a, &b, &radiance->n);
	radiance->nl = *norm(&radiance->n);
	if (dot(&radiance->nl, direction) < 0)
		radiance->n = radiance->nl;
	else
		minus_(&radiance->nl);
}
