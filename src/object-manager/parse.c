/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:25:01 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/22 15:56:09 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "rtv1.h"
//
// void 	printt(char **tab)
// {
// 	int i;
//
// 	i = -1;
// 	while (tab[++i])
// 		ft_printf("tab[%d] = %s\n", i, tab[i]);
// }
//
// int		parse(char **av, t_rtv1 *rtv1)
// {
// 	int		fd;
// 	int		opt[OPT];
// 	char	*line;
// 	t_obj	*obj;
//
// 	if ((fd = open(file_name, O_RDONLY)) > 0)
// 		return (error("./rtv1 Open errror."));
// 	if (order(fd, opt) == EXIT_FAILED)
// 		return (error("./rtv1 Format error."));
// 	while (get_next_line(fd, &line, 0) > 0)
// 	{
// 		if ((obj = data(line, type)) == NULL)
// 			return (error("./rtv1 Format error."));
// 		if (obj->type == T_LIGHT && array_add(param->list_light, (void*)obj) == KO)
// 			return (error("./rtv1 Format error."));
// 		if (array_add(param->list_obj, (void*)obj) == KO)
// 			return (error("./rtv1 Malloc error."));
// 	}
// 	close(fd);
// 	return (EXIT_SUCCESS);
// }
//
// int		order(int fd, int opt[OPT])
// {
// 	int		i;
// 	int		type;
// 	char	*line;
// 	char	**data;
//
// 	if (get_next_line(fd, &line, 0) > 0)
// 		return (EXIT_FAILURE);
// 	if ((data = ft_strsplit(line, ',')) == NULL)
// 		return (EXIT_FAILURE);
// 	i = -1;
// 	type = 0;
// 	while (data[++i])
// 	{
// 		if (ft_strequ(data[i], "TYPE"))
// 			opt[type++] = TYPE;
// 		else if (ft_strequ(data[i], "X") && (p_type[i_type++] = P_CENTER))
// 			i += 2;
// 		else if (ft_strequ(data[i], "NX") && (p_type[i_type++] = P_NORMAL))
// 			i += 2;
// 		else if (ft_strequ(data[i], "R") && (p_type[i_type++] = P_COLOR))
// 			i += 2;
// 		else if (ft_strequ(data[i], "RADIUS") && (p_type[i_type++] = P_SIZE))
// 			i += 1;
// 		else if (ft_strequ(data[i], "REFLEXION") && (p_type[i_type++] = P_MATERIAL))
// 			i += 2;
// 	}
// 	free_tab(data);
// 	return (EXIT_SUCCESS);
// }
