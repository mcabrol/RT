/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:05:22 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		init_window(t_rtv1 *rtv1)
{
	rtv1->mlx_ptr = mlx_init();
	rtv1->main = window(rtv1->mlx_ptr, W_MAIN, H_MAIN, "Raytracer");
	init_sprite(rtv1);
	rtv1->id_win = 0;
	rtv1->id_ppm = 0;
}

t_win		window(void *mlx_ptr, int width, int height, char *name)
{
	t_win win;

	win.win_ptr = mlx_new_window(mlx_ptr, width, height, name);
	win.img_ptr = mlx_new_image(mlx_ptr, width, height);
	win.data_ptr = mlx_get_data_addr(win.img_ptr,
									&(win.bits_per_pixel),
									&(win.size_line),
									&(win.endian));
	return (win);
}
