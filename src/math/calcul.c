/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 16:15:58 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			len(t_vec *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double			dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double			max(t_vec *v)
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

static int		inner_check_point(t_vec *k, t_vec *v, t_vec *origin, t_obj *obj)
{
	v[0].z = T_MAX;
	sub(origin, &obj->position, &v[5]);
	quadratic_base(*k, &v[0]);
	if (v[0].x == T_MAX && v[0].y == T_MAX && v[0].z == T_MAX)
		return (-1);
	return (0);
}

double			check_point(t_vec *k, t_vec *direction, \
						t_vec *origin, t_obj *obj)
{
	t_vec	v[6];
	double	m[2];

	if (inner_check_point(k, &v[0], origin, obj) == -1)
		return (T_MAX);
	m[0] = (dot(direction, &obj->direction) * v[0].x) \
		+ dot(&v[5], &obj->direction);
	nmulti(&obj->direction, m[0], &v[3]);
	sub(&obj->position, &obj->position, &v[4]);
	sum(&v[3], &v[4], &v[1]);
	if (obj->height != 0 \
		&& (len(&v[1]) > obj->height || dot(&v[1], &obj->direction) < 0))
		v[0].x = T_MAX;
	m[1] = (dot(direction, \
		&obj->direction) * v[0].y) + dot(&v[5], &obj->direction);
	nmulti(&obj->direction, m[1], &v[3]);
	sub(&obj->position, &obj->position, &v[4]);
	sum(&v[3], &v[4], &v[1]);
	if (obj->height != 0 && (len(&v[1]) > obj->height \
		|| dot(&v[1], &obj->direction) < 0))
		v[0].y = T_MAX;
	v[0].z = define_tmin(v[0]);
	return (v[0].z);
}
