/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/17 19:00:08 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void		radiance(t_scene *scene, t_ray *ray, t_render *render)
{
	size_t		id;
	t_obj		*shape;

	vec(0.0, 0.0, 0.0, &ray->blank);
	vec(1.0, 1.0, 1.0, &ray->mask);
	while (TRUE) {
		// Intersect
		if (!intersect(ray, &id, scene))
		{
			veccp(&ray->blank, &render->color);
			return ;
		}
		shape = &scene->obj[id];
		// Next point
		eval(ray, ray->distance, &ray->x);
		// Norm object
		normal(ray, shape);
		// Light
		lighting(shape, ray);
		// Textures
		multi_(&ray->mask, &shape->color);
		if (russian_roulette(ray, shape, render))
			return ;
		// Next path segment
		specular(ray, render, shape);
	}
}
