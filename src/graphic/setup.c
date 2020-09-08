/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/07 12:28:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		set_format(t_rtv1 *rtv1, int sample, int width, int height)
{
	if (rtv1->tabs == SAMPLE)
		rtv1->scene.samples = sample;
	else
	{
		rtv1->scene.width = width;
		rtv1->scene.height = height;
	}
}

int				close_settings(t_rtv1 *rtv1)
{
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->setting.img_ptr);
	mlx_destroy_window(rtv1->mlx_ptr, rtv1->setting.win_ptr);
	(rtv1->id_setting)--;
	return (EXIT_SUCCESS);
}

int				mouse_setting(int button, int x, int y, t_rtv1 *rtv1)
{
	x = 0;
	y = 0;
	if (button == 1)
	{
		if (rtv1->sprite.format.is_hover)
			rtv1->tabs = FORMAT;
		if (rtv1->sprite.sample.is_hover)
			rtv1->tabs = SAMPLE;
		if (rtv1->sprite.x8.is_hover)
			set_format(rtv1, 8, 320, 240);
		if (rtv1->sprite.x20.is_hover)
			set_format(rtv1, 20, 854, 480);
		if (rtv1->sprite.x200.is_hover)
			set_format(rtv1, 200, 1024, 768);
		if (rtv1->sprite.x500.is_hover)
			set_format(rtv1, 500, 1280, 720);
		if (rtv1->sprite.x1000.is_hover)
			set_format(rtv1, 1000, 1400, 1050);
		if (rtv1->sprite.x5000.is_hover)
			set_format(rtv1, 5000, 1920, 1080);
		if (rtv1->sprite.close_setting.is_hover)
			return (close_settings(rtv1));
	}
	put_setting(rtv1);
	return (EXIT_SUCCESS);
}
