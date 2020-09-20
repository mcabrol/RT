/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 19:34:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_texture(t_rtv1 *rtv1)
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

void	free_sprite(t_button button, void *mlx_ptr)
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

void	free_all_sprite(t_sprite *sprite, void *mlx_ptr)
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
