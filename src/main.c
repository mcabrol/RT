/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/24 16:33:24 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1			rtv1;

	// Checker
	if (ac > 1 && check(ac, av))
		return (error("usage: ./rtv1 [file.csv]"));
	else if (ac == 1)
		av[1] = "default.csv";

	// Scene
	init_scene(&rtv1);

	// GUI
	rtv1.scene.samples = 8;
	rtv1.scene.width = 640;
	rtv1.scene.height = 480;

	// Window
	rtv1.mlx_ptr = mlx_init();
	rtv1.main = window(rtv1.mlx_ptr, W_MAIN, H_MAIN, "Raytracer");
	rtv1.png = init_png(rtv1.mlx_ptr);
	rtv1.state = SETUP;
	put_setup(&rtv1);
	hook(&rtv1);
	mlx_loop(rtv1.mlx_ptr);
	return (0);
}

int		check(int ac, char **av)
{
	int i;

	i = ft_strlen(av[1]);
	if (ac && ac != 2)
		return (EXIT_FAILURE);
	if (i < 5 ||
		av[1][i - 4] != '.' ||
		av[1][i - 3] != 'c' ||
		av[1][i - 2] != 's' ||
		av[1][i - 1] != 'v')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		error(char *strerror)
{
	ft_dprintf(2, "%s\n", strerror);
	return (EXIT_FAILURE);
}
