/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 18:58:00 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	sphere_normal(t_obj *sphere, t_ray *ray)
{
	sub(&ray->p, &sphere->p, &ray->n);
	norm(&ray->n);
	radiance->nl = *norm(&r->n)
	if (dot(&r->nl))
}

void 	plane_normal(t_obj *plane, t_ray *ray)
{
	sub(&ray->p, &plane->p, &ray->n);
	norm(&ray->n);
}
