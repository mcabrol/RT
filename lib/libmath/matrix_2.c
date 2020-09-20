/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:49:37 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 17:30:54 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void		matrix_identity(t_matrix *m)
{
	m->data[0][0] = 1.0;
	m->data[1][1] = 1.0;
	m->data[2][2] = 1.0;
	m->data[3][3] = 1.0;
}

void		matrix_create(t_matrix *m, int fill)
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

static void	inner_matrix_print(int format, t_matrix *m)
{
	int		j;

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
}

void		matrix_print(t_matrix *m, int format)
{
	int			i;

	i = 0;
	if (format == WOLFRAM)
		ft_printf("{");
	while (i < 4)
	{
		inner_matrix_print(format);
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

void		matrix_transpose(t_matrix *a, t_matrix *dst)
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
