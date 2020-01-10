/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		ft_printf("Erreur d'initialisation de la SDL");
		exit(EXIT_FAILURE);
	}
	SDL_Quit();
	ft_printf("Libft ok\n");
	init();
	return (EXIT_SUCCESS);

}
