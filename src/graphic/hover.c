/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 16:09:48 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		is_hover(int x, int y, t_button *button, int xmin, int xmax, int ymin, int ymax)
{
	BOOL	tmp;

	tmp = button->is_hover;
	button->is_hover = (x > xmin && x < xmax \
		&& y > ymin && y < ymax) ? TRUE : FALSE;
	return ((tmp != button->is_hover) ? TRUE : FALSE);
}

int				hover(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->sprite.setup, 90, 181, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.retry, 181, 272, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.save, 272, 362, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.display, 362, 453, 0, 80))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.render, 453, 544, 0, 80))
		put_setup(rtv1);
	return (EXIT_SUCCESS);
}

int				hover_setting(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->sprite.close_setting, 0, 92, 0, 80))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.sample, 92, 183, 0, 80))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.format, 183, 276, 0, 80))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x8, 0, 276, 79, 122))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x20, 0, 276, 122, 164))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x200, 0, 276, 164, 207))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x500, 0, 276, 207, 251))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x1000, 0, 276, 251, 294))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x5000, 0, 276, 294, 340))
		put_setting(rtv1);
	return (EXIT_SUCCESS);
}
