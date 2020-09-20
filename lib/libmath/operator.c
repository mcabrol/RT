/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 17:16:43 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

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

void		sum3(t_vec *v1, t_vec *v2, t_vec *v3, t_vec *dest)
{
	vec(v1->x + v2->x + v3->x, v1->y + v2->y + v3->y, v1->z + v2->z + v3->z, \
		dest);
}

void		sub(t_vec *v1, t_vec *v2, t_vec *dest)
{
	vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z, dest);
}

void		sub3(t_vec *v1, t_vec *v2, t_vec *v3, t_vec *dest)
{
	vec(v1->x - v2->x - v3->x, v1->y - v2->y - v3->y, v1->z - v2->z - v3->z, \
		dest);
}
