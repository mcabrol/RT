/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 17:45:14 by mcabrol          ###   ########.fr       */
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

	win = &rtv1->image[rtv1->id_win];
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
	if (rtv1->id_win > MAX_WIN)
	{
		clean_image_array(rtv1);
		return (EXIT_FAILURE);
	}
	if (rtv1->id_win == 0)
		rtv1->image = init_win_array();
	if (rtv1->image)
		display_window(rtv1);
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
