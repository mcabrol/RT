/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:04:48 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		image(t_rtv1 *rtv1)
{
	int		x;
	int		y;
	int		i;
	t_vec	*screen;
	t_win	*win;

	win = &rtv1->image;
	screen = rtv1->render.screen;
	y = 0;
	while (y <= rtv1->scene.height)
	{
		x = 0;
		while (x <= rtv1->scene.width)
		{
			i = (rtv1->scene.height - 1 - y) * rtv1->scene.width + x - 1;
			put_pixel_vector(rtv1, x, rtv1->scene.height - y, &screen[i]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rtv1->mlx_ptr, win->win_ptr,
							win->img_ptr, 0, 0);
}

void 	write_ppm(t_rtv1 *rtv1)
{
	int 	fd;
	t_vec	*screen;

	screen = rtv1->render.screen;
	fd = open(ft_strcat(ft_itoa(rand()), ".ppm"), O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_dprintf(fd, "P3\n%d %d\n%d\n", rtv1->scene.width, rtv1->scene.height, 255);
	for (int i = 0; i < rtv1->scene.width * rtv1->scene.height; ++i)
	{
		ft_dprintf(fd, "%d %d %d ", to_byte(screen[i].x, GAMMA),
			                     	to_byte(screen[i].y, GAMMA),
			                     	to_byte(screen[i].z, GAMMA));
	}
	close(fd);
}
