/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:37:23 by judrion           #+#    #+#             */
/*   Updated: 2020/01/21 13:33:12 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void 		operator_addv(t_vec *src_1, t_vec *src_2, t_vec *dest)
{
	dest->x = src_1->x + src_2->x;
	dest->y = src_1->y + src_2->y;
	dest->z = src_1->z + src_2->z;
}

void 		operator_subv(t_vec *src_1, t_vec *src_2, t_vec *dest)
{
	dest->x = src_1->x - src_2->x;
	dest->y = src_1->y - src_2->y;
	dest->z = src_1->z - src_2->z;
}

void 		operator_mult(t_vec *src_1, double determinant, t_vec *dest)
{
	dest->x = src_1->x * determinant;
	dest->y = src_1->y * determinant;
	dest->z = src_1->z * determinant;
}

void 		operator_multv(t_vec *src_1, t_vec *src_2, t_vec *dest)
{
	dest->x = src_1->x * src_2->x;
	dest->y = src_1->y * src_2->y;
	dest->z = src_1->z * src_2->z;
}

void 		operator_div(t_vec *src_1, double determinant, t_vec *dest)
{
	if (determinant != 0)
	{
		dest->x = src_1->x / determinant;
		dest->y = src_1->y / determinant;
		dest->z = src_1->z / determinant;
	}
}
