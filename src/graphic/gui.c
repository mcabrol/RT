/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 18:42:53 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					init_sprite(t_rtv1 *rtv1)
{
	t_sprite	*sprite;

	sprite = &rtv1->sprite;
	if ((sprite->background = load(rtv1, PATH_SPRITE,\
		"background.png")) == NULL)
		return (EXIT_FAILURE);
	if ((sprite->background_setting = load(rtv1, PATH_SPRITE,\
		"background-setting.png")) == NULL)
		return (EXIT_FAILURE);
	if (init_button(rtv1, 0))
		return (EXIT_FAILURE);
	put_sprite(rtv1, rtv1->sprite.background, MAIN);
	return (EXIT_SUCCESS);
}

void				put_setup(t_rtv1 *rtv1)
{
	t_sprite	*sprite;

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

void				toggle_button(t_rtv1 *rtv1, t_button *button, t_bool status)
{
	if (status)
	{
		if (button->is_hover)
			put_sprite(rtv1, button->hover, MAIN);
		else
			put_sprite(rtv1, button->active, MAIN);
	}
	else
	{
		if (button->is_hover)
			put_sprite(rtv1, button->hover_disabled, MAIN);
		else
			put_sprite(rtv1, button->disabled, MAIN);
	}
}

void				put_sprite(t_rtv1 *rtv1, void *image, int window)
{
	if (window == MAIN)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->main.win_ptr, image, 0, 0);
	else if (window == SETTING)
		mlx_put_image_to_window(rtv1->mlx_ptr, rtv1->setting.win_ptr, image,\
			0, 0);
}
