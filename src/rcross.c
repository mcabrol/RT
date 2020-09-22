/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcross.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:29:14 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 14:52:44 by judrion          ###   ########.fr       */
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
	close_settings(rtv1);
	return (0);
}
