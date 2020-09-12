/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 17:00:58 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		len(t_vec *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double		dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double		max(t_vec *v)
{
	if (v->x > v->y && v->x > v->z)
		return (v->x);
	else
	{
		if (v->y > v->z)
			return (v->y);
		else
			return (v->z);
	}
}

double		check_point(t_vec *k, t_vec *direction, t_vec *origin, t_obj *obj)
{
	t_vec	t;
	t_vec	ac;
	t_vec	a;
	t_vec	b;
	t_vec	oc;
	double	len_ac;
	double	m[2];

	t.z = T_MAX;
	sub(origin, &obj->position, &oc);
	quadratic_base(*k, &t);
	if (t.x == T_MAX && t.y == T_MAX && t.z == T_MAX)
		return (T_MAX);
	m[0] = (dot(direction, &obj->direction) * t.x) + dot(&oc, &obj->direction);
	nmulti(&obj->direction, m[0], &a);
	sub(&obj->position, &obj->position, &b);
	sum(&a, &b, &ac);
	len_ac = len(&ac);
	if (obj->height != 0 && (len_ac > obj->height || dot(&ac, &obj->direction) \
	< 0))
		t.x = T_MAX;
	m[1] = (dot(direction, &obj->direction) * t.y) + dot(&oc, &obj->direction);
	nmulti(&obj->direction, m[1], &a);
	sub(&obj->position, &obj->position, &b);
	sum(&a, &b, &ac);
	len_ac = len(&ac);
	if (obj->height != 0 && (len_ac > obj->height || dot(&ac, &obj->direction) \
	< 0))
		t.y = T_MAX;
	t.z = define_tmin(t);
	return (t.z);
}
