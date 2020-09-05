/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/03 20:06:13 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		retry_is_hover(t_rtv1 *rtv1)
{
	if (rtv1->state == SETUP || rtv1->state == ERROR)
	{
		if (rtv1->state == ERROR)
			rtv1->setter = FALSE;
		ft_bzero(rtv1->file_str, ft_strlen(rtv1->file_str));
		file(rtv1->ac, rtv1->av, &rtv1->file_str);
		if (init_scene(rtv1, rtv1->file_str) == EXIT_FAILURE)
			rtv1->state = ERROR;
		else
			rtv1->state = SETUP;
	}
	else if (rtv1->state == RENDER)
	{
		free_texture(&rtv1->scene);
		ft_bzero(rtv1->screen, rtv1->scene.height * rtv1->scene.width);
		if (rtv1->scene.obj != NULL)
			free(rtv1->scene.obj);
		rtv1->state = SETUP;
	}
	return (EXIT_SUCCESS);
}

static int		render_is_hover(t_rtv1 *rtv1)
{
	if (rtv1->state == SETUP)
	{
		retry_is_hover(rtv1);
		rtv1->state = RENDER;
		render_is_hover(rtv1);
	}
	else if (rtv1->state == RENDER)
	{
		if (render(rtv1))
			return (EXIT_FAILURE);
		(rtv1->id_render)++;
	}
	return (EXIT_SUCCESS);
}

int		mouse(int button, int x, int y, t_rtv1 *rtv1)
{
	int		error;

	x = 0;
	y = 0;
	if (button == 1)
	{
		if (rtv1->sprite.retry.is_hover)
			error = retry_is_hover(rtv1);
		if (rtv1->sprite.render.is_hover)
			error = render_is_hover(rtv1);
		if (rtv1->sprite.save.is_hover)
		{
			write_ppm(rtv1);
			(rtv1->id_ppm)++;
		}
		if (rtv1->sprite.display.is_hover)
		{
			if (init_image(rtv1))
				return (EXIT_FAILURE);
			image(rtv1);
			(rtv1->id_win)++;
		}
		if (rtv1->sprite.setup.is_hover && rtv1->state == ERROR)
			clean_exit(rtv1);
		if (rtv1->sprite.setup.is_hover && rtv1->state == SETUP)
			create_setting(rtv1);
	}
	put_setup(rtv1);
	return (EXIT_SUCCESS);
}

void 	set_format(t_rtv1 *rtv1, int sample, int width, int height)
{
	if (rtv1->tabs == SAMPLE)
		rtv1->scene.samples = sample;
	else
	{
		rtv1->scene.width = width;
		rtv1->scene.height = height;
	}
}

int 	close_settings(t_rtv1 *rtv1)
{
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->setting.img_ptr);
	mlx_destroy_window(rtv1->mlx_ptr, rtv1->setting.win_ptr);
	(rtv1->id_setting)--;
	return (EXIT_SUCCESS);
}

int		mouse_setting(int button, int x, int y, t_rtv1 *rtv1)
{
	x = 0;
	y = 0;
	if (button == 1)
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
	put_setting(rtv1);
	return (EXIT_SUCCESS);
}

void 		format(t_rtv1 *rtv1, int width, int height)
{
	rtv1->scene.width = width;
	rtv1->scene.height = height;
}
