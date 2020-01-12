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

t_vec		sum(t_vec *v1, t_vec *v2)
{
	return (vec(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_vec		sub(t_vec *v1, t_vec *v2)
{
	return (vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

t_vec		multi(t_vec *v1, t_vec *v2)
{
	return (vec(v1->x * v2->x, v1->y * v2->y, v1->z * v2->z));
}

t_vec		nmulti(t_vec *v1, double n)
{
	return (vec(v1->x * n, v1->y * n, v1->z * n));
}

t_vec		divide(t_vec *v1, t_vec *v2)
{
	return (vec(v1->x / v2->x, v1->y / v2->y, v1->z / v2->z));
}

t_vec		ndivide(t_vec *v1, double n)
{
	return (vec(v1->x / n, v1->y / n, v1->z / n));
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
		if (v->y > v->z)
			return (v->y);
		else
			return (v->z);
}

t_vec		minus(t_vec *v)
{
	return (vec(-v->x, -v->y, -v->z));
}

t_vec		cross(t_vec *v1, t_vec *v2)
{
	return (vec(v1->y * v2->z - v1->z * v2->y,
				v1->z * v2->x - v1->x * v2->z,
				v1->x * v2->y - v1->y * v2->x));
}
