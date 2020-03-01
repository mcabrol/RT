/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 10:42:08 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1			rtv1;
	//
	// // Checker
	// if (file(ac, av, &rtv1.scene))
	// 	return (EXIT_FAILURE);
	if (ac)
		ft_printf("ac - %s", av[0]);
	// Default scene
	rtv1.scene.samples = 8;
	rtv1.scene.width = 640;
	rtv1.scene.height = 480;

	// Scene
	init_scene(&rtv1);

	// Window
	rtv1.mlx_ptr = mlx_init();
	rtv1.main = window(rtv1.mlx_ptr, W_MAIN, H_MAIN, "Raytracer");
	rtv1.png = init_png(rtv1.mlx_ptr);
	rtv1.state = SETUP;
	rtv1.png.h_render = FALSE;
	rtv1.png.h_cancel = FALSE;
	rtv1.png.h_save = FALSE;
	rtv1.png.h_show = FALSE;
	rtv1.id = 0;
	put_setup(&rtv1);
	hook(&rtv1);
	mlx_loop(rtv1.mlx_ptr);
	return (0);
}

int		error(char *strerror)
{
	ft_dprintf(2, "%s\n", strerror);
	return (EXIT_FAILURE);
}
