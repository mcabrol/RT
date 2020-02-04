/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 18:41:05 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

BOOL 	intersect(t_ray *ray, size_t *id, t_scene *scene)
{
	BOOL		hit;
	t_obj		*obj;
	size_t		n;
	size_t		i;

	hit = FALSE;
	n = sizeof(scene->obj) / sizeof(t_obj);
	i = 0u;
	while (i < n)
	{
		obj = &scene->obj[i];
		if (obj->t == SPHERE && intersect_sphere(obj, ray))
		{
			hit = TRUE;
			*id = i;
		}
		else if (obj->t == PLANE && intersect_plane(obj, ray))
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

BOOL	intersect_plane(t_obj *plane, t_ray *ray)
{
	t_vec		oc;
	double		k1;
	double		k2;
	double		koef;
	double		t;

	sub(&ray->o, &plane->p, &oc);
	koef = 1;
	t = INFINITY;
	if ((k1 = dot(&ray->d, &plane->d)) == 0)
		return (FALSE);
	k2 = dot(&oc, &plane->d);
	if (k1 == k2)
		koef = -1;
	t = -k2 / k1 * koef;
	ray->dist = t;
	return (t >= 0 ? TRUE : FALSE);
}
