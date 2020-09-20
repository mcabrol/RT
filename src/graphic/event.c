/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 15:21:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	hook(t_rtv1 *rtv1)
{
	t_win	*main;
	t_win	*setting;

	main = &rtv1->main;
	setting = &rtv1->setting;
	mlx_hook(main->win_ptr, 2, (1L << 2), key, rtv1);
	mlx_hook(main->win_ptr, 6, (1L << 6), hover, rtv1);
	mlx_hook(main->win_ptr, 4, (1L << 4), mouse, rtv1);
	mlx_hook(main->win_ptr, 17, (1L << 17), close_rcross_main, rtv1);
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
