/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/09 19:43:45 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 		init_sprite(t_rtv1 *rtv1)
{
	t_sprite 	*sprite;
	char 		*background;
	int 		height;
	int 		width;

	sprite = &rtv1->sprite;

	background = ft_strjoin(PATH_SPRITE, "background.png");
	printf("\n\nbackground : %s\n\n", background);
	sprite->background = mlx_png_file_to_image(rtv1->mlx_ptr, background, &width, &height);
	ft_bzero(background, ft_strlen(background));
	free(background);

	background = ft_strjoin(PATH_SPRITE, "background-setting.png");
	sprite->background_setting = mlx_png_file_to_image(rtv1->mlx_ptr, background, &width, &height);
	free(background);

	if (init_button(rtv1, 0))
		return (EXIT_FAILURE);

	put_sprite(rtv1, rtv1->sprite.background, MAIN);
	return (EXIT_SUCCESS);
}

void 		toggle_button(t_rtv1 *rtv1, t_button *button, BOOL status, int window)
{
	if (status)
	{
		if (button->is_hover)
			put_sprite(rtv1, button->hover, window);
		else
			put_sprite(rtv1, button->active, window);
	}
	else
	{
		if (button->is_hover)
			put_sprite(rtv1, button->hover_disabled, window);
		else
			put_sprite(rtv1, button->disabled, window);
	}
}

void 		put_setup(t_rtv1 *rtv1)
{
	t_sprite 	*sprite;

	sprite = &rtv1->sprite;
	if (rtv1->state == SETUP)
	{
		toggle_button(rtv1, &sprite->setup, ACTIVE, MAIN);
		toggle_button(rtv1, &sprite->save, DISABLE, MAIN);
		toggle_button(rtv1, &sprite->display, DISABLE, MAIN);
		toggle_button(rtv1, &sprite->render, ACTIVE, MAIN);
	}
	else if (rtv1->state == RENDER)
	{
		toggle_button(rtv1, &sprite->setup, ACTIVE, MAIN);
		toggle_button(rtv1, &sprite->save, ACTIVE, MAIN);
		toggle_button(rtv1, &sprite->display, ACTIVE, MAIN);
		toggle_button(rtv1, &sprite->render, DISABLE, MAIN);
	}
	else
	{
		toggle_button(rtv1, &sprite->error, ACTIVE, MAIN);
		toggle_button(rtv1, &sprite->close, ACTIVE, MAIN);
	}
	toggle_button(rtv1, &sprite->retry, ACTIVE, MAIN);
}

void 		toggle_setting(t_rtv1 *rtv1, t_button *button, int a, int b)
{
	put_sprite(rtv1, (a == b) ? button->active : button->disabled, SETTING);
}

void 		put_setting(t_rtv1 *rtv1)
{
	t_sprite 	*sprite;

	sprite = &rtv1->sprite;
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, sprite->background_setting, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, sprite->close_setting.active, 0, 0);
	if (rtv1->tabs == FORMAT)
	{
		put_sprite(rtv1, rtv1->sprite.format.active, SETTING);
		put_sprite(rtv1, rtv1->sprite.sample.disabled, SETTING);

		toggle_setting(rtv1, &sprite->f320, rtv1->scene.width, 320);
		toggle_setting(rtv1, &sprite->f854, rtv1->scene.width, 854);
		toggle_setting(rtv1, &sprite->f1024, rtv1->scene.width, 1024);
		toggle_setting(rtv1, &sprite->f1280, rtv1->scene.width, 1280);
		toggle_setting(rtv1, &sprite->f1400, rtv1->scene.width, 1400);
		toggle_setting(rtv1, &sprite->f1920, rtv1->scene.width, 1920);
	}
	else if (rtv1->tabs == SAMPLE)
	{
		put_sprite(rtv1, rtv1->sprite.format.disabled, SETTING);
		put_sprite(rtv1, rtv1->sprite.sample.active, SETTING);

		toggle_setting(rtv1, &sprite->x8, rtv1->scene.samples, 8);
		toggle_setting(rtv1, &sprite->x20, rtv1->scene.samples, 20);
		toggle_setting(rtv1, &sprite->x200, rtv1->scene.samples, 200);
		toggle_setting(rtv1, &sprite->x500, rtv1->scene.samples, 500);
		toggle_setting(rtv1, &sprite->x1000, rtv1->scene.samples, 1000);
		toggle_setting(rtv1, &sprite->x5000, rtv1->scene.samples, 5000);
	}
}

void 		create_setting(t_rtv1 *rtv1)
{
	if (!rtv1->id_setting)
	{
		rtv1->setting = window(rtv1->mlx_ptr, W_SETTING, H_SETTING, "Settings");
		mlx_hook(rtv1->setting.win_ptr, 6, (1L << 6), hover_setting, rtv1);
		mlx_mouse_hook(rtv1->setting.win_ptr, mouse_setting, rtv1);
		(rtv1->id_setting)++;
	}
	put_setting(rtv1);
}


void 	put_sprite(t_rtv1 *rtv1, void *image, int window)
{
	if (window == MAIN)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, image, 0, 0);
	else if (window == SETTING)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, image, 0, 0);
}
