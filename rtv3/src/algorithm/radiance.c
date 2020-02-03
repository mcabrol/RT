/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/15 09:44:04 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void		radiance(t_scene *scene, t_ray *ray, t_algo *rt)
{
	t_ray		*r;
	size_t		id;
	double		pr;
	t_vec		p;
	t_vec		n;
	t_vec		light;
	t_vec		u;
	t_vec		v;
	t_vec		sample_d;
	t_vec		_x;
	t_vec		_y;
	t_vec		_z;
	t_vec		_xy;
	t_vec		d;
	t_vec		w;
	t_vec		blank;
	t_vec		mask;
	double 		continue_probability;
	t_sphere	*shape;

	r = ray;
	vec(0.0, 0.0, 0.0, &blank);
	vec(1.0, 1.0, 1.0, &mask);
	while (TRUE) {
		if (!intersect(r, &id, scene)) {
			veccp(&blank, &rt->color);
			return ;
		}
		shape = &scene->obj[id];

		// Next point
		eval(r, r->tmax, &p);

		// Norm object
		sub(&p, &shape->p, &n);
		norm(&n);

		// Light
		multiplication(&mask, &shape->e, &light);
		sum_(&blank, &light);

		// Textures
		multi_(&mask, &shape->f);

		// Russian roulette
		if (4u < (unsigned int)r->depth)
		{
			continue_probability = max(&shape->f);
			if (erand48(rt->xseed) >= continue_probability)
			{
				veccp(&blank, &rt->color);
				return ;
			}
			ndivide_(&mask, continue_probability);
		}

		// Next path segment
		switch (shape->reflect) {

		case SPEC: {
			r->o = p;
			specular_reflect(&r->d, &n, &r->d);
			r->tmin = EPSILON_SPHERE;
			r->tmax = INFINITY;
			r->depth++;
			break;
		}

		case REFR: {
			r->o = p;
			r->d = specular_transmit(&r->d, &n, REFRACTIVE_INDEX_OUT, REFRACTIVE_INDEX_IN, &pr, rt->xseed);
			nmulti_(&mask, pr);
			r->tmin = EPSILON_SPHERE;
			r->tmax = INFINITY;
			r->depth++;
			break;
		}

		default: {
			 if (0.0 > dot(&n, &r->d))
			 	w = n;
			else
				minus(&n, &w);
			t_vec _u = { 0.0, 0.0, 0.0 };
			if (fabs(w.x) > 0.1) {
				_u.y = 1.0;
			}
			else {
				_u.x = 1.0;
			}
			cross(&_u, &w, &u);
			norm(&u);
			cross(&w, &u, &v);
			cosine_weighted_sample(erand48(rt->xseed), erand48(rt->xseed), &sample_d);
			nmulti(&u, sample_d.x, &_x);
			nmulti(&v, sample_d.y, &_y);
			nmulti(&w, sample_d.z, &_z);
			sum(&_x, &_y, &_xy);
			sum(&_xy, &_z, &d);
			r->o = p;
			r->d = *norm(&d);;
			r->tmin = EPSILON_SPHERE;
			r->tmax = INFINITY;
			r->depth++;
		}
		}
	}
}
