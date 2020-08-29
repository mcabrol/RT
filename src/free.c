/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 17:26:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void clean_all_windows(t_rtv1 *rtv1)
{
		int		i;

		i = 0;
		while (i < rtv1->id_win)
		{
			if (rtv1->image && rtv1->image[i].img_ptr)
			{
				mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
				mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
			}
			i = i + 1;
		}
}

void 	free_scene(t_scene *scene)
{
	ft_tabdel(scene->obj_type);
	ft_tabdel(scene->obj_options);
	// free_obj(&scene->cam);
}

void 	free_obj(t_obj *obj)
{
	if (obj->texture.path)
	{
		// free(obj->texture.path);
		// free(obj->texture.data);
		// free(obj->texture.image);
	}


}

void free_texture(t_scene *scene)
{
	int i;
	t_obj *obj;

	i = -1;
	obj = NULL;
	while (++i < scene->n)
	{
		obj = &scene->obj[i];
		if (obj->texture.path)
		{
			free(obj->texture.path);
			free(obj->texture.data);
			free(obj->texture.image);
		}
	}
}

void 	clean_exit(t_rtv1 *rtv1)
{
	t_win 	*main;

	main = &rtv1->main;
	if (rtv1->state == ERROR)
	{
		mlx_destroy_image(rtv1->mlx_ptr, rtv1->main.img_ptr);
		mlx_destroy_window(rtv1->mlx_ptr, main->win_ptr);
	}
	else
	{
		if (rtv1->scene.obj == NULL)
			free(rtv1->scene.obj);
		ft_tabdel(rtv1->scene.obj_type);
		ft_tabdel(rtv1->scene.obj_options);
		clean_all_windows(rtv1);
		if (rtv1->state == RENDER && rtv1->id_win > 0)
			free(rtv1->image);
	}
	exit(EXIT_SUCCESS);
}
