/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 18:05:22 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_window(char **av, t_rtv1 *rtv1)
{
	t_win *win;

	win = &rtv1->win;
	win->mlx_ptr = mlx_init();
	if (!(win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, av[0])))
		return (EXIT_FAILURE);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->data_ptr = mlx_get_data_addr(win->img_ptr,
			&(win->bits_per_pixel),
			&(win->size_line),
			&(win->endian));
	bg_gradient(win);
	logo_center(win);
	mlx_hook(win->win_ptr, 2, 1L << 2, key, rtv1);
	mlx_loop(win->mlx_ptr);
	return (EXIT_SUCCESS);
}

int		key(int keycode, t_rtv1 *rtv1)
{
	t_win *win;

	win = &rtv1->win;
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		exit(0);
	}
	if (keycode == 36)
	{
		pathtracer(rtv1);
		bg_gradient(win);
		finish_center(win);
	}
	if (keycode == 49)
	{
		image(rtv1);
		mlx_put_image_to_window(win->mlx_ptr, win->render_win_ptr,
								win->render_img_ptr, 0, 0);
	}
	return (EXIT_SUCCESS);
}

void	erase(t_win *win)
{
	ft_bzero(win->data_ptr, HEIGHT * WIDTH * 4);
}

void	put_pixel(t_win *win, int x, int y, int color)
{
	unsigned int i;

	i = (int)(x * 4 + win->size_line * y);
	if (x <= WIDTH)
		if (y <= HEIGHT)
		{
			win->data_ptr[i] = (char)color & 0xFF;
			win->data_ptr[i + 1] = (char)(color >> 8) & 0xFF;
			win->data_ptr[i + 2] = (char)(color >> 16) & 0xFF;
		}
}

void	put_pixel_vector(t_win *win, int x, int y, t_vec *v)
{
	unsigned int i;

	i = (int)(x * 4 + win->size_line * y);
	if (x <= WIDTH)
		if (y <= HEIGHT)
		{
			win->render_data_ptr[i] = (char)to_byte(v->x, GAMMA);
			win->render_data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			win->render_data_ptr[i + 2] = (char)to_byte(v->z, GAMMA);
		}
}
