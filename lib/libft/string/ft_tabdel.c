/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:55:21 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/21 19:07:31 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		if (tab[i])
			free(tab[i]);
	}
	if (tab)
		free(tab);
}

void	ft_tabdel_partial(char **data, int d_allocated)
{
	int		i;

	i = 0;
	while (i < d_allocated)
	{
		if (data[i])
			free(data[i]);
		i = i + 1;
	}
	if (data)
		free(data);
}
