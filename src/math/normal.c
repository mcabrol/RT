/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:54:01 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/28 18:00:45 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	plane_normal(t_ray *r, t_radiance *radiance, t_obj *obj)
{
	t_vec 	tmp;

	nmulti(&r->d, radiance->distance, &tmp);
	sum(&r->o, &tmp, &radiance->x);
	if (dot(&r->d, &obj->d) > 0)
		minus(&obj->d, &radiance->n);
	else
		radiance->n = obj->d;
	radiance->nl = *norm(&radiance->n);
	if (dot(&radiance->nl, &r->d) < 0)
		radiance->n = radiance->nl;
	else
		minus(&radiance->nl, &radiance->n);
}

void	sphere_normal(t_ray *r, t_radiance *radiance, t_obj *obj)
{
	t_vec 	tmp;

	nmulti(&r->d, radiance->distance, &tmp);
	sum(&r->o, &tmp, &radiance->x);
	sub(&radiance->x, &obj->p, &radiance->n);
	radiance->nl = *norm(&radiance->n);
	if (dot(&radiance->nl, &r->d) < 0)
		radiance->n = radiance->nl;
	else
		minus(&radiance->nl, &radiance->n);
}
