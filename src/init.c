/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:00:36 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 20:27:06 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	init_window(t_window *window)
{
	window->position.x = 0;
	window->position.y = 0;
	window->size.x = HEIGHT;
	window->size.y = WIDTH;
	window->flags = SDL_WINDOW_SHOWN | SDL_WINDOW_POPUP_MENU;
	return (1);
}
