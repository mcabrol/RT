/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/03 19:41:17 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1			rtv1;
	char			*file_str;

	file_str = NULL;
	rtv1.ac = ac;
	rtv1.av = av;
	rtv1.path = realpath("./", NULL);

	if (file(ac, av, &file_str))
		return (EXIT_FAILURE);

	rtv1.id_render = 0;
	rtv1.id_ppm = 0;
	rtv1.id_win = 0;

	// Default scene
	rtv1.scene.samples = 8;
	rtv1.scene.width = 640;
	rtv1.scene.height = 480;

	// Scene
	init_scene(&rtv1, file_str);

	// Window
	init_window(&rtv1);
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
