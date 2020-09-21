/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/21 17:10:03 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		setup_ray(t_ray *ray)
{
	vec(0.0, 0.0, 0.0, &ray->blank);
	vec(1.0, 1.0, 1.0, &ray->mask);
}

static void		inner_radiance(t_scene *scene, t_ray *ray, t_obj *shape)
{
	eval(ray, ray->distance, &ray->x);
	normal(ray, shape);
	lighting(scene, ray, shape);
	texture(ray, shape);
}

void			radiance(t_scene *scene, t_ray *ray, t_render *render)
{
	size_t		id;
	t_obj		*shape;

	setup_ray(ray);
	while (TRUE)
	{
		if (!intersect(ray, &id, scene))
		{
			if (scene->cam.environment.path == NULL)
				return (veccp(&ray->blank, &render->color));
			else
				return (environment_texture(scene, ray, &render->color));
		}
		shape = &scene->obj[id];
		inner_radiance(scene, ray, shape);
		if (russian_roulette(ray, shape, render))
			return ;
		reflect(ray, render, shape);
	}
}
