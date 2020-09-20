/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:55:21 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 18:05:58 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	ft_tabdel_partial(char **data, int d_allocated)
{
	int		i;

	i = 0;
	while (i < d_allocated)
	{
		free(data[i]);
		i = i + 1;
	}
	if (data)
		free(data);
}
