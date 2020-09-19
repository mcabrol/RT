/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/18 22:01:46 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		radiance(t_scene *scene, t_ray *ray, t_render *render)
{
	int			hit;
	size_t		id;
	t_obj		*shape;

	vec(0.0, 0.0, 0.0, &ray->blank);
	vec(1.0, 1.0, 1.0, &ray->mask);
	hit = 0;
	while (TRUE)
	{
		if (!intersect(ray, &id, scene))
		{
			if (scene->cam.environment.path == NULL)
				return (veccp(&ray->blank, &render->color));
			else
				return ((hit) ? environment_texture(scene, ray, &render->color)\
				: veccp(&ray->blank, &render->color));
		}
		else
			hit++;
		shape = &scene->obj[id];
		eval(ray, ray->distance, &ray->x);
		normal(ray, shape);
		lighting(scene, ray, shape);
		pthread_mutex_lock(&scene->lock);
		texture(ray, shape);
		pthread_mutex_unlock(&scene->lock);
		if (russian_roulette(ray, shape, render))
			return ;
		reflect(ray, render, shape);
	}
}
