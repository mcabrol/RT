/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/10 14:34:16 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sprite 		init_sprite(void *mlx_ptr)
{
	t_sprite png;
	int width;
	int height;

	png.background = mlx_png_file_to_image(mlx_ptr, "img/background.png", &width, &height);
	png.success = mlx_png_file_to_image(mlx_ptr, "img/success.png", &width, &height);
	png.failure = mlx_png_file_to_image(mlx_ptr, "img/failure.png", &width, &height);
	png.render = mlx_png_file_to_image(mlx_ptr, "img/render.png", &width, &height);
	png.cancel = mlx_png_file_to_image(mlx_ptr, "img/cancel.png", &width, &height);
	png.save = mlx_png_file_to_image(mlx_ptr, "img/save.png", &width, &height);
	png.show = mlx_png_file_to_image(mlx_ptr, "img/show.png", &width, &height);
	png.f480 = mlx_png_file_to_image(mlx_ptr, "img/480p.png", &width, &height);
	png.f720 = mlx_png_file_to_image(mlx_ptr, "img/720p.png", &width, &height);
	png.f1080 = mlx_png_file_to_image(mlx_ptr, "img/1080p.png", &width, &height);
	png.s8 = mlx_png_file_to_image(mlx_ptr, "img/8s.png", &width, &height);
	png.s40 = mlx_png_file_to_image(mlx_ptr, "img/40s.png", &width, &height);
	png.s200 = mlx_png_file_to_image(mlx_ptr, "img/200s.png", &width, &height);
	png.s500 = mlx_png_file_to_image(mlx_ptr, "img/500s.png", &width, &height);
	png.s1000 = mlx_png_file_to_image(mlx_ptr, "img/1000s.png", &width, &height);
	return (png);
}

void 		put_setup(t_rtv1 *rtv1)
{
	if (rtv1->state == SETUP)
	{
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.background, 0, 0);
		if (rtv1->scene.width == 640 && rtv1->scene.height == 480)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.f480, 0, 0);
		else if (rtv1->scene.width == 1280 && rtv1->scene.height == 720)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.f720, 0, 0);
		else if (rtv1->scene.width == 1920 && rtv1->scene.height == 1080)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.f1080, 0, 0);
		if (rtv1->scene.samples == 8)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.s8, 0, 0);
		else if (rtv1->scene.samples == 40)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.s40, 0, 0);
		else if (rtv1->scene.samples == 200)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.s200, 0, 0);
		else if (rtv1->scene.samples == 500)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.s500, 0, 0);
		else if (rtv1->scene.samples == 1000)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.s1000, 0, 0);
		if (rtv1->png.h_render == TRUE)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.render, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.success, 0, 0);
		if (rtv1->png.h_cancel == TRUE)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.cancel, 0, 0);
		if (rtv1->png.h_save == TRUE)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.save, 0, 0);
		if (rtv1->png.h_show == TRUE)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.show, 0, 0);
	}
}
