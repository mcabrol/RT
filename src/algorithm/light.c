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

void		lighting(t_ray *ray, t_obj *shape)
{
	multiplication(&ray->mask, &shape->emission, &ray->light);
	sum_(&ray->blank, &ray->light);
}
