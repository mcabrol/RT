/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:05:19 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/06 20:21:16 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *end;

	end = ft_memccpy(dst, src, 0, len);
	if (dst + len > end && end != NULL)
		ft_bzero(end, (dst + len) - end);
	return (dst);
}
