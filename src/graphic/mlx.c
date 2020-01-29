/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:01:01 by mcabrol          ###   ########.fr       */
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
	mlx_hook(render->win.win_ptr, 2, 1L << 2, key, render);
	mlx_expose_hook(render->win.win_ptr, expose_hook, render);
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
	erase(render);
	return (EXIT_SUCCESS);
}

void	erase(t_render *render)
{
	ft_bzero(render->win.data_ptr, HEIGHT * WIDTH * 4);
	expose_hook(render);
}

int		expose_hook(t_render *render)
{
	rtv1(render);
	// multithread(render);
	mlx_put_image_to_window(render->win.mlx_ptr, render->win.win_ptr, render->win.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

void	put_pixel(t_render *render, int x, int y, t_vec *v)
{
	unsigned int i;

	i = (int)(x * 4 + render->win.size_line * y);
	if ((unsigned int)x < WIDTH && (unsigned int)x > 0)
		if ((unsigned int)y < HEIGHT && (unsigned int)y > 0)
		{
			//ft_printf("%d %d %d\n", to_byte(v->x, GAMMA), to_byte(v->y, GAMMA), to_byte(v->z, GAMMA));
			render->win.data_ptr[i] = (char)to_byte(v->x, GAMMA);
			render->win.data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			render->win.data_ptr[i + 2] = (char)to_byte(v->z, GAMMA);
		}
}
