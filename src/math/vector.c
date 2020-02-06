/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
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

t_vec		*norm(t_vec *v)
{
	double a;

	a = 1 / sqrt(norm_s(v));
	v->x *= a;
	v->y *= a;
	v->z *= a;
	return (v);
}

double 		norm_s(t_vec *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}
