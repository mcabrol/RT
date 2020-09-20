/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:23:58 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 17:17:16 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	matrix_mult(t_matrix *a, t_matrix *b, t_matrix *dest)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				dest->data[i][j] += a->data[i][k] * b->data[k][j];
				k = k + 1;
			}
			j = j + 1;
		}
		i = i + 1;
	}
}

void	matrix_scaling(t_matrix *m, t_vec *scaling)
{
	m->data[0][0] = scaling->x;
	m->data[1][1] = scaling->y;
	m->data[2][2] = scaling->z;
	m->data[3][3] = scaling->w;
}

void	matrix_rotate(t_matrix *m, double angle, int axe)
{
	if (axe == X_AXE)
	{
		m->data[0][0] = 1;
		m->data[1][1] = cos((angle * M_PI) / 180);
		m->data[1][2] = sin((angle * M_PI) / 180);
		m->data[2][1] = -sin((angle * M_PI) / 180);
		m->data[2][2] = cos((angle * M_PI) / 180);
	}
	else if (axe == Y_AXE)
	{
		m->data[0][0] = cos((angle * M_PI) / 180);
		m->data[0][2] = sin((angle * M_PI) / 180);
		m->data[1][1] = 1;
		m->data[2][0] = -sin((angle * M_PI) / 180);
		m->data[2][2] = cos((angle * M_PI) / 180);
	}
	else if (axe == Z_AXE)
	{
		m->data[0][0] = cos((angle * M_PI) / 180);
		m->data[0][1] = sin((angle * M_PI) / 180);
		m->data[1][0] = sin((angle * M_PI) / 180);
		m->data[1][1] = cos((angle * M_PI) / 180);
		m->data[2][2] = 1;
	}
}

void	matrix_translate(t_matrix *a, t_vec *translate)
{
	matrix_identity(a);
	a->data[0][3] = translate->x;
	a->data[1][3] = translate->y;
	a->data[2][3] = translate->z;
	a->data[3][0] = translate->w;
}
