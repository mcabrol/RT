/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:25:45 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 14:30:57 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		uv(t_ray *ray, t_obj *obj, double *u, double *v)
{
	if (obj->type == SPHERE)
		uv_sphere(u, v, ray);
	else if (obj->type == PLANE)
		uv_plane(u, v, ray);
	else if (obj->type == CYLINDER)
		uv_cylinder(u, v, ray, obj);
}

void		uv_sphere(double *u, double *v, t_ray *ray)
{
	*u = (double)(0.5 + (atan2(ray->n.z, ray->n.x) / (2.0 * M_PI)));
	*v = (double)(0.5 - (asin(ray->n.y) / M_PI));
}

void		uv_cylinder(double *u, double *v, t_ray *ray, t_obj *obj)
{
	t_vec	tmp;
	double	lenght;
	double	h;

	*u = 0.5 + atan2(ray->n.z, ray->n.x) / (2 * M_PI);
	sub(&obj->direction, &obj->position, &tmp);
	lenght = len(&tmp);
	sub(&ray->x, &obj->position, &tmp);
	h = len(&tmp);
	*v = sqrt(h * h - obj->radius * obj->radius) / lenght / 2 * obj->radius;
}

void		uv_plane(double *u, double *v, t_ray *ray)
{
	t_vec n;
	t_vec z;
	t_vec tmp;

	vec(0, 0, 1, &z);
	cross(&ray->n, &z, &n);
	if (dot(&n, &n) < 0.001)
		vec(1, 0, 0, &n);
	else
		norm(&n);
	cross(&n, &ray->n, &tmp);
	*u = fabs(dot(&ray->x, &n));
	*v = fabs(dot(&ray->x, &tmp));
}
