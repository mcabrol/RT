/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 16:30:05 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1			rtv1;

	ac = 0;
	// if (ac > 1 && check(ac, av))
	// 	return (error("usage: ./rtv1 [file.csv]"));
	// else if (ac == 1)
	// 	av[1] = "default.csv";
	init_scene(&rtv1);
	init_window(av, &rtv1);
	//init_opencl(&cl);
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
