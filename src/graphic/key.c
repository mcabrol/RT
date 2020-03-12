/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 19:18:38 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// #include "minilibx-linux/mlx_int.h"

int		key(int keycode, t_rtv1 *rtv1)
{
	t_win *main;
	int		i;

	main = &rtv1->main;
	if (keycode == 53)
	{
		if (rtv1->scene.m != NULL)
			free(rtv1->scene.m);
		free(rtv1->scene.obj);
		i = 0;
		while(rtv1->scene.obj_type[i])
		{
			free(rtv1->scene.obj_type[i]);
			i = i + 1;
		}
		free(rtv1->scene.obj_type);
		i = 0;
		while(rtv1->scene.obj_options[i])
		{
			free(rtv1->scene.obj_options[i]);
			i = i + 1;
		}
		free(rtv1->scene.obj_options);
		free(rtv1->scene.obj_setter);
		i = 0;
		//bug si on ouvre une fenetre et la ferme avec la croix, segfault
		while (i < MAX_WIN)
		{
			if (rtv1->image && rtv1->image[i].img_ptr)
			{
				mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
				mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
				//peut etre d'autre chose a clean ici
			}
			i = i + 1;
		}
		free(rtv1->image);
		 mlx_destroy_image(rtv1->mlx_ptr, rtv1->main.img_ptr);
		mlx_destroy_window(rtv1->mlx_ptr, main->win_ptr);
		exit(0);
	}
	if (keycode == 36)
	{
		pathtracer(rtv1);
	}
	if (keycode == 49)
	{
		if (init_image(rtv1))
			return (EXIT_FAILURE);
		image(rtv1);
		(rtv1->id_win++);
	}
	if (keycode == 1)
	{
		write_ppm(rtv1);
	}
	return (EXIT_SUCCESS);
}
