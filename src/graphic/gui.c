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

	// png.background = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/background.png", &width, &height);
	// png.success = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/success.png", &width, &height);
	// png.failure = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/failure.png", &width, &height);
	// png.render = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/render.png", &width, &height);
	// png.cancel = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/cancel.png", &width, &height);
	// png.save = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/save.png", &width, &height);
	// png.show = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/show.png", &width, &height);
	// png.f480 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/480p.png", &width, &height);
	// png.f720 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/720p.png", &width, &height);
	// png.f1080 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/1080p.png", &width, &height);
	// png.s8 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/8s.png", &width, &height);
	// png.s40 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/40s.png", &width, &height);
	// png.s200 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/200s.png", &width, &height);
	// png.s500 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/500s.png", &width, &height);
	// png.s1000 = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/img/1000s.png", &width, &height);

	// New version

	// Normal
	png.background = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/background.png", &width, &height);
	png.setup = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/setup.png", &width, &height);
	png.close = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/close.png", &width, &height);
	png.retry = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/retry.png", &width, &height);
	png.save = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/save.png", &width, &height);
	png.display = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/display.png", &width, &height);
	png.render = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/render.png", &width, &height);
	png.error = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/error.png", &width, &height);

	// Hover
	png.setup_hover = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/setup-hover.png", &width, &height);
	png.retry_hover = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/retry-hover.png", &width, &height);
	png.close_hover = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/close-hover.png", &width, &height);
	png.save_hover = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/save-hover.png", &width, &height);
	png.display_hover = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/display-hover.png", &width, &height);
	png.render_hover = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/render-hover.png", &width, &height);

	// Disabled
	png.save_disabled = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/save-disabled.png", &width, &height);
	png.display_disabled = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/display-disabled.png", &width, &height);
	png.render_disabled = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/render-disabled.png", &width, &height);

	// Hover Disabled
	png.save_hover_disabled = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/save-hover-disabled.png", &width, &height);
	png.display_hover_disabled = mlx_png_file_to_image(mlx_ptr, "/Users/Famille/Documents/Martin/rtv1/sprite/display-hover-disabled.png", &width, &height);


	return (png);
}

void 		put_setup(t_rtv1 *rtv1)
{
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.background, 0, 0);

	if (rtv1->state == SETUP)
	{
		if (rtv1->png.setup_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.setup_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.setup, 0, 0);

		if (rtv1->png.save_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.save_hover_disabled, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.save_disabled, 0, 0);

		if (rtv1->png.display_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.display_hover_disabled, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.display_disabled, 0, 0);

		if (rtv1->png.render_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.render_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.render, 0, 0);
	}
	else if (rtv1->state == RENDER)
	{
		if (rtv1->png.setup_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.setup_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.setup, 0, 0);

		if (rtv1->png.save_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.save_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.save, 0, 0);

		if (rtv1->png.display_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.display_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.display, 0, 0);

		if (rtv1->png.render_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.render_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.render_disabled, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.error, 0, 0);
		if (rtv1->png.setup_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.close_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.close, 0, 0);

		if (rtv1->png.retry_is_hover)
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.retry_hover, 0, 0);
		else
			mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.retry, 0, 0);
	}

	// Retry
	if (rtv1->png.retry_is_hover)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.retry_hover, 0, 0);
	else
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, rtv1->png.retry, 0, 0);


}
