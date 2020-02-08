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
	double 		distance;
	t_obj		*obj;
	size_t		n;
	size_t		i;

	hit = FALSE;
	n = sizeof(scene->obj) / sizeof(t_obj);
	i = 0u;
	ray->dist = T_MAX;
	while (i < n)
	{
		obj = &scene->obj[i];
		if (obj->t == SPHERE)
			distance = intersect_sphere(obj, ray);
		else if (obj->t == PLANE)
			distance = intersect_plane(obj, ray);
		else if (obj->t == CYLINDER)
			distance = intersect_cylinder(obj, ray);
		else if (obj->t == CONE)
			distance = intersect_cone(obj, ray);
		else if (obj->t == BOX)
			distance = intersect_box(obj, ray);
		if (distance >= T_MIN && distance < ray->dist)
		{
			hit = TRUE;
			ray->dist = distance;
			*id = i;
		}
		i++;
	}
	return (hit);
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

double	intersect_plane(t_obj *plane, t_ray *ray)
{
	t_vec		oc;
	double		k1;
	double		k2;
	double		koef;
	double		t;

	sub(&ray->o, &plane->p, &oc);
	koef = 1;
	t = T_MAX;
	if ((k1 = dot(&ray->d, &plane->d)) == 0)
		return (FALSE);
	k2 = dot(&oc, &plane->d);
	if (k1 == k2)
		koef = -1;
	t = -k2 / k1 * koef;
	return (t);
}

double		intersect_cylinder(t_obj *cylinder, t_ray *ray)
{
	t_vec	oc;
	t_vec	k;
	double	t_min;

	sub(&ray->o, &cylinder->p, &oc);
	k.x = dot(&ray->d, &ray->d) - pow(dot(&ray->d, &cylinder->d), 2);
	k.y = 2 * (dot(&ray->d, &oc) - dot(&ray->d, &cylinder->d) * dot(&oc, &cylinder->d));
	k.z = dot(&oc, &oc) - pow(dot(&oc, &cylinder->d), 2) - cylinder->r * cylinder->r;
	t_min = check_pnt(&k, &ray->d, &ray->o, cylinder);
	return (t_min);
}

double		intersect_cone(t_obj *cone, t_ray *ray)
{
	t_vec		oc;
	t_vec		k;
	double		a;
	double		t_min;

	sub(&ray->o, &cone->p, &oc);
	a = 1 + cone->a * cone->a;
	k.x = dot(&ray->d, &ray->d) - a * pow(dot(&ray->d, &cone->d), 2);
	k.y = 2 * (dot(&ray->d, &oc) - a * dot(&ray->d, &cone->d) * dot(&oc, &cone->d));
	k.z = dot(&oc, &oc) - a * pow(dot(&oc, &cone->d), 2);
	t_min = check_pnt(&k, &ray->d, &ray->o, cone);
	return (t_min);
}

double		intersect_box(t_obj *box, t_ray *ray)
{
	// ray->o ray->o
	// ov    ray->d
	double		min[3];
	double		max[3];
	t_vec		rev_ov;
	t_vec		pos;

	divide3(1, &ray->d, &rev_ov);
	vec(box->p.x + box->ca, box->p.y + box->cb, box->p.z + box->cc, &pos);
	if (rev_ov.x >= 0)
	{
		min[0] = (box->p.x - ray->o.x) * rev_ov.x;
		max[0] = (pos.x - ray->o.x) * rev_ov.x;
	}
	else
	{
		min[0] = (pos.x - ray->o.x) * rev_ov.x;
		max[0] = (box->p.x - ray->o.x) * rev_ov.x;
	}
	if (rev_ov.y >= 0)
	{
		min[1] = (box->p.y - ray->o.y) * rev_ov.y;
		max[1] = (pos.y - ray->o.y) * rev_ov.y;
	}
	else
	{
		min[1] = (pos.y - ray->o.y) * rev_ov.y;
		max[1] = (box->p.y - ray->o.y) * rev_ov.y;
	}
	if (rev_ov.z >= 0)
	{
		min[2] = (box->p.z - ray->o.z) * rev_ov.z;
		max[2] = (pos.z - ray->o.z) * rev_ov.z;
	}
	else
	{
		min[2] = (pos.z - ray->o.z) * rev_ov.z;
		max[2] = (box->p.z - ray->o.z) * rev_ov.z;
	}
	return (ft_check_pnt_box(min, max));
}
