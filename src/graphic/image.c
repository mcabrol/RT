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

	win = &rtv1->image[rtv1->id];
	screen = rtv1->render.screen;
	y = -1;
	while (++y <= rtv1->scene.height)
	{
		x = -1;
		while (++x <= rtv1->scene.width)
		{
			i = (rtv1->scene.height - 1 - y) * rtv1->scene.width + x - 1;
			put_pixel_vector(rtv1, x, rtv1->scene.height - y, &screen[i]);
		}
	}
	mlx_put_image_to_window(rtv1->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}

void 	write_ppm(t_rtv1 *rtv1)
{
	time_t	stamp;
	int 	i;
	int 	fd;
	t_scene	*scene;

	scene = &rtv1->scene;
	stamp = time(NULL);
	i = -1;
	fd = open(ft_strcat(ctime(&stamp), ".ppm"), O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_dprintf(fd, "P3\n%d %d\n%d\n", scene->width, scene->height, 255);
	while (++i < scene->width * scene->height)
		ft_dprintf(fd, "%d %d %d ", to_byte(rtv1->render.screen[i].x, GAMMA),
			                     	to_byte(rtv1->render.screen[i].y, GAMMA),
			                     	to_byte(rtv1->render.screen[i].z, GAMMA));
	close(fd);
}

void 	write_ppm_(t_rtv1 *rtv1)
{
	time_t	stamp;
	int 	i;
	int 	fd;
	t_scene	*scene;

	scene = &rtv1->scene;
	stamp = time(NULL);
	i = -1;
	fd = open(ft_strcat(ctime(&stamp), ".ppm"), O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_dprintf(fd, "P3\n%d %d\n%d\n", scene->width, scene->height, 255);
	while (++i < scene->width * scene->height)
		ft_dprintf(fd, "%d %d %d ", rtv1->render.screen[i].x,
			                     	rtv1->render.screen[i].y,
			                     	rtv1->render.screen[i].z);
	close(fd);
}
