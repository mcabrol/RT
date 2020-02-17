/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:25:45 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/17 18:36:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv1.h"

void 	lighting(t_obj *shape, t_ray *ray)
{
	multiplication(&ray->mask, &shape->emission, &ray->light);
	sum_(&ray->blank, &ray->light);
}
