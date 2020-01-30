/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 16:15:55 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		vec(double a, double b, double c, t_vec *dest)
{
	dest->x = a;
	dest->y = b;
	dest->z = c;
}

t_vec		vecp(double a, double b, double c)
{
	t_vec vector;

	vector.x = a;
	vector.y = b;
	vector.z = c;
	return (vector);
}

void		veccp(t_vec *v, t_vec *dest)
{
	dest->x = v->x;
	dest->y = v->y;
	dest->z = v->z;
}

double		len(t_vec *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec		*norm(t_vec *v)
{
	double l;

	if (v->x == 0 && v->y == 0 && v->z == 0)
		return (v);
	l = len(v);
	v->x /= l;
	v->y /= l;
	v->z /= l;
	return (v);
}

void		norm_(t_vec *v, t_vec *dest)
{
	double a;

	a = 1 / sqrt(norm_s(v));
	dest->x = v->x * a;
	dest->y = v->y * a;
	dest->z = v->z * a;
}

double 		norm_s(t_vec *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}
