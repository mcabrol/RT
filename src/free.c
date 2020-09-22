/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 12:22:40 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			free_texture(t_rtv1 *rtv1)
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

void			free_sprite(t_button button, void *mlx_ptr)
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

static void		free_sample_sprite(t_sprite *sprite, void *mlx_ptr)
{
	if (sprite->x8.active)
		free_sprite(sprite->x8, mlx_ptr);
	if (sprite->x20.active)
		free_sprite(sprite->x20, mlx_ptr);
	if (sprite->x200.active)
		free_sprite(sprite->x200, mlx_ptr);
	if (sprite->x500.active)
		free_sprite(sprite->x500, mlx_ptr);
	if (sprite->x1000.active)
		free_sprite(sprite->x1000, mlx_ptr);
	if (sprite->x5000.active)
		free_sprite(sprite->x5000, mlx_ptr);
}

static void		free_format_sprite(t_sprite *sprite, void *mlx_ptr)
{
	if (sprite->f320.active)
		free_sprite(sprite->f320, mlx_ptr);
	if (sprite->f854.active)
		free_sprite(sprite->f854, mlx_ptr);
	if (sprite->f1024.active)
		free_sprite(sprite->f1024, mlx_ptr);
	if (sprite->f1280.active)
		free_sprite(sprite->f1280, mlx_ptr);
	if (sprite->f1400.active)
		free_sprite(sprite->f1400, mlx_ptr);
	if (sprite->f1920.active)
		free_sprite(sprite->f1920, mlx_ptr);
}

void			free_all_sprite(t_sprite *sprite, void *mlx_ptr)
{
	if (sprite->setup.active)
		free_sprite(sprite->setup, mlx_ptr);
	if (sprite->close.active)
		free_sprite(sprite->close, mlx_ptr);
	if (sprite->save.active)
		free_sprite(sprite->save, mlx_ptr);
	if (sprite->retry.active)
		free_sprite(sprite->retry, mlx_ptr);
	if (sprite->display.active)
		free_sprite(sprite->display, mlx_ptr);
	if (sprite->render.active)
		free_sprite(sprite->render, mlx_ptr);
	if (sprite->error.active)
		free_sprite(sprite->error, mlx_ptr);
	if (sprite->sample.active)
		free_sprite(sprite->sample, mlx_ptr);
	if (sprite->format.active)
		free_sprite(sprite->format, mlx_ptr);
	if (sprite->close_setting.active)
		free_sprite(sprite->close_setting, mlx_ptr);
	free_format_sprite(sprite, mlx_ptr);
	free_sample_sprite(sprite, mlx_ptr);
	mlx_destroy_image(mlx_ptr, sprite->background);
	mlx_destroy_image(mlx_ptr, sprite->background_setting);
}
