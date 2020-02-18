/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 16:59:55 by mcabrol          ###   ########.fr       */
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
	while (++y <= HEIGHT)
	{
		x = -1;
		while (++x <= WIDTH)
			put_pixel(win, x, y, c1);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
							win->img_ptr, 0, 0);
}

void 		logo_center(t_win *win)
{
	int 	height;
	int 	width;
	int		x;
	int		y;

	win->img_logo = mlx_xpm_file_to_image(win->mlx_ptr, "19.xpm",
						   &width, &height);
	x = (WIDTH / 2) - (width / 2);
	y = (HEIGHT / 2) - (height / 2);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
							win->img_logo, x, y);
}

void 		finish_center(t_win *win)
{
	int 	height;
	int 	width;
	int		x;
	int		y;

	win->img_finish = mlx_xpm_file_to_image(win->mlx_ptr, "terminated.xpm",
						   &width, &height);
	x = (WIDTH / 2) - (width / 2) + 1;
	y = (HEIGHT / 2) - (height / 2) + 1;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
							win->img_finish, x, y);
}
