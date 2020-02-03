/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 19:16:35 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_window(char **av, t_render *render)
{
	render->win.mlx_ptr = mlx_init();
	if (!(render->win.win_ptr = mlx_new_window(render->win.mlx_ptr, WIDTH, HEIGHT, av[0])))
		return (EXIT_FAILURE);
	render->win.img_ptr = mlx_new_image(render->win.mlx_ptr, WIDTH, HEIGHT);
	render->win.data_ptr = mlx_get_data_addr(render->win.img_ptr,
			&(render->win.bits_per_pixel),
			&(render->win.size_line),
			&(render->win.endian));
	// bg_gradient(render);
	// logo_center(render);
	mlx_hook(render->win.win_ptr, 2, 1L << 2, key, render);
	mlx_loop(render->win.mlx_ptr);
	return (EXIT_SUCCESS);
}

int		key(int keycode, t_render *render)
{
	if (keycode == 53)
	{
		mlx_destroy_window(render->win.mlx_ptr, render->win.win_ptr);
		exit(0);
	}
	if (keycode == 36)
	{
		rtv1(render);
		image(render);
	}
	// erase(render);
	return (EXIT_SUCCESS);
}

void	erase(t_render *render)
{
	ft_bzero(render->win.data_ptr, HEIGHT * WIDTH * 4);
}

void	put_pixel_vector(t_render *render, int x, int y, t_vec *v)
{
	unsigned int i;

	i = (int)(x * 4 + render->win.size_line * y);
	if (x <= WIDTH && x >= 0)
		if (y <= HEIGHT && y >= 0)
		{
			render->win.data_ptr[i] = (char)to_byte(v->x, GAMMA);
			render->win.data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			render->win.data_ptr[i + 2] = (char)to_byte(v->z, GAMMA);
		}
}

void	put_pixel(t_render *render, int x, int y, int color)
{
	unsigned int i;

	i = (int)(x * 4 + render->win.size_line * y);
	if (x <= WIDTH && x >= 0)
		if (y <= HEIGHT && y >= 0)
		{
			render->win.data_ptr[i] = (char)color & 0xFF;
			render->win.data_ptr[i + 1] = (char)(color >> 8) & 0xFF;
			render->win.data_ptr[i + 2] = (char)(color >> 16) & 0xFF;
		}
}
