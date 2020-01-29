/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 16:37:41 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		sum(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z, dest);
}

void		sum_(t_vec *v1, t_vec *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

void		sub(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z, dest);
}

void		multi(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->x * v2->x, v1->y * v2->y, v1->z * v2->z, dest);
}

void		multi_(t_vec *v1, t_vec *v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
}

void		nmulti(t_vec *v1, double n, t_vec *dest)
{
	vec(v1->x * n, v1->y * n, v1->z * n, dest);
}

void		nmulti_(t_vec *v1, double n)
{
	v1->x *= n;
	v1->y *= n;
	v1->z *= n;
}

void		divide(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->x / v2->x, v1->y / v2->y, v1->z / v2->z, dest);
}

void		divide3(double a, t_vec *v, t_vec *dest)
{
	vec(a / v->x, a / v->y, a / v->z, dest);
}

void		ndivide(t_vec *v1, double n, t_vec *dest)
{
	double a;

	a = 1.0 / n;
	vec(v1->x * a, v1->y * a, v1->z * a, dest);
}

void		ndivide_(t_vec *v1, double n)
{
	double a;

	a = 1.0 / n;
	v1->x *= a;
	v1->y *= a;
	v1->z *= a;
}

void		minus(t_vec *v, t_vec *dest)
{
	vec(-v->x, -v->y, -v->z, dest);
}

void		minus_(t_vec *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
}

void		cross(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->y * v2->z - v1->z * v2->y,
				v1->z * v2->x - v1->x * v2->z,
				v1->x * v2->y - v1->y * v2->x, dest);
}
