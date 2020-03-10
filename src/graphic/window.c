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
