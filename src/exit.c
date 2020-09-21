/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:27:32 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/21 15:12:41 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	clean_all_windows(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	while (i < rtv1->id_win)
	{
		if (rtv1->image && rtv1->image[i].img_ptr && \
		rtv1->image[i].available == 0)
		{
			mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
			mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
		}
		i = i + 1;
	}
	free(rtv1->image);
}

int			clean_image_array(t_rtv1 *rtv1)
{
	int		i;
	int		cleaned;

	i = 0;
	cleaned = 0;
	while (i < MAX_WIN)
	{
		if (rtv1->image[i].available == 2)
		{
			rtv1->image[i].available = 1;
			mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
			mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
			rtv1->id_win = rtv1->id_win - 1;
			cleaned = cleaned + 1;
		}
		i = i + 1;
	}
	if (cleaned == 0)
		throw_error(NO_WIN_AVAILABLE);
	return (cleaned);
}

void		clean_exit(t_rtv1 *rtv1)
{
	t_win	*main;

	main = &rtv1->main;
	if (rtv1->scene.obj != NULL)
	{
		if (rtv1->state != ERROR)
		{
			ft_tabdel(rtv1->scene.obj_type);
			ft_tabdel(rtv1->scene.obj_options);
			free(rtv1->list_disabled);
			free(rtv1->scene.obj_setter);
			free(rtv1->scene.obj);
		}
	}
	clean_all_windows(rtv1);
	free_all_sprite(&rtv1->sprite, rtv1->mlx_ptr);
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->main.img_ptr);
	exit(EXIT_SUCCESS);
}
