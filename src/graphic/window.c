/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/08 20:43:21 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 		init_window(t_rtv1 *rtv1)
{
	rtv1->mlx_ptr = mlx_init();
	rtv1->main = window(rtv1->mlx_ptr, W_MAIN, H_MAIN, "Raytracer");
	if (init_sprite(rtv1))
		return (EXIT_FAILURE);
	rtv1->id_win = 0;
	rtv1->id_ppm = 0;
	return (EXIT_SUCCESS);
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
