/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 19:04:27 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		bg_gradient(t_win *render)
{
	int x;
	int y;
	int c1;
	// int c2;

	y = 0;
	c1 = F_GREY;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(render, x, y, c1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(render->win.mlx_ptr, render->win.win_ptr,
							render->win.img_ptr, 0, 0);
}

void 		logo_center(t_win *render)
{
	int 	height;
	int 	width;
	int		x;
	int		y;

	render->win.img_logo = mlx_xpm_file_to_image(render->win.mlx_ptr, "19.xpm",
						   &width, &height);
	x = (WIDTH / 2) - (width / 2);
	y = (HEIGHT / 2) - (height / 2);
	mlx_put_image_to_window(render->win.mlx_ptr, render->win.win_ptr,
							render->win.img_logo, x, y);

}
