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

	// load_button(rtv1->mlx_ptr, &sprite->error, "320x240");
	// load_button(rtv1->mlx_ptr, &sprite->error, "854x480");
	// load_button(rtv1->mlx_ptr, &sprite->error, "1024x768");
	// load_button(rtv1->mlx_ptr, &sprite->error, "1280x720");
	// load_button(rtv1->mlx_ptr, &sprite->error, "1400x1050");
	// load_button(rtv1->mlx_ptr, &sprite->error, "1920x1080");

	put_sprite(rtv1, rtv1->sprite.background);
}

// void 		init_setting(t_rtv1 *rtv1)
// {
// 	t_sprite 	*sprite;
// 	char 		*background;
// 	int 		height;
// 	int 		width;
//
// 	sprite = &rtv1->sprite;
// 	background = ft_strjoin(PATH_SPRITE, "background-setting.png");
// 	sprite->background = mlx_png_file_to_image(rtv1->mlx_ptr, background, &width, &height);
// 	free(background);
//
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "8x");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "20x");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "200x");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "500x");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "1000x");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "5000x");
//
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "320x240");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "854x480");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "1024x768");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "1280x720");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "1400x1050");
// 	load_setting(rtv1->mlx_ptr, &sprite->setup, "1920x1080");
//
// 	load_button(rtv1->mlx_ptr, &sprite->setup, "sample");
// 	load_button(rtv1->mlx_ptr, &sprite->retry, "format");
// }

void 		toggle_button(t_rtv1 *rtv1, t_button *button, BOOL status)
{
	if (status)
	{
		if (button->is_hover)
			put_sprite(rtv1, button->hover);
		else
			put_sprite(rtv1, button->active);
	}
	else
	{
		if (button->is_hover)
			put_sprite(rtv1, button->hover_disabled);
		else
			put_sprite(rtv1, button->disabled);
	}
}

void 		put_setup(t_rtv1 *rtv1)
{
	t_sprite 	*sprite;

	sprite = &rtv1->sprite;
	if (rtv1->state == SETUP)
	{
		toggle_button(rtv1, &sprite->setup, ACTIVE);
		toggle_button(rtv1, &sprite->save, DISABLE);
		toggle_button(rtv1, &sprite->display, DISABLE);
		toggle_button(rtv1, &sprite->render, ACTIVE);
	}
	else if (rtv1->state == RENDER)
	{
		toggle_button(rtv1, &sprite->setup, ACTIVE);
		toggle_button(rtv1, &sprite->save, ACTIVE);
		toggle_button(rtv1, &sprite->display, ACTIVE);
		toggle_button(rtv1, &sprite->render, DISABLE);
	}
	else
	{
		toggle_button(rtv1, &sprite->error, ACTIVE);
		toggle_button(rtv1, &sprite->close, ACTIVE);
	}
	toggle_button(rtv1, &sprite->retry, ACTIVE);
}

void 		put_setting(t_rtv1 *rtv1)
{
	rtv1->setting = window(rtv1->mlx_ptr, W_SETTING, H_SETTING, "Settings");
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.background_setting, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.close_setting.active, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.sample.active, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.format.disabled, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.x8.disabled, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.x20.active, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.x200.disabled, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.x500.disabled, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.x1000.disabled, 0, 0);
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, rtv1->sprite.x5000.disabled, 0, 0);
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
		ft_strcmp(name, "x1000") == 0 || ft_strcmp(name, "x5000") == 0)
	{
		disabled = ft_strjoin(pathname, "-disabled.png");
		button->disabled = mlx_png_file_to_image(mlx_ptr, disabled, &width, &height);
		free(disabled);
	}
	free(pathname);
}

void 	put_sprite(t_rtv1 *rtv1, void *image)
{
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, image, 0, 0);
}

void 	put_sprite_setting(t_rtv1 *rtv1, void *image)
{
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, image, 0, 0);
}
