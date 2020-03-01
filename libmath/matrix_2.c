/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:49:37 by judrion           #+#    #+#             */
/*   Updated: 2020/03/01 12:29:32 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"


void matrix_identity(t_matrix *m)
{
	m->data[0][0] = 1.0;
	m->data[1][1] = 1.0;
	m->data[2][2] = 1.0;
	m->data[3][3] = 1.0;
}

void matrix_create(t_matrix *m, int fill)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->data[i][j] = 0.0;
			j = j + 1;
		}
		i = i + 1;
	}
	if (fill != NO_FILL)
		matrix_identity(m);
}

void matrix_print(t_matrix *m, int format)
{
	int			i;
	int			j;

	i = 0;
	if (format == WOLFRAM)
		printf("{");
	while (i < 4)
	{
		j = 0;
		if (format == WOLFRAM)
			printf("{");
		while (j < 4)
		{
			if (format == WOLFRAM)
			{
				if (j < 3)
				printf("%.3f,", m->data[i][j]);
			else
				printf("%.3f", m->data[i][j]);
			}
			else
				printf("[%+.3f]", m->data[i][j]);
			j = j + 1;
		}
		if (format == WOLFRAM)
		{
			if (i < 3)
				printf("},");
			else
				printf("}");
		}
		else
			printf("\n");
		i = i + 1;
	}
	if (format == WOLFRAM)
	{
		printf("}");
		printf("\n");
	}
}

void matrix_transpose(t_matrix *a, t_matrix *dst)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst->data[i][j] = a->data[j][i];
			j = j + 1;
		}
		i = i + 1;
	}
}

t_matrix *matrix_lookat(t_obj *obj, t_vec *from, t_vec *to)
{
	t_vec	forward;
	t_vec	right;
	t_vec	up;
	t_vec	orientation;
	t_matrix	*m;

	m = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	normal(vec(0, 1, 0, &orientation), orientation);
	normal(sub(&from, &to, &forward), &forward));
	cross(&orientation, &forward, &right);
	cross(&forward, &right, &up);
	matrix_create(m, 1);
	m->data[0][0] = right.x;
	m->data[0][1] = right.y;
	m->data[0][2] = right.z;
	m->data[1][0] = up.x;
	m->data[1][1] = up.y;
	m->data[1][2] = up.z;
	m->data[2][0] = forward.x;
	m->data[2][1] = forward.y;
	m->data[2][2] = forward.z;
	m->data[3][0] = from.x;
	m->data[3][1] = from.y;
	m->data[3][2] = from.z;
	return (m);
}
