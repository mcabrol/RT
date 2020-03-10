/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:44:35 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/10 17:45:00 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		reflect(t_ray *ray, t_render *render, t_obj *shape)
{
	if (shape->reflect == SPEC)
	{
		ray->origin = ray->x;
		specular_reflect(&ray->direction, &ray->n);
		ray->depth++;
	}
	else
	{
		ray->origin = ray->x;
		diffuse_reflect(&ray->direction, &ray->n, render->xseed);
		ray->depth++;
	}
}

void		specular_reflect(t_vec *d, t_vec *n)
{
	t_vec a;

	nmulti(n, 2.0 * dot(n, d), &a);
	sub_(d, &a);
}

void		diffuse_reflect(t_vec *d, t_vec *n, unsigned short xseed[3])
{
	t_vec tmp;
	t_vec uvw[3];
	t_vec xyz[3];
	t_vec sample;

	vec(0.0, 0.0, 0.0, &tmp);
	if (0.0 > dot(n, d))
		uvw[2] = *n;
	else
		minus(n, &uvw[2]);
	if (fabs(uvw[2].x) > 0.1)
		tmp.y = 1.0;
	else
		tmp.x = 1.0;
	cross(&tmp, &uvw[2], &uvw[0]);
	norm(&uvw[0]);
	cross(&uvw[2], &uvw[0], &uvw[1]);
	cosine_weighted_sample(erand48(xseed), erand48(xseed), &sample);
	nmulti(&uvw[0], sample.x, &xyz[0]);
	nmulti(&uvw[1], sample.y, &xyz[1]);
	nmulti(&uvw[2], sample.z, &xyz[2]);
	sum(&xyz[0], &xyz[1], &tmp);
	sum(&tmp, &xyz[2], d);
	norm(d);
}
