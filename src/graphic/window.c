/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 12:38:00 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			init_window(t_rtv1 *rtv1)
{
	rtv1->mlx_ptr = mlx_init();
	if (!rtv1->mlx_ptr)
		return (EXIT_FAILURE);
	rtv1->main = window(rtv1->mlx_ptr, W_MAIN, H_MAIN, "Raytracer");
	if (!rtv1->main.win_ptr || !rtv1->main.img_ptr)
		return (EXIT_FAILURE);
	if (init_sprite(rtv1))
	{
		free_all_sprite(&rtv1->sprite, rtv1->mlx_ptr);
		return (EXIT_FAILURE);
	}
	rtv1->id_win = 0;
	rtv1->id_ppm = 0;
	rtv1->main.available = -1;
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
	if (mlx_ptr && win.win_ptr)
		mlx_clear_window(mlx_ptr, win.win_ptr);
	return (win);
}

void		create_setting(t_rtv1 *rtv1)
{
	if (!rtv1->id_setting)
	{
		rtv1->setting = window(rtv1->mlx_ptr, W_SETTING, H_SETTING, "Settings");
		if (rtv1->setting.win_ptr)
		{
			mlx_hook(rtv1->setting.win_ptr, 6, (1L << 6), hover_setting, rtv1);
			mlx_mouse_hook(rtv1->setting.win_ptr, mouse_setting, rtv1);
			mlx_hook(rtv1->setting.win_ptr, 17, (1L << 17), close_rcross_s,\
					rtv1);
		}
		(rtv1->id_setting)++;
	}
	put_setting(rtv1);
}

int			close_settings(t_rtv1 *rtv1)
{
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->setting.img_ptr);
	mlx_destroy_window(rtv1->mlx_ptr, rtv1->setting.win_ptr);
	(rtv1->id_setting)--;
	return (EXIT_SUCCESS);
}
