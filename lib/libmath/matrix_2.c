/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:49:37 by judrion           #+#    #+#             */
/*   Updated: 2020/03/10 14:48:50 by mcabrol          ###   ########.fr       */
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
		ft_printf("{");
	while (i < 4)
	{
		j = 0;
		if (format == WOLFRAM)
			ft_printf("{");
		while (j < 4)
		{
			if (format == WOLFRAM)
			{
				if (j < 3)
				ft_printf("%.3f,", m->data[i][j]);
			else
				ft_printf("%.3f", m->data[i][j]);
			}
			else
				ft_printf("[%+.3f]", m->data[i][j]);
			j = j + 1;
		}
		if (format == WOLFRAM)
		{
			if (i < 3)
				ft_printf("},");
			else
				ft_printf("}");
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


t_matrix *matrix_lookat(t_vec *from, t_vec *to)
{
	t_vec	*forward;
	t_vec	right;
	t_vec	up;
	t_vec	orientation;
	t_matrix	*m[3];

	m[0] = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	vec(0, 1, 0, &orientation);
	orientation = *norm(&orientation);
	sub(from, to, forward);
	forward = norm(forward);
	cross(&orientation, forward, &right);
	right = *norm(&right);
	cross(forward, &right, &up);
	up = *norm(&up);
	matrix_create(m[0], FILL);
	m[0]->data[0][0] = right.x;
	m[0]->data[0][1] = right.y;
	m[0]->data[0][2] = right.z;
	m[0]->data[1][0] = up.x;
	m[0]->data[1][1] = up.y;
	m[0]->data[1][2] = up.z;
	m[0]->data[2][0] = forward->x;
	m[0]->data[2][1] = forward->y;
	m[0]->data[2][2] = forward->z;
	// matrix_print(m[0], WOLFRAM);

	m[1] = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	matrix_create(m[0], FILL);

	m[1]->data[3][0] = from->x;
	m[1]->data[3][1] = from->y;
	m[1]->data[3][2] = from->z;
	// matrix_print(m[1], WOLFRAM);

	m[2] = (t_matrix*)ft_memalloc(sizeof(t_matrix));
	matrix_create(m[2], FILL);

	matrix_mult(m[1], m[0], m[2]);
	free(m[0]);
	free(m[1]);
	// matrix_print(m[2], WOLFRAM);
	ft_printf("=================================================\n");
	return (m[2]);
}
