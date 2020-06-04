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
	free(background);

	load_button(rtv1->mlx_ptr, &sprite->setup, "setup");
	load_button(rtv1->mlx_ptr, &sprite->close, "close");
	load_button(rtv1->mlx_ptr, &sprite->retry, "retry");
	load_button(rtv1->mlx_ptr, &sprite->save, "save");
	load_button(rtv1->mlx_ptr, &sprite->display, "display");
	load_button(rtv1->mlx_ptr, &sprite->render, "render");
	load_button(rtv1->mlx_ptr, &sprite->error, "error");
	put_sprite(rtv1, sprite->background);
}

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

	if (ft_strcmp(name, "error") != 0)
	{
		hover = ft_strjoin(pathname, "-hover.png");
		button->hover = mlx_png_file_to_image(mlx_ptr, hover, &width, &height);
		free(hover);
	}

	if (ft_strcmp(name, "render") == 0 ||
		ft_strcmp(name, "display") == 0 ||
		ft_strcmp(name, "save") == 0)
	{
		disabled = ft_strjoin(pathname, "-disabled.png");
		button->disabled = mlx_png_file_to_image(mlx_ptr, disabled, &width, &height);
		free(disabled);

		hover_disabled = ft_strjoin(pathname, "-hover-disabled.png");
		button->hover_disabled = mlx_png_file_to_image(mlx_ptr, hover_disabled, &width, &height);
		free(hover_disabled);
	}
	free(pathname);
}

void 	put_sprite(t_rtv1 *rtv1, void *image)
{
	mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, image, 0, 0);
}
