/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:02:14 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		bg_gradient(t_win *win)
{
	int x;
	int y;
	int c1;
	// int c2;

	y = -1;
	c1 = F_GREY;
	while (++y <= M_HEIGHT)
	{
		x = -1;
		while (++x <= M_WIDTH)
			put_pixel(win, x, y, c1);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
							win->img_ptr, 0, 0);
}

void 		logo_center(t_win *win)
{
	int 	height;
	int 	width;

	win->img_logo = mlx_png_file_to_image(win->mlx_ptr, "img/startup.png",
						   &width, &height);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
							win->img_logo, 0, 0);
}

void 		finish_center(t_win *win)
{
	int 	height;
	int 	width;

	win->img_logo = mlx_png_file_to_image(win->mlx_ptr, "img/success.png",
						   &width, &height);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
							win->img_logo, 0, 0);
}
