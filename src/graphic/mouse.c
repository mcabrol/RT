/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/03 20:06:13 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse(int button, int x, int y, t_rtv1 *rtv1)
{
	char	*file_str;

	file_str = NULL;
	ft_printf("%d %d : %d", x, y, button);
	if (button == 1 && rtv1->png.retry_is_hover)
	{
		free_texture(&rtv1->scene);
		if (rtv1->state == RENDER)
		{
			free(rtv1->scene.obj);
			free(rtv1->screen);
		}
		file(rtv1->ac, rtv1->av, &file_str);
		if (init_scene(rtv1, file_str) == EXIT_FAILURE)
			rtv1->state = ERROR;
		else
			rtv1->state = SETUP;
	}
	if (rtv1->state == SETUP)
	{
		if (button == 1 && rtv1->png.render_is_hover)
		{
			if (render(rtv1))
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		put_setup(rtv1);
	}
	else if (rtv1->state == RENDER)
	{
		if (button == 1 && rtv1->png.save_is_hover)
		{
			write_ppm(rtv1);
			(rtv1->id_ppm)++;
		}
		else if (button == 1 && rtv1->png.display_is_hover)
		{
			if (init_image(rtv1))
				return (EXIT_FAILURE);
			image(rtv1);
			(rtv1->id_win)++;
		}
		else if (button == 1 && rtv1->png.retry_is_hover)
		{
			// free_texture(&rtv1->scene);
			// free(rtv1->scene.obj);
			// free(rtv1->screen);
			file(rtv1->ac, rtv1->av, &file_str);
			if (init_scene(rtv1, file_str) == EXIT_FAILURE)
				rtv1->state = ERROR;
			else
				rtv1->state = SETUP;
		}
		put_setup(rtv1);
	}
	else if (rtv1->state == ERROR)
	{
		if (button == 1 && rtv1->png.setup_is_hover)
		{
			clean_exit(rtv1);
		}
		put_setup(rtv1);
	}
	return (EXIT_SUCCESS);
}

void 		format(t_rtv1 *rtv1, int width, int height)
{
	rtv1->scene.width = width;
	rtv1->scene.height = height;
}
