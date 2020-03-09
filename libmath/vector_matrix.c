/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:01:09 by judrion           #+#    #+#             */
/*   Updated: 2020/03/09 14:19:44 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void vector_matrix_mult(t_vec *src, t_matrix *m, t_vec *dst)
{
	int 	i;
	int		j;
	double	output[4];
	double	input[4];

	i = 0;
	ft_memcpy(input, src, sizeof(double) * 4);
	ft_bzero(output, sizeof(double) * 4);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			output[i] = output[i] + m->data[i][j] * input[j];
			j = j + 1;
		}
		i = i + 1;
	}
	ft_memcpy(dst, output, sizeof(double) * 4);
	// vector_print(dst, TERM);
}
