/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcross.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:29:14 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 19:36:34 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		close_rcross(t_win *win)
{
	win->available = 2;
	return (0);
}

int		close_rcross_main(t_rtv1 *rtv1)
{
	clean_exit(rtv1);
	return (0);
}

int		close_rcross_s(t_rtv1 *rtv1)
{
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->setting.img_ptr);
	mlx_destroy_window(rtv1->mlx_ptr, rtv1->setting.win_ptr);
	return (0);
}
