/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/03 19:40:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse(int button, int x, int y, t_rtv1 *rtv1)
{
	char	*file_str;

	if (rtv1->state == SETUP)
	{
		if (button == 1 && x > 148 && x < 217 && y > 325 && y < 339)
		{
			rtv1->scene.width = 640;
			rtv1->scene.height = 480;
		}
		else if (button == 1 && x > 148 && x < 221 && y > 343 && y < 357)
		{
			rtv1->scene.width = 1280;
			rtv1->scene.height = 720;
		}
		else if (button == 1 && x > 148 && x < 254 && y > 361 && y < 375)
		{
			rtv1->scene.width = 1920;
			rtv1->scene.height = 1080;
		}
		if (button == 1 && x > 148 && x < 165 && y > 448 && y < 461)
			rtv1->scene.samples = 8;
		else if (button == 1 && x > 171 && x < 200 && y > 448 && y < 461)
			rtv1->scene.samples = 40;
		else if (button == 1 && x > 204 && x < 240 && y > 448 && y < 461)
			rtv1->scene.samples = 200;
		else if (button == 1 && x > 246 && x < 283 && y > 448 && y < 461)
			rtv1->scene.samples = 500;
		else if (button == 1 && x > 289 && x < 332 && y > 448 && y < 461)
			rtv1->scene.samples = 1000;
		else if (button == 1 && x > 156 && x < 243 && y > 527 && y < 558)
		{
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.success, 0, 0);
			pathtracer(rtv1);
			rtv1->state = RENDER;
			return (EXIT_SUCCESS);
		}
		put_setup(rtv1);
	}
	if (rtv1->state == RENDER)
	{
		if (button == 1 && x > 148 && x < 254 && y > 383 && y < 415)
			write_ppm(rtv1);
		else if (button == 1 && x > 148 && x < 254 && y > 429 && y < 459)
		{
			if (rtv1->id > MAX_WIN)
				return (EXIT_FAILURE);
			if (rtv1->id == 0)
				rtv1->image = (t_win*)ft_memalloc(sizeof(t_win) * MAX_WIN);
			if (rtv1->image)
				rtv1->image[rtv1->id] = window(rtv1->mlx_ptr, rtv1->scene.width, rtv1->scene.height, "Image");
			image(rtv1);
			(rtv1->id++);
		}
		else if (button == 1 && x > 156 && x < 243 && y > 527 && y < 558)
		{
			if (file(rtv1->ac, rtv1->av, &file_str))
				return (EXIT_FAILURE);
			init_scene(rtv1, file_str);
			rtv1->state = SETUP;
			put_setup(rtv1);
		}
	}
	return (EXIT_SUCCESS);
}
