/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 13:26:04 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		retry_is_hover(t_rtv1 *rtv1)
{
	if (rtv1->state == SETUP || rtv1->state == ERROR)
	{
		if (rtv1->state == ERROR)
			rtv1->setter = FALSE;
		ft_bzero(rtv1->file_str, ft_strlen(rtv1->file_str));
		file(rtv1->ac, rtv1->av, &rtv1->file_str);
		rtv1->state = (init_scene(rtv1, rtv1->file_str)) ? ERROR : SETUP;
	}
	else if (rtv1->state == RENDER)
	{
		free_texture(&rtv1->scene);
		ft_bzero(rtv1->screen, rtv1->scene.height * rtv1->scene.width);
		if (rtv1->scene.obj != NULL)
			free(rtv1->scene.obj);
		rtv1->state = SETUP;
	}
	return (EXIT_SUCCESS);
}

static int		render_is_hover(t_rtv1 *rtv1)
{
	if (rtv1->state == SETUP)
	{
		retry_is_hover(rtv1);
		if (render(rtv1))
			return (EXIT_FAILURE);
		rtv1->state = RENDER;
		(rtv1->id_render)++;
	}
	else
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int				mouse(int button, int x, int y, t_rtv1 *rtv1)
{
	int	error;

	x = 0;
	y = 0;
	if (button == 1)
	{
		if (rtv1->sprite.retry.is_hover)
			error = retry_is_hover(rtv1);
		if (rtv1->sprite.render.is_hover)
			error = render_is_hover(rtv1);
		if (rtv1->sprite.save.is_hover && rtv1->state != ERROR && rtv1->state != SETUP)
			rtv1->id_ppm += write_ppm(rtv1);
		if (rtv1->sprite.display.is_hover && rtv1->state != ERROR && rtv1->state != SETUP )
		{
			if (init_image(rtv1))
				return (EXIT_FAILURE);
			rtv1->id_win += image(rtv1);
		}
		if (rtv1->sprite.setup.is_hover && rtv1->state == ERROR)
			clean_exit(rtv1);
		else if (rtv1->sprite.setup.is_hover && (rtv1->state == SETUP || rtv1->state == RENDER))
			create_setting(rtv1);
	}
	put_setup(rtv1);
	return (EXIT_SUCCESS);
}
