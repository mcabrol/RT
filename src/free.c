/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/17 18:06:30 by mcabrol          ###   ########.fr       */
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

void 	free_scene(t_scene *scene)
{
	ft_tabdel(scene->obj_type);
	ft_tabdel(scene->obj_options);
	// free_obj(&scene->cam);
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
void free_sprite(t_button button, char *nom, void *mlx_ptr)
{
	printf("===============================================\n");
	printf("name : %s\n", nom);
	printf("active : %p\n", button.active);
	printf("hover : %p\n", button.hover);
	printf("hover_disabled : %p\n", button.hover_disabled);
	printf("disabled : %p\n", button.disabled);


	mlx_destroy_image(mlx_ptr, button.active);
	if (button.disabled != NULL)
		mlx_destroy_image(mlx_ptr, button.disabled);
	if (button.hover != NULL)
		mlx_destroy_image(mlx_ptr, button.hover);
	if (button.hover_disabled != NULL)
		mlx_destroy_image(mlx_ptr, button.hover_disabled);

	printf("freed\n");
}

void free_all_sprite(t_sprite *sprite, void *mlx_ptr)
{
	free_sprite(sprite->setup, "setup", mlx_ptr);
	free_sprite(sprite->close, "close", mlx_ptr);
	free_sprite(sprite->save, "save", mlx_ptr);
	free_sprite(sprite->retry, "retry", mlx_ptr);
	free_sprite(sprite->display, "display", mlx_ptr);
	free_sprite(sprite->render, "render", mlx_ptr);
	free_sprite(sprite->error, "error", mlx_ptr);
	free_sprite(sprite->sample, "sample", mlx_ptr);
	free_sprite(sprite->format, "format", mlx_ptr);
	free_sprite(sprite->close_setting, "close_setting", mlx_ptr);
	free_sprite(sprite->x8, "x8", mlx_ptr);
	free_sprite(sprite->x20, "x20", mlx_ptr);
	free_sprite(sprite->x200, "x200", mlx_ptr);
	free_sprite(sprite->x500, "x500", mlx_ptr);
	free_sprite(sprite->x1000, "x1000", mlx_ptr);
	free_sprite(sprite->x5000, "x5000", mlx_ptr);
	free_sprite(sprite->f320, "f320", mlx_ptr);
	free_sprite(sprite->f854, "f854", mlx_ptr);
	free_sprite(sprite->f1024, "f1024", mlx_ptr);
	free_sprite(sprite->f1280, "f1280", mlx_ptr);
	free_sprite(sprite->f1400, "f1400", mlx_ptr);
	free_sprite(sprite->f1920, "f1920", mlx_ptr);
	mlx_destroy_image(mlx_ptr, sprite->background);
	mlx_destroy_image(mlx_ptr, sprite->background_setting);
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
