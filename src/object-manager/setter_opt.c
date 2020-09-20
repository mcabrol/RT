/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 19:09:12 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	**get_opt(const char *filename)
{
	int		fd;
	int		size;
	char	**data;
	char	*str;

	if ((size = get_file_size(filename)) < 0)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((str = (char *)ft_memalloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	if ((read(fd, str, size - 1)) == 0)
		return (NULL);
	close(fd);
	data = ft_strsplit(str, ' ');
	free(str);
	return (data);
}

char	*get_opt_str(const char *filename)
{
	int		fd;
	int		size;
	char	*str;

	if ((size = get_file_size(filename)) < 0)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((str = (char *)ft_memalloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	if ((read(fd, str, size - 1)) == 0)
		return (NULL);
	close(fd);
	return (str);
}
