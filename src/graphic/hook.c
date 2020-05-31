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
	image = &rtv1->image[rtv1->id_win];
	mlx_hook(main->win_ptr, 2, 1L << 2, key, rtv1);
	// mlx_hook(image->win_ptr, 2, 1L << 2, exit_hook, rtv1);
	mlx_hook(main->win_ptr, 6, (1L << 6), hover, rtv1);
	mlx_mouse_hook(main->win_ptr, mouse, rtv1);
}

int		exit_hook(int keycode, t_rtv1 *rtv1)
{
	t_win *win;

	win = &rtv1->image[rtv1->id_win];
	if (keycode == 53)
	{
		mlx_destroy_window(rtv1->mlx_ptr, win->win_ptr);
		exit(0);
	}
	return (EXIT_SUCCESS);
}

int 	hover(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->png.setup_is_hover, 90, 181, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->png.retry_is_hover, 181, 272, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->png.save_is_hover, 272, 362, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->png.display_is_hover, 362, 453, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->png.render_is_hover, 453, 544, 0, 80))
		put_setup(rtv1);
	return (EXIT_SUCCESS);
}

int 	is_hover(int x, int y, int *button, int xmin, int xmax, int ymin, int ymax)
{
	int state;

	state = *button;
	*button = (x > xmin && x < xmax && y > ymin && y < ymax) ? TRUE : FALSE;
 	return ((state != *button) ? TRUE : FALSE);
}
