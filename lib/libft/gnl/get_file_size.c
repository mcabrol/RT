/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:12:54 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/18 19:22:14 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			get_file_size(const char *filename)
{
	int			i;
	int			a;
	char		buffer[BUFF_SIZE];
	int			fd;

	i = 0;
	a = 0;
	if ((fd = open(filename, O_RDONLY)) < 0 || fd > OPEN_MAX)
	{
		if (fd > 0)
			close(fd);
		return (-1);
	}
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
