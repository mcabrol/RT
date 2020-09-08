/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/07 21:05:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1			rtv1;

	init_session(&rtv1, ac, av);

	if (file(ac, av, &rtv1.file_str))
		return (EXIT_FAILURE);

	// Scene
	if (init_scene(&rtv1, rtv1.file_str) == EXIT_FAILURE)
		rtv1.state = ERROR;
	else
		rtv1.state = SETUP;

	// Window
	init_window(&rtv1);

	// Start session
	put_setup(&rtv1);

	// Event
	hook(&rtv1);

	// Loop
	mlx_loop(rtv1.mlx_ptr);

	return (0);
}

void 	init_session(t_rtv1 *rtv1, int ac, char **av)
{
	rtv1->ac = ac;
	rtv1->av = av;
	rtv1->id_parse = 0;
	rtv1->id_render = 0;
	rtv1->id_ppm = 0;
	rtv1->id_win = 0;
	rtv1->id_setting = 0;
	rtv1->setter = FALSE;
	rtv1->tabs = FORMAT;

	// Default scene
	rtv1->scene.samples = 8;
	rtv1->scene.width = 800;
	rtv1->scene.height = 600;
}

int		error(char *strerror)
{
	ft_dprintf(2, "%s\n", strerror);
	return (EXIT_FAILURE);
}
