/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:59:01 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/27 10:02:54 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*(haystack + i))
	{
		j = 0;
		while (*(needle + j) && *(haystack + i + j) == (*(needle + j)))
			j++;
		if (*(needle + j) == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
