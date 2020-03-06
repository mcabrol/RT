/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/06 19:11:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void 	swap(unsigned int* a, unsigned int* b)
{
	unsigned int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


static void 	sort(unsigned int *arr, int n)
{
	int 	gap;
	int 	i;
	double 	shrink;
	BOOL 	sorted;

	gap = n;
	i = 0;
	shrink = 1.3;
	sorted = FALSE;
	while (!sorted)
	{
		gap /= shrink;
		sorted = gap < TRUE ? TRUE : FALSE;
		gap = gap < 1 ? 1 : gap;
		i = 0;
		while (i + gap < n)
		{
			if (arr[i] > arr[i + gap])
			{
				swap(&arr[i], &arr[i + gap]);
				sorted = FALSE;
			}
			i++;
		}
	}
}

void 	median(t_rtv1 *rtv1)
{
	int 			i;
	int 			j;
	unsigned int	red[9];
	unsigned int	green[9];
	unsigned int	blue[9];

	i = 0;
	while (i < rtv1->scene.width * rtv1->scene.height)
	{
		ft_printf("i> %d\n", i);
		j = 0;
		while (j < 9)
		{
			red[j] = to_byte(rtv1->screen[i + (j * rtv1->scene.width)].x, GAMMA);
			green[j] = to_byte(rtv1->screen[i + (j * rtv1->scene.width)].y, GAMMA);
			blue[j] = to_byte(rtv1->screen[i + (j * rtv1->scene.width)].z, GAMMA);
			// ft_printf("red> %d\n", red[j]);
			// ft_printf("green> %d\n", green[j]);
			// ft_printf("blue> %d\n", blue[j]);
			j++;
		}
		sort(red, 9);
		sort(green, 9);
		sort(blue, 9);

		rtv1->screen[i].x = red[4];
		rtv1->screen[i].y = green[4];
		rtv1->screen[i].z = blue[4];
		i++;
	}
}
