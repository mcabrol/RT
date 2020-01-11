/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 23:22:40 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

#include "../libft/inc/libft.h"
#include "../SDL2-2.0.10/include/SDL.h"

#define HEIGHT	400
#define WIDTH	400

typedef struct		s_point
{

	int				x;
	int				y;
}					t_point;

typedef struct		s_window
{

	t_point			position;
	t_point			size;
	Uint32			flags;
	SDL_Window		*ptr;
	SDL_Renderer 	*render;
}					t_window;

/*
**	window.c
*/

int					init_window(t_window *window);
int					create_window(const char *title, t_window *w);



#endif
