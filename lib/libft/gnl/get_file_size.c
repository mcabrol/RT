/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:12:54 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 18:10:21 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	stop(int fd)
{
	if (fd > 0)
		close(fd);
	return (-1);
}

int			get_file_size(const char *filename)
{
	int			i;
	int			a;
	char		buffer[BUFF_SIZE];
	int			fd;

	i = 0;
	a = 0;
	if ((fd = open(filename, O_RDONLY)) < 0 || fd > OPEN_MAX)
		return (stop(fd));
	while (1)
	{
		i = read(fd, buffer, BUFF_SIZE);
		if (i < BUFF_SIZE)
		{
			close(fd);
			return (a += i);
		}
		else if (i == BUFF_SIZE)
		{
			a += i;
			*buffer -= BUFF_SIZE;
		}
	}
	close(fd);
	return (0);
}
