/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/28 17:07:54 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	intersect(t_ray *ray, t_radiance *radiance, int *id, t_scene *scene)
{
	BOOL		hit;
	double		distance;
	size_t		n;
	size_t		i;

	hit = FALSE;
	n = sizeof(scene->obj) / sizeof(t_obj);
	i = 0u;
	*id = -1;
	while (i < n)
	{
		if (scene->obj[i].t == SPHERE)
			distance = intersect_sphere(&scene->obj[i], ray);
		else if (scene->obj[i].t == PLAN)
			distance = intersect_plan(&scene->obj[i], ray);
		if (distance >= T_MIN && distance < radiance->distance)
		{
			radiance->distance = distance;
			*id = i;
		}
		i++;
	}
}

double 	intersect_sphere(t_obj *sphere, t_ray *ray)
{
	t_vec	oc;
	t_vec	k;
	double	tmin;

	sub(&ray->o, &sphere->p, &oc);
	k.x = dot(&ray->d, &ray->d);
	k.y = 2 * dot(&oc, &ray->d);
	k.z = dot(&oc, &oc) - sphere->r * sphere->r;
	// Need to check if neg
	tmin = quadratic(k.x, k.y, k.z);
	return (tmin);
}

double	intersect_plan(t_obj *plan, t_ray *ray)
{
	// ov		Direction
	// point	Origin
	t_vec		oc;
	double		k1;
	double		k2;
	double		koef;
	double		t;

	sub(&ray->o, &plan->p, &oc);
	koef = 1;
	t = T_MAX;
	if ((k1 = dot(&ray->d, &plan->d)) == 0)
		return (t);
	k2 = dot(&oc, &plan->d);
	if (k1 == k2)
		koef = -1;
	t = -k2 / k1 * koef;
	return (t);
}
