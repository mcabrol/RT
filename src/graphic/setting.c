/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 18:00:37 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			set_format(t_rtv1 *rtv1, int sample, int width, int height)
{
	if (rtv1->tabs == SAMPLE)
		rtv1->scene.samples = sample;
	else
	{
		rtv1->scene.width = width;
		rtv1->scene.height = height;
	}
}

static void		toggle_setting(t_rtv1 *rtv1, t_button *button, int a, int b)
{
	put_sprite(rtv1, (a == b) ? button->active : button->disabled, SETTING);
}

static void		put_format(t_rtv1 *rtv1)
{
	t_sprite	*sprite;

	sprite = &rtv1->sprite;
	put_sprite(rtv1, rtv1->sprite.format.active, SETTING);
	put_sprite(rtv1, rtv1->sprite.sample.disabled, SETTING);
	toggle_setting(rtv1, &sprite->f320, rtv1->scene.width, 320);
	toggle_setting(rtv1, &sprite->f854, rtv1->scene.width, 854);
	toggle_setting(rtv1, &sprite->f1024, rtv1->scene.width, 1024);
	toggle_setting(rtv1, &sprite->f1280, rtv1->scene.width, 1280);
	toggle_setting(rtv1, &sprite->f1400, rtv1->scene.width, 1400);
	toggle_setting(rtv1, &sprite->f1920, rtv1->scene.width, 1920);
}

static void		put_sample(t_rtv1 *rtv1)
{
	t_sprite	*sprite;

	sprite = &rtv1->sprite;
	put_sprite(rtv1, rtv1->sprite.format.disabled, SETTING);
	put_sprite(rtv1, rtv1->sprite.sample.active, SETTING);
	toggle_setting(rtv1, &sprite->x8, rtv1->scene.samples, 8);
	toggle_setting(rtv1, &sprite->x20, rtv1->scene.samples, 20);
	toggle_setting(rtv1, &sprite->x200, rtv1->scene.samples, 200);
	toggle_setting(rtv1, &sprite->x500, rtv1->scene.samples, 500);
	toggle_setting(rtv1, &sprite->x1000, rtv1->scene.samples, 1000);
	toggle_setting(rtv1, &sprite->x5000, rtv1->scene.samples, 5000);
}

void			put_setting(t_rtv1 *rtv1)
{
	put_sprite(rtv1, rtv1->sprite.background_setting, SETTING);
	put_sprite(rtv1, rtv1->sprite.close_setting.active, SETTING);
	if (rtv1->tabs == FORMAT)
		put_format(rtv1);
	else if (rtv1->tabs == SAMPLE)
		put_sample(rtv1);
}
