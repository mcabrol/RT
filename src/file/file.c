/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/24 18:53:07 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		file(int ac, char **av)
{
	char 	*filename;
	int		size;

	if (ac > 1 && check(ac, av))
		return (error("usage: ./rtv1 [file.csv]"));
	else if (ac == 1)
		filename = "default.rt";
	else
		filename = av[1];
	if ((size = get_file_size(filename)) < 0)
		return (error("usage: ./rtv1 [file.csv]"));
	ft_printf("%d octet\n", size);
	return (EXIT_SUCCESS);
}

int		check(int ac, char **av)
{
	int i;

	i = ft_strlen(av[1]);
	if (ac && ac != 2)
		return (EXIT_FAILURE);
	if (i < 4 ||
		av[1][i - 3] != '.' ||
		av[1][i - 2] != 'r' ||
		av[1][i - 1] != 't')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
