/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/15 19:58:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		retry_is_hover(t_rtv1 *rtv1)
{
	printf("rtv1->state : %d\n", rtv1->state);
	if (rtv1->state == SETUP || rtv1->state == ERROR)
	{
		if (rtv1->state == ERROR)
			rtv1->setter = FALSE;
		ft_bzero(rtv1->file_str, ft_strlen(rtv1->file_str));
	}
	else if (rtv1->state == RENDER)
	{
		free(rtv1->screen);
		if (rtv1->scene.obj != NULL)
		{
			free_texture(rtv1);
			free(rtv1->scene.obj);
		}
	}
	file(rtv1->ac, rtv1->av, &rtv1->file_str);
	rtv1->state = (init_scene(rtv1, rtv1->file_str)) ? ERROR : SETUP;
	printf("\trtv1->state : %d\n", rtv1->state);
	return (EXIT_SUCCESS);
}

static int		render_is_hover(t_rtv1 *rtv1)
{
	if (rtv1->id_render == 0)
		rtv1->screen = (t_vec *)malloc((rtv1->scene.width * rtv1->scene.height)\
		* sizeof(t_vec));
	if (rtv1->state == SETUP)
	{
		if (render(rtv1))
			return (EXIT_FAILURE);
		rtv1->state = RENDER;
		(rtv1->id_render)++;
	}
	return (EXIT_SUCCESS);
}

static int		display_is_hover(t_rtv1 *rtv1)
{
	if (init_image(rtv1))
		return (EXIT_FAILURE);
	else
		rtv1->id_win += image(rtv1);
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
		if (rtv1->sprite.save.is_hover && rtv1->state == RENDER)
			rtv1->id_ppm += write_ppm(rtv1);
		if (rtv1->sprite.display.is_hover && rtv1->state == RENDER)
			error = display_is_hover(rtv1);
		if (rtv1->sprite.setup.is_hover && rtv1->state == ERROR)
			clean_exit(rtv1);
		else if (rtv1->sprite.setup.is_hover && rtv1->state != ERROR)
			create_setting(rtv1);
	}
	put_setup(rtv1);
	return (EXIT_SUCCESS);
}
