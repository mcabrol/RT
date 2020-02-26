/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/26 18:51:38 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	hook(t_rtv1 *rtv1)
{
	t_win *main;
	t_win *image;

	main = &rtv1->main;
	image = &rtv1->image;
	mlx_hook(main->win_ptr, 2, 1L << 2, key, rtv1);
	mlx_hook(main->win_ptr, 6, (1L << 6), hover, rtv1);
	mlx_mouse_hook(main->win_ptr, mouse, rtv1);
}

int 	hover(int x, int y, t_rtv1 *rtv1)
{
	int state;

	if (rtv1->state == SETUP)
	{
		state = rtv1->png.hover;
		if (x > 156 && x < 243 && y > 527 && y < 558)
			rtv1->png.hover = TRUE;
		else
			rtv1->png.hover = FALSE;
		if (state != rtv1->png.hover)
		{
			ft_printf("%s\n", rtv1->png.hover ? "TRUE" : "FALSE");
			put_setup(rtv1);
		}
	}
	return (EXIT_SUCCESS);
}
