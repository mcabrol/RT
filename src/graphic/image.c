/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:04:48 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		image(t_rtv1 *rtv1)
{
	int		x;
	int		y;
	int		i;
	t_win	*win;

	win = &rtv1->win;
	win->render_win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "render");
	win->render_img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->render_data_ptr = mlx_get_data_addr(win->render_img_ptr,
			&(win->bits_per_pixel),
			&(win->size_line),
			&(win->endian));
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			i = (HEIGHT - 1 - y) * WIDTH + x - 1;
			put_pixel_vector(&rtv1->win,
							x, HEIGHT - y,
							 &rtv1->render.screen[i]);
			x++;
		}
		y++;
	}
}
