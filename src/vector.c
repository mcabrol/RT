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

t_vec		vec(double a, double b, double c)
{
	t_vec vector;

	vector.x = a;
	vector.y = b;
	vector.z = c;
	return (vector);
}

t_vec		*cpy(t_vec *v1, t_vec *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = v2->z;
	return (v1);
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
