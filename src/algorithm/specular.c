/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/17 18:57:22 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		specular(t_ray *ray, t_render *render, t_obj *shape)
{
	if (shape->reflect == SPEC) {
		ray->origin = ray->x;
		specular_reflect(&ray->direction, &ray->n);
		ray->depth++;
	}
	else
	{
		ray->origin = ray->x;
		specular_diffuse(&ray->direction, &ray->n, render->xseed);
		ray->depth++;
	}
}

void		specular_reflect(t_vec *d, t_vec *n)
{
	t_vec a;

	nmulti(n, 2.0 * dot(n, d), &a);
	sub_(d, &a);
}

void 		specular_diffuse(t_vec *d, t_vec *n, unsigned short xseed[3])
{
	t_vec _u;
	t_vec u;
	t_vec w;
	t_vec v;
	t_vec _x;
	t_vec _y;
	t_vec _z;
	t_vec _xy;
	t_vec sample_d;

	vec(0.0, 0.0, 0.0, &_u);
	if (0.0 > dot(n, d))
		w = *n;
	else
	 	minus(n, &w);
	if (fabs(w.x) > 0.1)
	   _u.y = 1.0;
	else
	   _u.x = 1.0;
   cross(&_u, &w, &u);
   norm(&u);
   cross(&w, &u, &v);
   cosine_weighted_sample(erand48(xseed), erand48(xseed), &sample_d);
   nmulti(&u, sample_d.x, &_x);
   nmulti(&v, sample_d.y, &_y);
   nmulti(&w, sample_d.z, &_z);
   sum(&_x, &_y, &_xy);
   sum(&_xy, &_z, d);
   norm(d);
}
