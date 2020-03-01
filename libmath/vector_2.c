/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:15:31 by judrion           #+#    #+#             */
/*   Updated: 2020/01/29 16:39:46 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void		vector_normalize(t_vec *src, t_vec *dst)
{
	double			magnitude;
	double			lenght;

	lenght = vector_length(src);
	if (lenght != 0)
	{
		magnitude = 1 / vector_length(src);
		operator_mult(src, magnitude, dst);
	}
}

double		vector_dotproduct(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void		vector_crossprod(t_vec *a, t_vec *b, t_vec *dest)
{
	dest->x = a->y * b->z - b->y * a->z;
	dest->y = a->z * b->x - b->z * a->x;
	dest->z = a->x * b->y - b->x * a->y;
}

double		vector_length(t_vec *a)
{
	return (sqrtf(a->x * a->x + a->y * a->y + a->z * a->z));
}

void 	vector_print(t_vec *a, int format)
{
	if (format == TERM)
		printf("vector : [%.3f:%.3f:%.3f:%.3f]\n", a->x, a->y, a->z, a->w);
	else
		printf("{{%.3f,%.3f,%.3f,%.3f}}\n", a->x, a->y, a->z, a->w);

}
