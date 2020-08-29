/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 17:21:48 by mcabrol          ###   ########.fr       */
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
}

int		init_image(t_rtv1 *rtv1)
{
	char	*win_name;
	char	*string_id;
	char	*tmp;

	if (rtv1->id_win > MAX_WIN)
		return (EXIT_FAILURE);
	if (rtv1->id_win == 0)
		rtv1->image = (t_win*)ft_memalloc(sizeof(t_win) * MAX_WIN);
	if (rtv1->image)
	{
		string_id = ft_itoa(rtv1->id_win);
		win_name = ft_strjoin("render - win #", string_id);
		free(string_id);
		string_id = ft_itoa(rtv1->id_render);
		tmp = win_name;
		win_name = ft_strjoin(win_name, " - render #");
		free(tmp);
		tmp = win_name;
		win_name = ft_strjoin(win_name, string_id);
		free(tmp);
		free(string_id);
		rtv1->image[rtv1->id_win] = window(rtv1->mlx_ptr, rtv1->scene.width, rtv1->scene.height, win_name);
	}
	return (EXIT_SUCCESS);
}

void 	write_ppm(t_rtv1 *rtv1)
{
	int 	i;
	int 	fd;
	t_scene	*scene;
	char 	*name;

	scene = &rtv1->scene;
	i = -1;
	name = stamp();
	fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	ft_dprintf(fd, "P3\n%d %d\n%d\n", scene->width, scene->height, 255);
	while (++i < scene->width * scene->height)
		ft_dprintf(fd, "%d %d %d ", to_byte(rtv1->screen[i].x, GAMMA),
			                     	to_byte(rtv1->screen[i].y, GAMMA),
			                     	to_byte(rtv1->screen[i].z, GAMMA));
	close(fd);
}
