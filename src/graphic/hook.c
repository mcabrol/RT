/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/03 19:08:01 by mcabrol          ###   ########.fr       */
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
	if (rtv1->state == SETUP)
	{
		if (is_hover(x, y, &rtv1->png.h_render, 156, 243, 527, 558))
			put_setup(rtv1);
	}
	if (rtv1->state == RENDER)
	{
		if (is_hover(x, y, &rtv1->png.h_render, 156, 243, 527, 558))
			put_setup(rtv1);
		if (is_hover(x, y, &rtv1->png.h_show, 148, 254, 429, 459))
			put_setup(rtv1);
		if (is_hover(x, y, &rtv1->png.h_save, 148, 254, 383, 415))
			put_setup(rtv1);
	}
	return (EXIT_SUCCESS);
}

int 	is_hover(int x, int y, int *button, int xmin, int xmax, int ymin, int ymax)
{
	int state;

	state = *button;
	*button = (x > xmin && x < xmax && y > ymin && y < ymax) ? TRUE : FALSE;
 	return ((state != *button) ? TRUE : FALSE);
}
