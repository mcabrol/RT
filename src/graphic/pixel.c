/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/02 10:41:32 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_pixel_vector(t_rtv1 *rtv1, int x, int y, t_vec *v)
{
	t_win *win;
	int i;

	win = &rtv1->image[rtv1->id];
	i = (x * 4 + win->size_line * y);
	if (x < rtv1->scene.width)
		if (y < rtv1->scene.height)
		{
			win->data_ptr[i + 2] = (char)to_byte(v->x, GAMMA);
			win->data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			win->data_ptr[i] = (char)to_byte(v->z, GAMMA);
		}
}
