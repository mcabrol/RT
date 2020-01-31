/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:10:38 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 19:56:01 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	image(t_render *render)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			put_pixel_vector(render, WIDTH - x, HEIGHT - y,
				&render->screen[(HEIGHT - 1 - y) * WIDTH + x]);
		}
	}
	mlx_put_image_to_window(render->win.mlx_ptr, render->win.win_ptr,
							render->win.img_ptr, 0, 0);
}
