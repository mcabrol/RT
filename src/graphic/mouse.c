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
	x = 0;
	y = 0;
	if (button == 1 && rtv1->sprite.retry.is_hover)
	{
		free_texture(&rtv1->scene);
		if (rtv1->state == RENDER)
		{
			ft_printf("\nfree all shit\n");
			ft_bzero(rtv1->screen, rtv1->scene.height * rtv1->scene.width);
			free(rtv1->scene.obj);
		}
		ft_bzero(rtv1->file_str, ft_strlen(rtv1->file_str));
		file(rtv1->ac, rtv1->av, &rtv1->file_str);
		if (init_scene(rtv1, rtv1->file_str) == EXIT_FAILURE)
			rtv1->state = ERROR;
		else
			rtv1->state = SETUP;
		put_setup(rtv1);
		return (EXIT_SUCCESS);
	}
	if (rtv1->state == SETUP)
	{
		if (button == 1 && rtv1->sprite.render.is_hover)
		{
			if (render(rtv1))
				return (EXIT_FAILURE);
			(rtv1->id_render)++;
		}
		put_setup(rtv1);
		return (EXIT_SUCCESS);
	}
	else if (rtv1->state == RENDER)
	{
		if (button == 1 && rtv1->sprite.save.is_hover)
		{
			write_ppm(rtv1);
			(rtv1->id_ppm)++;
		}
		else if (button == 1 && rtv1->sprite.display.is_hover)
		{
			if (init_image(rtv1))
				return (EXIT_FAILURE);
			image(rtv1);
			(rtv1->id_win)++;
		}
		return (EXIT_SUCCESS);
	}
	else if (rtv1->state == ERROR)
	{
		if (button == 1 && rtv1->sprite.setup.is_hover)
			clean_exit(rtv1);
	}
	return (EXIT_SUCCESS);
}

void 		format(t_rtv1 *rtv1, int width, int height)
{
	rtv1->scene.width = width;
	rtv1->scene.height = height;
}
