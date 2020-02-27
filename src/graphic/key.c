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

int		key(int keycode, t_rtv1 *rtv1)
{
	t_win *main;

	main = &rtv1->main;
	if (keycode == 53)
	{
		mlx_destroy_window(rtv1->mlx_ptr, main->win_ptr);
		exit(0);
	}
	if (keycode == 36)
	{
		pathtracer(rtv1);
	}
	if (keycode == 49)
	{
		rtv1->image[rtv1->id] = window(rtv1->mlx_ptr, rtv1->scene.width, rtv1->scene.height, "Image");
		image(rtv1);
		(rtv1->id++);
	}
	if (keycode == 1)
	{
		write_ppm(rtv1);
	}
	return (EXIT_SUCCESS);
}
