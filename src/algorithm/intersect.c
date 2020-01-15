/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/13 18:02:01 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

BOOL 	intersect(t_ray *ray, size_t *id, t_scene *scene)
{
	BOOL		hit;
	size_t		n;
	size_t		i;

	hit = FALSE;
	n = sizeof(scene->obj) / sizeof(t_sphere);
	i = 0u;
	while (i < n)
	{
		if (intersect_sphere(&scene->obj[i], ray))
		{
			hit = TRUE;
			*id = i;
		}
		i++;
	}
	return (hit);
}

BOOL 	intersect_sphere(t_sphere *sphere, t_ray *ray)
{
	t_vec	op;
	double	dop;
	double	d;
	double	sqrtd;
	double	tmin;
	double	tmax;

	sub(&sphere->p, &ray->o, &op);
	dop = dot(&ray->d, &op);
	d = dop * dop - dot(&op, &op) + sphere->r * sphere->r;
	if (0 > d)
		return (FALSE);
	sqrtd = sqrt(d);
	tmin = dop - sqrtd;
	if (ray->tmin < tmin && tmin < ray->tmax)
	{
		ray->tmax = tmin;
		return (TRUE);
	}
	tmax = dop + sqrtd;
	if (ray->tmin < tmax && tmax < ray->tmax)
	{
		ray->tmax = tmax;
		return (TRUE);
	}
	return (FALSE);
}
