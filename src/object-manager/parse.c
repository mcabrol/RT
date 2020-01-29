/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:25:01 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:06:33 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	printt(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_printf("tab[%d] = %s\n", i, tab[i]);
}

int		data(char *line)
{
	char **tab;

	tab = ft_strsplit(line, ',');
	printt(tab);
	return (EXIT_SUCCESS);
}

// int		parse(char **av, t_render *render)
// {
// 	int		fd;
// 	char	*line;
//
// 	render->program = av[1];
// 	if ((fd = open(render->program, O_RDONLY)) > 0)
// 		return (error("./rtv1 Open errror."));
// 	// if (order(fd, opt) == EXIT_FAILURE)
// 	// 	return (error("./rtv1 Format error."));
// 	while (get_next_line(fd, &line) > 0)
// 	{
// 		if (data(line))
// 			return (error("./rtv1 Wrong scene."));
// 		free(line);
// 	}
// 	close(fd);
// 	return (EXIT_SUCCESS);
// }
