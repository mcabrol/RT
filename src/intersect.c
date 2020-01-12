/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 	intersect(t_ray *ray, size_t *id)
{
	int hit;
	size_t n;
	size_t i;

	hit = FALSE;
	n = sizeof(sphere) / sizeof(t_sphere);
	i = 0u;
	while (i < n)
	{
		if (intersect_sphere(&sphere[i], ray))
		{
			hit = TRUE;
			*id = i;
		}
	}
	return (hit);
}

int 	intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec op;
	double dop;
	double d;
	double sqrtd;
	double tmin;
	double tmax;

	op = sub(&sphere->p, &ray->o);
	dop = dot(&ray->d, &op);
	d = dop * dop - dot(&op, &op) + sphere->r * sphere->r;

	if (0 > d)
		return (FALSE);

	sqrtd = sqrtd(d);

	t_min = dop - sqrtd;
	if (ray->tmin < tmin && tmin < ray->tmax)
	{
		ray->tmax = tmin;
		return (TRUE);
	}

	return (FALSE);
}
