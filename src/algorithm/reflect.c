/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:44:35 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 18:42:45 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			reflect(t_ray *ray, t_render *render, t_obj *shape)
{
	if (shape->reflect == SPEC)
	{
		ray->origin = ray->x;
		specular_reflect(&ray->direction, &ray->n);
		ray->depth++;
	}
	else if (shape->reflect == REFR)
	{
		ray->origin = ray->x;
		refractive_reflect(ray, render->xseed, shape);
		nmulti_(&ray->mask, ray->pr);
		ray->depth++;
	}
	else
	{
		ray->origin = ray->x;
		diffuse_reflect(&ray->direction, &ray->n, render->xseed);
		ray->depth++;
	}
}

t_vec			*specular_reflect(t_vec *d, t_vec *n)
{
	t_vec a;

	nmulti(n, 2.0 * dot(n, d), &a);
	sub_(d, &a);
	return (d);
}

void			diffuse_reflect(t_vec *d, t_vec *n, unsigned short xseed[3])
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

static void		refractive_stop(t_ray *ray, t_vec *d_re, double pr)
{
	ray->pr = pr;
	veccp(d_re, &ray->direction);
}

void			refractive_reflect(t_ray *ray, unsigned short xseed[3], \
									t_obj *obj)
{
	t_vec	vec[6];
	t_bool	out_to_in;
	double	doub[4];
	double	cos[2];

	veccp(&ray->direction, &vec[5]);
	vec[0] = *specular_reflect(&vec[5], &ray->n);
	out_to_in = dot(&ray->n, &ray->direction) < 0;
	out_to_in ? vec[1] = ray->n : minus(&ray->n, &vec[1]);
	doub[0] = out_to_in ? obj->index_out / obj->index_in : \
						obj->index_in / obj->index_out;
	cos[0] = dot(&ray->direction, &vec[1]);
	cos[1] = 1.0 - doub[0] * doub[0] * (1.0 - cos[0] * cos[0]);
	if (0.0 > cos[1])
		return (refractive_stop(ray, &vec[0], 1.0));
	multin(doub[0], &ray->direction, &vec[2]);
	nmulti(&vec[1], (doub[0] * cos[0] + sqrt(cos[1])), &vec[3]);
	sub(&vec[2], &vec[3], &vec[4]);
	norm(&vec[4]);
	doub[1] = 1.0 - (out_to_in ? -cos[0] : dot(&vec[4], &ray->n));
	doub[2] = schlick_reflectance(obj->index_out, obj->index_in, doub[1]);
	doub[3] = 0.25 + 0.5 * doub[2];
	if (erand48(xseed) < doub[3])
		return (refractive_stop(ray, &vec[0], (doub[2] / doub[3])));
	return (refractive_stop(ray, &vec[4], ((1.0 - doub[2]) / (1.0 - doub[3]))));
}
