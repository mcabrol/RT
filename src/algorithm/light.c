/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:25:45 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/10 18:41:16 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		lighting(t_scene *scene, t_ray *ray, t_obj *shape)
{
	t_vec	ambient;

	veccp(&scene->cam.ambient, &ambient);
	// if (shape->reflect == DIFF)
	// 	multiplication(&shape->color, &scene->cam.ambient, &ambient);
	// sum(&shape->emission, &ambient, &emission);
	multiplication(&ray->mask, &shape->emission, &ray->light);
	sum_(&ray->blank, &ray->light);
}
