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
	int 	i;
	t_win 	*main;

	main = &rtv1->main;
	// if (rtv1->scene.m != NULL)
	// 	free(rtv1->scene.m);
	free(rtv1->scene.obj);

	ft_tabdel(rtv1->scene.obj_type);
	ft_tabdel(rtv1->scene.obj_options);
	// bug si on ouvre une fenetre et la ferme avec la croix, segfault

	i = -1;
	while (++i < rtv1->id_win)
	{
		if (rtv1->image && rtv1->image[i].img_ptr)
		{
			mlx_destroy_image(rtv1->mlx_ptr, rtv1->image[i].img_ptr);
			mlx_destroy_window(rtv1->mlx_ptr, rtv1->image[i].win_ptr);
			//peut etre d'autre chose a clean ici
		}
	}
	free(rtv1->image);
	mlx_destroy_image(rtv1->mlx_ptr, rtv1->main.img_ptr);
	mlx_destroy_window(rtv1->mlx_ptr, main->win_ptr);
	exit(0);
}
