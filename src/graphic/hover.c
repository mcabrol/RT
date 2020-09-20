/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 18:42:59 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		is_hover(int x, int y, t_button *button)
{
	t_bool		tmp;
	t_position	*position;

	position = &button->position;
	tmp = button->is_hover;
	button->is_hover = (x > position->xmin && x < position->xmax \
		&& y > position->ymin && y < position->ymax) ? TRUE : FALSE;
	return ((tmp != button->is_hover) ? TRUE : FALSE);
}

int				hover(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->sprite.setup))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.retry))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.save))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.display))
		put_setup(rtv1);
	if (is_hover(x, y, &rtv1->sprite.render))
		put_setup(rtv1);
	return (EXIT_SUCCESS);
}

int				hover_setting(int x, int y, t_rtv1 *rtv1)
{
	if (is_hover(x, y, &rtv1->sprite.close_setting))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.sample))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.format))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x8))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x20))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x200))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x500))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x1000))
		put_setting(rtv1);
	if (is_hover(x, y, &rtv1->sprite.x5000))
		put_setting(rtv1);
	return (EXIT_SUCCESS);
}
