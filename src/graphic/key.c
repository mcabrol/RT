/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 10:20:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key(int keycode, t_rtv1 *rtv1)
{
	t_win *main;

	main = &rtv1->main;
	if (keycode == 53)
	{
		//commented to cancel a segfault
		//mlx_destroy_window(rtv1->mlx_ptr, main->win_ptr);
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
