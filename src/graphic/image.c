/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 14:09:32 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				image(t_rtv1 *rtv1)
{
	int		x;
	int		y;
	int		i;
	t_vec	*screen;
	t_win	*win;

	win = &rtv1->image[rtv1->id_win_to_print];
	screen = rtv1->screen;
	y = -1;
	while (++y <= rtv1->scene.height)
	{
		x = -1;
		while (++x <= rtv1->scene.width)
		{
			i = (rtv1->scene.height - 1 - y) * rtv1->scene.width + x;
			put_pixel_vector(rtv1, x, y, &screen[i]);
		}
	}
	mlx_put_image_to_window(rtv1->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
	return (1);
}

int				init_image(t_rtv1 *rtv1)
{
	if (rtv1->id_win == MAX_WIN)
	{
		clean_image_array(rtv1);
		rtv1->state = RENDER;
	}
	if (rtv1->id_win == 0 && !rtv1->image)
		rtv1->image = init_win_array();
	if (rtv1->image)
	{
		if (display_window(rtv1) == EXIT_FAILURE)
		{
			throw_error(NO_WIN_AVAILABLE);
			rtv1->state = ERROR;
			return (EXIT_FAILURE);
		}
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				write_ppm(t_rtv1 *rtv1)
{
	int		x;
	int		y;
	int		i;
	int		fd;
	char	*name;

	y = -1;
	name = stamp();
	fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_dprintf(fd, "P3\n%d %d\n%d\n", rtv1->scene.width, rtv1->scene.height,\
	255);
	while (++y < rtv1->scene.height)
	{
		x = -1;
		while (++x < rtv1->scene.width)
		{
			i = (rtv1->scene.height - 1 - y) * rtv1->scene.width + x;
			ft_dprintf(fd, "%d %d %d ", to_byte(rtv1->screen[i].x, GAMMA),
											to_byte(rtv1->screen[i].y, GAMMA),
											to_byte(rtv1->screen[i].z, GAMMA));
		}
	}
	close(fd);
	return (1);
}
