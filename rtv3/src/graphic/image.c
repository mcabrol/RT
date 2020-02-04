/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 18:00:01 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		image(t_rtv1 *rtv1)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			i = (HEIGHT - 1 - y) * WIDTH + x - 1;
			put_pixel_vector(&rtv1->win,
							 WIDTH - x, HEIGHT - y,
							 &rtv1->render.screen[i]);
			x++;
		}
		y++;
	}
	free(rtv1->render.screen);
}
