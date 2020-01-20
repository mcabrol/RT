/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 14:43:07 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_window(char **av, t_rtv1 *rtv1)
{
	rtv1->win.mlx_ptr = mlx_init();
	if (!(rtv1->win.win_ptr = mlx_new_window(rtv1->win.mlx_ptr, WIDTH, HEIGHT, av[0])))
		return (EXIT_FAILURE);
	rtv1->win.img_ptr = mlx_new_image(rtv1->win.mlx_ptr, WIDTH, HEIGHT);
	rtv1->win.data_ptr = mlx_get_data_addr(rtv1->win.img_ptr,
			&(rtv1->win.bits_per_pixel),
			&(rtv1->win.size_line),
			&(rtv1->win.endian));
	mlx_hook(rtv1->win.win_ptr, 2, 1L << 2, key, rtv1);
	mlx_expose_hook(rtv1->win.win_ptr, expose_hook, rtv1);
	mlx_loop(rtv1->win.mlx_ptr);
	return (EXIT_SUCCESS);
}

int		key(int keycode, t_rtv1 *rtv1)
{
	if (keycode == 53)
	{
		mlx_destroy_window(rtv1->win.mlx_ptr, rtv1->win.win_ptr);
		exit(0);
	}
	erase(rtv1);
	return (EXIT_SUCCESS);
}

void	erase(t_rtv1 *rtv1)
{
	ft_bzero(rtv1->win.data_ptr, HEIGHT * WIDTH * 4);
	expose_hook(rtv1);
}

int		expose_hook(t_rtv1 *rtv1)
{
	rt(rtv1);
	mlx_put_image_to_window(rtv1->win.mlx_ptr, rtv1->win.win_ptr, rtv1->win.img_ptr, 0, 0);
	return (EXIT_SUCCESS);
}

void	put_pixel(t_rtv1 *rtv1, int x, int y, t_vec *v)
{
	unsigned int i;

	i = (int)(x * 4 + rtv1->win.size_line * y);
	if ((unsigned int)x < WIDTH && (unsigned int)x > 0)
		if ((unsigned int)y < HEIGHT && (unsigned int)y > 0)
		{
			//ft_printf("%d %d %d\n", to_byte(v->x, GAMMA), to_byte(v->y, GAMMA), to_byte(v->z, GAMMA));
			rtv1->win.data_ptr[i] = (char)to_byte(v->x, GAMMA);
			rtv1->win.data_ptr[i + 1] = (char)to_byte(v->y, GAMMA);
			rtv1->win.data_ptr[i + 2] = (char)to_byte(v->z, GAMMA);
		}
}
