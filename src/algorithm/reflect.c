/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:44:35 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/17 17:29:40 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		reflect(t_ray *ray, t_render *render, t_obj *shape)
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

t_vec		*specular_reflect(t_vec *d, t_vec *n)
{
	t_vec a;

	nmulti(n, 2.0 * dot(n, d), &a);
	sub_(d, &a);
	return (d);
}

void		diffuse_reflect(t_vec *d, t_vec *n, unsigned short xseed[3])
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

static void refractive_stop(t_ray *ray, t_vec *d_re, double pr)
{
	ray->pr = pr;
	veccp(d_re, &ray->direction);
	return ;
}

void		refractive_reflect(t_ray *ray, unsigned short xseed[3], t_obj *obj)
{
	t_vec 	d_re;
	BOOL	out_to_in;
	t_vec 	nl;
	double 	nn;
	double	cos_theta;
	double	cos2_phi;
	t_vec	a;
	t_vec	b;
	t_vec	d_tr;
	double	c;
	double	re;
	double	p_re;
	t_vec	d_tmp;

	veccp(&ray->direction, &d_tmp);
	d_re = *specular_reflect(&d_tmp, &ray->n);
	out_to_in = dot(&ray->n, &ray->direction) < 0;
	if (out_to_in)
		nl = ray->n;
	else
		minus(&ray->n, &nl);
	nn = out_to_in ? obj->index_out / obj->index_in : \
	obj->index_in / obj->index_out;
	cos_theta = dot(&ray->direction, &nl);
	cos2_phi = 1.0 - nn * nn * (1.0 - cos_theta * cos_theta);
	if (0.0 > cos2_phi)
		return (refractive_stop(ray, &d_re, 1.0));
	multin(nn, &ray->direction, &a);
	nmulti(&nl, (nn * cos_theta + sqrt(cos2_phi)), &b);
	sub(&a, &b, &d_tr);
	norm(&d_tr);
	c = 1.0 - (out_to_in ? -cos_theta : dot(&d_tr, &ray->n));
	re = schlick_reflectance(obj->index_out, obj->index_in, c);
	p_re = 0.25 + 0.5 * re;
	if (erand48(xseed) < p_re)
		return (refractive_stop(ray, &d_re, (re / p_re)));
	else
		return (refractive_stop(ray, &d_tr, ((1.0 - re) / (1.0 - p_re))));
}
