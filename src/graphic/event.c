/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/07 18:59:51 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	hook(t_rtv1 *rtv1)
{
	t_win	*main;
	t_win	*setting;
	t_win	*image;

	main = &rtv1->main;
	setting = &rtv1->setting;
	image = &rtv1->image[rtv1->id_win];
	mlx_hook(main->win_ptr, 2, 1L << 2, key, rtv1);
	// mlx_hook(image->win_ptr, 2, 1L << 2, exit_hook, rtv1);
	mlx_hook(main->win_ptr, 6, (1L << 6), hover, rtv1);
	mlx_mouse_hook(main->win_ptr, mouse, rtv1);
}

int		exit_hook(int keycode, t_rtv1 *rtv1)
{
	t_win	*win;

	win = &rtv1->image[rtv1->id_win];
	if (keycode == 53)
	{
		mlx_destroy_window(rtv1->mlx_ptr, win->win_ptr);
		exit(0);
	}
	return (EXIT_SUCCESS);
}

int		is_hover(int x, int y, t_button *button, int xmin, int xmax, int ymin,
	int ymax)
{
	BOOL	tmp;

	tmp = button->is_hover;
	button->is_hover = (x > xmin && x < xmax && y > ymin && y < ymax) ? TRUE : FALSE;
 	return ((tmp != button->is_hover) ? TRUE : FALSE);
}
