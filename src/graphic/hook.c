/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/28 16:34:51 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	hook(t_rtv1 *rtv1)
{
	t_win *main;
	t_win *image;

	main = &rtv1->main;
	image = &rtv1->image[rtv1->id];
	mlx_hook(main->win_ptr, 2, 1L << 2, key, rtv1);
	// mlx_hook(image->win_ptr, 2, 1L << 2, exit_hook, rtv1);
	mlx_hook(main->win_ptr, 6, (1L << 6), hover, rtv1);
	mlx_mouse_hook(main->win_ptr, mouse, rtv1);
}

int		exit_hook(int keycode, t_rtv1 *rtv1)
{
	t_win *win;

	win = &rtv1->image[rtv1->id];
	if (keycode == 53)
	{
		mlx_destroy_window(rtv1->mlx_ptr, win->win_ptr);
		exit(0);
	}
	return (EXIT_SUCCESS);
}

int 	hover(int x, int y, t_rtv1 *rtv1)
{
	int state;

	if (rtv1->state == SETUP)
	{
		state = rtv1->png.h_render;
		rtv1->png.h_render = (x > 156 && x < 243 && y > 527 && y < 558) ? TRUE : FALSE;
		if (state != rtv1->png.h_render)
			put_setup(rtv1);
	}
	if (rtv1->state == RENDER)
	{
		state = rtv1->png.h_cancel;
		rtv1->png.h_cancel = (x > 156 && x < 243 && y > 527 && y < 558) ? TRUE : FALSE;
		if (state != rtv1->png.h_cancel)
			put_setup(rtv1);
		state = rtv1->png.h_show;
		rtv1->png.h_show = (x > 148 && x < 254 && y > 429 && y < 459) ? TRUE : FALSE;
		if (state != rtv1->png.h_show)
			put_setup(rtv1);
			state = rtv1->png.h_save;
		rtv1->png.h_save = (x > 148 && x < 254 && y > 383 && y < 415) ? TRUE : FALSE;
		if (state != rtv1->png.h_save)
			put_setup(rtv1);
	}
	return (EXIT_SUCCESS);
}
