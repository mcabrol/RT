/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:14:35 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 17:19:23 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

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
