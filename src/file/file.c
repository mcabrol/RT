/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 11:16:10 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		file(int ac, char **av, char **file_str)
{
	char 	*filename;
	int 	fd;
	int		size;

	if (ac > 1 && check(ac, av))
		return (error("usage: ./rtv1 [file.csv]"));
	else if (ac == 1)
		filename = "scenes/default.rt";
	else
		filename = av[1];
	if ((size = get_file_size(filename)) < 0)
		return (error("usage: ./rtv1 [file.rt]"));
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (error("usage: ./rtv1 [file.rt]"));
	if ((*file_str = (char *)malloc(sizeof(char) * (size))) == NULL)
		return (error("usage: ./rtv1 [file.rt]"));
	read(fd, *file_str, size);
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
