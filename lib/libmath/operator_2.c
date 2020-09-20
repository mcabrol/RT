/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:14:35 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 17:49:42 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double		operator_distance(t_vec *p1, t_vec *p2)
{
	t_vec	p_tmp;
	double	dist;

	sub(p1, p2, &p_tmp);
	dist = vector_dotproduct(&p_tmp, &p_tmp);
	return (sqrtf(dist));
}

void		sub_(t_vec *v1, t_vec *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}

void		multiplication(t_vec *v1, t_vec *v2, t_vec *dest)
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
