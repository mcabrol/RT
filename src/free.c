/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/19 17:40:18 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void clean_all_windows(t_rtv1 *rtv1)
{
		int		i;

		i = 0;
		while (i < rtv1->id_win)
		{
			if (rtv1->image && rtv1->image[i].img_ptr && rtv1->image[i].available == 0)
			{
				mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
				mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
			}
			i = i + 1;
		}
		free(rtv1->image);
}

void free_texture(t_rtv1 *rtv1)
{
	int i;

	i = -1;
	while (++i < rtv1->scene.n)
	{
		if (rtv1->scene.obj[i].texture.data)
		{
			free(rtv1->scene.obj[i].texture.path);
			mlx_destroy_image(rtv1->mlx_ptr, rtv1->scene.obj[i].texture.image);
		}
	}
}
void free_sprite(t_button button, void *mlx_ptr)
{
	if (button.active != NULL)
		mlx_destroy_image(mlx_ptr, button.active);
	if (button.disabled != NULL)
		mlx_destroy_image(mlx_ptr, button.disabled);
	if (button.hover != NULL)
		mlx_destroy_image(mlx_ptr, button.hover);
	if (button.hover_disabled != NULL)
		mlx_destroy_image(mlx_ptr, button.hover_disabled);
}

void free_all_sprite(t_sprite *sprite, void *mlx_ptr)
{
	free_sprite(sprite->setup, mlx_ptr);
	free_sprite(sprite->close, mlx_ptr);
	free_sprite(sprite->save, mlx_ptr);
	free_sprite(sprite->retry, mlx_ptr);
	free_sprite(sprite->display, mlx_ptr);
	free_sprite(sprite->render, mlx_ptr);
	free_sprite(sprite->error, mlx_ptr);
	free_sprite(sprite->sample, mlx_ptr);
	free_sprite(sprite->format, mlx_ptr);
	free_sprite(sprite->close_setting, mlx_ptr);
	free_sprite(sprite->x8, mlx_ptr);
	free_sprite(sprite->x20, mlx_ptr);
	free_sprite(sprite->x200, mlx_ptr);
	free_sprite(sprite->x500, mlx_ptr);
	free_sprite(sprite->x1000, mlx_ptr);
	free_sprite(sprite->x5000, mlx_ptr);
	free_sprite(sprite->f320, mlx_ptr);
	free_sprite(sprite->f854, mlx_ptr);
	free_sprite(sprite->f1024, mlx_ptr);
	free_sprite(sprite->f1280, mlx_ptr);
	free_sprite(sprite->f1400, mlx_ptr);
	free_sprite(sprite->f1920, mlx_ptr);
	mlx_destroy_image(mlx_ptr, sprite->background);
	mlx_destroy_image(mlx_ptr, sprite->background_setting);
}

void	clean_image_array(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	while (i < MAX_WIN)
	{
		if (rtv1->image[i].available == 2)
		{
			rtv1->image[i].available = 1;
			mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
			mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
			printf("rtv1->id_win : %d\n", rtv1->id_win);
			rtv1->id_win = rtv1->id_win - 1;
		}
		i = i + 1;
	}
}

int				close_rcross(t_win *win)
{
	win->available = 2;
	return (0);
}

int		close_rcross_main(t_rtv1 *rtv1)
{
	clean_exit(rtv1);
	return (0);
}

int		close_rcross_s(t_rtv1 *rtv1)
{
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->setting.img_ptr);
	mlx_destroy_window(rtv1->mlx_ptr, rtv1->setting.win_ptr);
	return (0);
}

void 	clean_exit(t_rtv1 *rtv1)
{
	t_win 	*main;

	main = &rtv1->main;
	if (rtv1->scene.obj != NULL)
	{
		if (rtv1->state != ERROR)
		{
				ft_tabdel(rtv1->scene.obj_type);
				ft_tabdel(rtv1->scene.obj_options);
				free(rtv1->scene.obj_setter);
				free(rtv1->scene.obj);
		}
	}
	clean_all_windows(rtv1);
	free_all_sprite(&rtv1->sprite, rtv1->mlx_ptr);
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->main.img_ptr);
	exit(EXIT_SUCCESS);
}
