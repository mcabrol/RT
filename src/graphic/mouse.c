/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/09 20:14:18 by judrion          ###   ########.fr       */
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
		if (init_scene(rtv1, rtv1->file_str) == EXIT_FAILURE)
			rtv1->state = ERROR;
		else
			rtv1->state = SETUP;
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
		rtv1->state = RENDER;
		render_is_hover(rtv1);
	}
	else if (rtv1->state == RENDER)
	{
		if (render(rtv1))
			return (EXIT_FAILURE);
		(rtv1->id_render)++;
	}
	return (EXIT_SUCCESS);
}

int		mouse(int button, int x, int y, t_rtv1 *rtv1)
{
	int		error;

	x = 0;
	y = 0;
	printf("key #%d - rtv1->state : %d\n", button, rtv1->state);
	if (button == 1)
	{
		if (rtv1->sprite.retry.is_hover)
			error = retry_is_hover(rtv1);
		if (rtv1->sprite.render.is_hover)
			error = render_is_hover(rtv1);
		if (rtv1->sprite.save.is_hover)
		{
			write_ppm(rtv1);
			(rtv1->id_ppm)++;
		}
		if (rtv1->sprite.display.is_hover)
		{
			printf("je bug...\n");
			if (init_image(rtv1))
				return (EXIT_FAILURE);
			image(rtv1);
			(rtv1->id_win)++;
		}
		if (rtv1->sprite.setup.is_hover && rtv1->state == ERROR)
			clean_exit(rtv1);
		if (rtv1->sprite.setup.is_hover && rtv1->state == SETUP)
			create_setting(rtv1);
	}
	put_setup(rtv1);
	return (EXIT_SUCCESS);
}



void 		format(t_rtv1 *rtv1, int width, int height)
{
	rtv1->scene.width = width;
	rtv1->scene.height = height;
}
