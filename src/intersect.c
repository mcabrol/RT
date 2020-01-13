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

BOOL 	intersect(t_ray *ray, size_t *id)
{
	t_sphere	obj[9];
	bool		hit;
	size_t		n;
	size_t		i;

	obj[0] = sphere(1e5,
					vec(1e5 + 1.0, 40.8, 81.6),
					vec(0.0, 0.0, 0.0),
					vec(0.75, 0.25, 0.25),
					DIFF); // Left
	obj[1] = sphere(1e5,
					vec(-1e5 + 99.0, 40.8, 81.6),
					vec(0.0, 0.0, 0.0),
					vec(0.25, 0.25, 0.75),
					DIFF); // Right
	obj[2] = sphere(1e5,
					vec(50.0, 40.8, 1e5),
					vec(0.0, 0.0, 0.0),
					vec(0.75, 0.75, 0.75),
					DIFF); //Back
	obj[3] = sphere(1e5,
					vec(50.0, 40.8, -1e5 + 170.0),
					vec(0.0, 0.0, 0.0),
					vec(0.0, 0.0, 0.0),
					DIFF); //Front
	obj[4] = sphere(1e5,
					vec(50.0, 1e5, 81.6),
					vec(0.0, 0.0, 0.0),
					vec(0.75, 0.75, 0.75),
					DIFF); //Bottom
	obj[5] = sphere(1e5,
					vec(50.0, -1e5 + 81.6, 81.6),
					vec(0.0, 0.0, 0.0),
					vec(0.75, 0.75, 0.75),
					DIFF); //Top
	obj[6] = sphere(16.5,
					vec(27.0, 16.5, 47.0),
					vec(0.0, 0.0, 0.0),
					vec(0.999, 0.999, 0.999),
					SPEC); //Mirror
	obj[7] = sphere(16.5,
					vec(73.0, 16.5, 78.0),
					vec(0.0, 0.0, 0.0),
					vec(0.999, 0.999, 0.999),
					REFR); // Glass
	obj[8] = sphere(600,
					vec(50.0, 681.6 - .27, 81.6),
					vec(12.0, 12.0, 12.0),
					vec(0.0, 0.0, 0.0),
					DIFF); // Light

	hit = FALSE;
	n = sizeof(obj) / sizeof(t_sphere);
	i = 0u;
	while (i < n)
	{
		if (intersect_sphere(&obj[i], ray))
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

	op = sub(&sphere->p, &ray->o);
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
