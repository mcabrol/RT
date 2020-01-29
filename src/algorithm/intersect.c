/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 19:42:02 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		intersect(t_vec *origin, t_vec *direction, t_radiance *radiance, t_render *render)
{
	double		distance;
	int			n;
	int			i;

	n = sizeof(obj) / sizeof(t_object);
	i = 0;
	radiance->id = -1;
	while (i < n)
	{
		if (render->object[i].type == SPHERE)
			distance = intersect_sphere(&render->object[i], origin, direction);
		else if (render->object[i].type == PLANE)
			distance = intersect_plane(&render->object[i], origin, direction);
		if (distance >= T_MIN && distance < radiance->distance)
		{
			radiance->distance = distance;
			radiance->id = i;
		}
		i++;
	}
}

double		intersect_sphere(t_object *obj, t_vec *origin, t_vec *direction)
{
	t_vec	oc;
	t_vec	k;
	double	tmin;

	sub(origin, &obj->position, &oc);
	k.x = dot(direction, direction);
	k.y = 2 * dot(&oc, direction);
	k.z = dot(&oc, &oc) - obj->radius * obj->radius;
	// Need to check if neg
	tmin = quadratic(k.x, k.y, k.z);
	return (tmin);
}

double		intersect_plane(t_object *obj, t_vec *origin, t_vec *direction)
{
	// ov		Direction
	// point	Origin
	t_vec		oc;
	double		k1;
	double		k2;
	double		koef;
	double		t;

	sub(origin, &obj->position, &oc);
	koef = 1;
	t = T_MAX;
	if ((k1 = dot(direction, &obj->direction)) == 0)
		return (t);
	k2 = dot(&oc, &obj->direction);
	if (k1 == k2)
		koef = -1;
	t = -k2 / k1 * koef;
	return (t);
}
