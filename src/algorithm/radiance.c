/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 18:55:01 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		radiance(t_rtv1 *rtv1, t_ray *ray)
{
	t_ray		*r;
	size_t		id;
	double		pr;
	t_vec		p;
	t_vec		n;
	t_vec		l;
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
	t_vec		roll;
	t_obj		*shape;

	r = ray;
	vec(0.0, 0.0, 0.0, &blank);
	vec(1.0, 1.0, 1.0, &roll);
	while (TRUE) {
		if (!intersect(r, &id, &rtv1->scene)) {
			veccp(&blank, &rtv1->rt.l_t);
			return ;
		}
		shape = &rtv1->scene.obj[id];
		eval(r, r->tmax, &p);
		sub(&p, &shape->p, &n);
		norm(&n);
		multiplication(&roll, &shape->e, &l);
		sum_(&blank, &l);
		multi_(&roll, &shape->f);

		// Russian roulette
		if (4u < (unsigned int)r->depth) {
			double continue_probability = max(&shape->f);
			if (erand48(rtv1->rt.xseed) >= continue_probability) {
				veccp(&blank, &rtv1->rt.l_t);
				return ;
			}
			ndivide_(&roll, continue_probability);
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
			r->d = specular_transmit(&r->d, &n, REFRACTIVE_INDEX_OUT, REFRACTIVE_INDEX_IN, &pr, rtv1->rt.xseed);
			nmulti_(&roll, pr);
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
			cosine_weighted_sample(erand48(rtv1->rt.xseed), erand48(rtv1->rt.xseed), &sample_d);
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
