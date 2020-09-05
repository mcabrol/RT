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

void 		init_sprite(t_rtv1 *rtv1)
{
	t_sprite 	*sprite;
	char 		*background;
	int 		height;
	int 		width;

	sprite = &rtv1->sprite;

	background = ft_strjoin(PATH_SPRITE, "background.png");
	sprite->background = mlx_png_file_to_image(rtv1->mlx_ptr, background, &width, &height);
	ft_bzero(background, ft_strlen(background));

	background = ft_strjoin(PATH_SPRITE, "background-setting.png");
	sprite->background_setting = mlx_png_file_to_image(rtv1->mlx_ptr, background, &width, &height);
	free(background);

	load_button(rtv1->mlx_ptr, &sprite->setup, "setup");
	load_button(rtv1->mlx_ptr, &sprite->close, "close");
	load_button(rtv1->mlx_ptr, &sprite->retry, "retry");
	load_button(rtv1->mlx_ptr, &sprite->save, "save");
	load_button(rtv1->mlx_ptr, &sprite->display, "display");
	load_button(rtv1->mlx_ptr, &sprite->render, "render");
	load_button(rtv1->mlx_ptr, &sprite->error, "error");

	load_button(rtv1->mlx_ptr, &sprite->sample, "sample");
	load_button(rtv1->mlx_ptr, &sprite->format, "format");
	load_button(rtv1->mlx_ptr, &sprite->close_setting, "close-setting");

	load_button(rtv1->mlx_ptr, &sprite->x8, "x8");
	load_button(rtv1->mlx_ptr, &sprite->x20, "x20");
	load_button(rtv1->mlx_ptr, &sprite->x200, "x200");
	load_button(rtv1->mlx_ptr, &sprite->x500, "x500");
	load_button(rtv1->mlx_ptr, &sprite->x1000, "x1000");
	load_button(rtv1->mlx_ptr, &sprite->x5000, "x5000");

	load_button(rtv1->mlx_ptr, &sprite->f320, "320x240");
	load_button(rtv1->mlx_ptr, &sprite->f854, "854x480");
	load_button(rtv1->mlx_ptr, &sprite->f1024, "1024x768");
	load_button(rtv1->mlx_ptr, &sprite->f1280, "1280x720");
	load_button(rtv1->mlx_ptr, &sprite->f1400, "1400x1050");
	load_button(rtv1->mlx_ptr, &sprite->f1920, "1920x1080");

	put_sprite(rtv1, rtv1->sprite.background, MAIN);
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

void 		load_button(void *mlx_ptr, t_button *button, char *name)
{
	int width;
	int height;

	char *pathname;

	char *active;
	char *hover;
	char *disabled;
	char *hover_disabled;

	button->is_active = FALSE;
	button->is_hover = FALSE;

	pathname = ft_strjoin(PATH_SPRITE, name);

	active = ft_strjoin(pathname, ".png");
	button->active = mlx_png_file_to_image(mlx_ptr, active, &width, &height);
	free(active);

	if (ft_strcmp(name, "retry") == 0 || ft_strcmp(name, "setup") == 0)
	{
		hover = ft_strjoin(pathname, "-hover.png");
		button->hover = mlx_png_file_to_image(mlx_ptr, hover, &width, &height);
		free(hover);
	}

	if (ft_strcmp(name, "render") == 0 ||
		ft_strcmp(name, "save") == 0 ||
		ft_strcmp(name, "display") == 0 ||
		ft_strcmp(name, "save") == 0)
	{
		disabled = ft_strjoin(pathname, "-disabled.png");
		button->disabled = mlx_png_file_to_image(mlx_ptr, disabled, &width, &height);
		free(disabled);

		hover = ft_strjoin(pathname, "-hover.png");
		button->hover = mlx_png_file_to_image(mlx_ptr, hover, &width, &height);
		free(hover);

		hover_disabled = ft_strjoin(pathname, "-hover-disabled.png");
		button->hover_disabled = mlx_png_file_to_image(mlx_ptr, hover_disabled, &width, &height);
		free(hover_disabled);
	}

	if (ft_strcmp(name, "sample") == 0 ||
		ft_strcmp(name, "format") == 0)
	{
		disabled = ft_strjoin(pathname, "-disabled.png");
		button->disabled = mlx_png_file_to_image(mlx_ptr, disabled, &width, &height);
		free(disabled);
	}

	if (ft_strcmp(name, "sample") == 0 || ft_strcmp(name, "format") == 0 ||
		ft_strcmp(name, "x8") == 0 || ft_strcmp(name, "x20") == 0 ||
		ft_strcmp(name, "x200") == 0 || ft_strcmp(name, "x500") == 0 ||
		ft_strcmp(name, "x1000") == 0 || ft_strcmp(name, "x5000") == 0 ||
		ft_strcmp(name, "320x240") == 0 || ft_strcmp(name, "854x480") == 0 ||
		ft_strcmp(name, "1024x768") == 0 || ft_strcmp(name, "1280x720") == 0 ||
		ft_strcmp(name, "1400x1050") == 0 || ft_strcmp(name, "1920x1080") == 0)
	{
		disabled = ft_strjoin(pathname, "-disabled.png");
		button->disabled = mlx_png_file_to_image(mlx_ptr, disabled, &width, &height);
		free(disabled);
	}
	free(pathname);
}

void 	put_sprite(t_rtv1 *rtv1, void *image, int window)
{
	if (window == MAIN)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, image, 0, 0);
	else if (window == SETTING)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, image, 0, 0);
}
