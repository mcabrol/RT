/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:55:21 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 11:57:40 by judrion          ###   ########.fr       */
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

void 	ft_tabdel_partial(char **data, int d_allocated)
{
	while (data[d_allocated])
	{
		free(data[d_allocated]);
		d_allocated = d_allocated + 1;
	}
	free(data);
}
