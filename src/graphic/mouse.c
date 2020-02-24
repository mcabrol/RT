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

int		mouse(int button, int x, int y, t_rtv1 *rtv1)
{
	// ft_dprintf(1, "%d, %d, %d\n", button, x, y);
	if (rtv1->state == SETUP)
	{
		if (button == 1 && x > 148 && x < 217 && y > 325 && y < 339)
		{
			rtv1->scene.width = 640;
			rtv1->scene.height = 480;
		}
		if (button == 1 && x > 148 && x < 221 && y > 343 && y < 357)
		{
			rtv1->scene.width = 1280;
			rtv1->scene.height = 720;
		}
		if (button == 1 && x > 148 && x < 254 && y > 361 && y < 375)
		{
			rtv1->scene.width = 1920;
			rtv1->scene.height = 1080;
		}
		if (button == 1 && x > 148 && x < 165 && y > 448 && y < 461)
			rtv1->scene.samples = 8;
		if (button == 1 && x > 171 && x < 200 && y > 448 && y < 461)
			rtv1->scene.samples = 40;
		if (button == 1 && x > 204 && x < 240 && y > 448 && y < 461)
			rtv1->scene.samples = 200;
		if (button == 1 && x > 246 && x < 283 && y > 448 && y < 461)
			rtv1->scene.samples = 500;
		if (button == 1 && x > 289 && x < 332 && y > 448 && y < 461)
			rtv1->scene.samples = 1000;
		if (button == 1 && x > 156 && x < 243 && y > 527 && y < 558)
		{
			pathtracer(rtv1);
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.success, 0, 0);
			rtv1->state = RENDER;
			return (EXIT_SUCCESS);
		}
		put_setup(rtv1);
	}
	if (rtv1->state == RENDER)
	{
		if (button == 1 && x > 102 && x < 189 && y > 528 && y < 569)
		{
			write_ppm(rtv1);
		}
		if (button == 1 && x > 211 && x < 298 && y > 528 && y < 569)
		{
			rtv1->state = SETUP;
			put_setup(rtv1);
		}
	}
	return (EXIT_SUCCESS);
}
