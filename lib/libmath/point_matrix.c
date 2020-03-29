/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:27:19 by judrion           #+#    #+#             */
/*   Updated: 2020/01/21 13:33:19 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void 	point_matrix_scaling(t_vec *p, t_matrix *m, t_vec *dst)
{
	dst->x = p->x * m->data[0][0];
	dst->y = p->y * m->data[1][1];
	dst->z = p->z * m->data[2][2];
}

void 	point_matrix_rotate(t_vec *p, t_matrix *m, t_vec *dst)
{
	double	w;

	dst->x = p->x * m->data[0][0]
			+ p->y * m->data[0][1]
			+ p->z * m->data[0][2];
	dst->y = p->x * m->data[1][0]
			+ p->y * m->data[1][1]
			+ p->z * m->data[1][2];
	dst->z = p->x * m->data[2][0]
			+ p->y * m->data[2][1]
			+ p->z * m->data[2][2];
	// w = p->x * m->data[0][2]
	// 		+ p->y * m->data[1][3]
	// 		+ p->z * m->data[2][3];
}

void 	point_matrix_mult(t_vec *p, t_matrix *m, t_vec *dst)
{
	double		w;
	t_vec		tmp;

	vector_init(&tmp, p->x, p->y, p->z);
 	dst->x = tmp.x * m->data[0][0]
 			+ tmp.y * m->data[1][0]
 			+ tmp.z * m->data[2][0]
 			+ m->data[3][0];
 	dst->y = tmp.x * m->data[0][1]
 			+ tmp.y * m->data[1][1]
 			+ tmp.z * m->data[2][1]
 			+ m->data[3][1];
 	dst->z = tmp.x * m->data[0][2]
 			+ tmp.y * m->data[1][2]
 			+ tmp.z * m->data[2][2]
 			+ m->data[3][2];
 	w = tmp.x * m->data[0][3]
 			+ tmp.y * m->data[1][3]
 			+ tmp.z * m->data[2][3]
 			+ m->data[3][3];
	if (w != 1 && w != 0)
	{
		dst->x = dst->x / w;
		dst->y = dst->y / w;
	    dst->z = dst->z / w;
	}
}

void 	point_translate(t_vec *p, t_matrix *m, t_vec *dst)
{
	dst->x = p->x * m->data[0][0];
}
