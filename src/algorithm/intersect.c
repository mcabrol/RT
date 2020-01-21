/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 16:15:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

BOOL 	intersect(t_ray *ray, size_t *id, t_scene *scene)
{
	BOOL		hit;
	int 		type;
	size_t		n;
	size_t		i;

	hit = FALSE;
	n = sizeof(scene->obj) / sizeof(t_obj);
	i = 0u;
	while (i < n)
	{
		type = scene->obj[i].t;
		if (type == SPHERE ? intersect_sphere(&scene->obj[i], ray) : intersect_plan(&scene->obj[i], ray))
		{
			hit = TRUE;
			*id = i;
		}
		i++;
	}
	return (hit);
}

BOOL 	intersect_sphere(t_obj *sphere, t_ray *ray)
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

BOOL	intersect_plan(t_obj *plan, t_ray *ray)
{
	t_vec n;
	t_vec pl;
	float t;
	float denom;

	norm_(&plan->p, &n);
	denom = dot(&n, &ray->d);
	if (denom > 1e-4)
	{
		sub(&plan->p, &ray->o, &pl);
		t = dot(&pl, &n) / denom;
		return (t >= 0 ? TRUE : FALSE);
	}
	return (FALSE);
}
