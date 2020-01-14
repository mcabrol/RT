/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/13 20:00:18 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// t_vec	radiance(t_ray *ray, unsigned short xseed[3])
// {
// 	t_ray		*r;
// 	t_vec		p;
// 	t_vec		n;
// 	t_vec		l1;
// 	t_vec		l2;
// 	t_vec		f;
// 	size_t		id;
// 	t_sphere	*shape;
// 	double		prob;
// 	double		pr;
// 	t_vec		w;
// 	t_vec		u;
// 	t_vec		v;
// 	t_vec		x;
// 	t_vec		y;
// 	t_vec		z;
// 	t_vec		xy;
// 	t_vec		d;
// 	t_vec		sample;
// 	t_sphere	obj[8];
//
// 	obj[0] = sphere(1e5,
// 					vec(1e5 + 1.0, 40.8, 81.6),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.75, 0.25, 0.25),
// 					DIFF);
// 	obj[1] = sphere(1e5,
// 					vec(-1e5 + 99.0, 40.8, 81.6),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.25, 0.25, 0.75),
// 					DIFF);
// 	obj[2] = sphere(1e5,
// 					vec(50.0, 40.8, 1e5),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.75, 0.75, 0.75),
// 					DIFF);
// 	obj[3] = sphere(1e5,
// 					vec(50.0, 40.8, -1e5 + 170.0),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.75, 0.75, 0.75),
// 					DIFF);
// 	obj[4] = sphere(1e5,
// 					vec(50.0, 1e5, 81.6),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.75, 0.75, 0.75),
// 					DIFF);
// 	obj[5] = sphere(1e5,
// 					vec(50.0, -1e5 + 81.6, 81.6),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.75, 0.75, 0.75),
// 					DIFF);
// 	obj[6] = sphere(16.5,
// 					vec(27.0, 16.5, 47.0),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.999, 0.999, 0.999),
// 					SPEC);
// 	obj[6] = sphere(16.5,
// 					vec(73.0, 16.5, 78.0),
// 					vec(0.0, 0.0, 0.0),
// 					vec(0.999, 0.999, 0.999),
// 					REFR);
// 	obj[7] = sphere(600,
// 					vec(50.0, 681.6 - .27, 81.6),
// 					vec(12.0, 12.0, 12.0),
// 					vec(0.0, 0.0, 0.0),
// 					DIFF);
// 	pr = 0.0;
// 	l1 = vec(0.0, 0.0, 0.0);
// 	f = vec(1.0, 1.0, 1.0);
// 	r = ray;
// 	while (1)
// 	{
// 		if (!intersect(r, &id))
// 			return (l1);
// 		shape = &obj[id];
// 		p = eval(r, r->tmax);
// 		n = sub(&p, &shape->p);
// 		norm(&n);
// 		l2 = multi(&f, &shape->e);
// 		l1 = sum(&l1, &l2);
// 		f = multi(&f, &shape->f);
//
// 		if (4u < (unsigned int)r->depth)
// 		{
// 			prob = max(&shape->f);
// 			if (erand48(xseed) >= prob)
// 				return (l1);
// 			f = ndivide(&f, prob);
// 		}
//
// 		if (shape->reflect == SPEC)
// 		{
// 			// ft_printf("hit SPECULAR\n");
// 			r->o = p;
// 			r->d = specular_reflect(&r->d, &n);
// 			r->tmin = EPSILON_SPHERE;
// 			r->tmax = INFINITY;
// 			r->depth++;
// 			break ;
// 		}
// 		else if (shape->reflect == REFR)
// 		{
// 			// ft_printf("hit REFRACTION\n");
// 			r->o = p;
// 			r->d = specular_transmit(&r->d, &n, REFRACTIVE_INDEX_OUT, REFRACTIVE_INDEX_IN, &pr, xseed);
// 			f = nmulti(&f, pr);
// 			r->tmin = EPSILON_SPHERE;
// 			r->tmax = INFINITY;
// 			r->depth++;
// 			break ;
// 		}
// 		else
// 		{
// 			// ft_printf("hit DIFFUSE\n");
// 			w = (0.0 > dot(&n, &r->d)) ? n : minus(&n);
// 			u = vec(0.0, 0.0, 0.0);
// 			if (fabs(w.x) > 0.1)
// 				u.y = 1.0;
// 			else
// 				u.x = 1.0;
// 			u = cross(&u, &w);
// 			norm(&u);
// 			v = cross(&w, &u);
// 			sample = cosine_weighted_sample(erand48(xseed), erand48(xseed));
// 			x = nmulti(&u, sample.x);
// 			y = nmulti(&v, sample.y);
// 			z = nmulti(&w, sample.z);
// 			xy = sum(&x, &y);
// 			d = sum(&xy, &z);
// 			r->o = p;
// 			r->d = *norm(&d);
// 			r->tmin = EPSILON_SPHERE;
// 			r->tmax = INFINITY;
// 			r->depth++;
// 			break ;
// 		}
// 	}
// 	ft_printf("### YOOOOOOO ###\n");
// }

void		radiance(t_scene *scene, t_ray *ray, unsigned short xseed[3], t_vec *dest)
{
	t_ray *r = ray;
	t_vec p;
	t_vec n;
	t_vec l;
	t_vec u;
	t_vec v;
	t_vec sample_d;
	t_vec _x;
	t_vec _y;
	t_vec _z;
	t_vec _xy;
	t_vec d;
	t_vec w;
	t_vec L = { 0.0, 0.0, 0.0 };
	t_vec F = { 1.0, 1.0, 1.0 };

	while (TRUE) {
		size_t id;
		if (!intersect(r, &id, scene)) {
			veccp(&L, dest);
			return ;
		}

		t_sphere *shape = &scene->obj[id];
		eval(r, r->tmax, &p);
		sub(&p, &shape->p, &n);
		norm(&n);

		multi(&F, &shape->e, &l);
		sum_(&L, &l);
		multi_(&F, &shape->f);

		// Russian roulette
		if (4u < (unsigned int)r->depth) {
			double continue_probability = max(&shape->f);
			if (erand48(xseed) >= continue_probability) {
				veccp(&L, dest);
				return ;
			}
			ndivide_(&F, continue_probability);
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
			double pr;
			r->d = specular_transmit(&r->d, &n, REFRACTIVE_INDEX_OUT, REFRACTIVE_INDEX_IN, &pr, xseed);
			nmulti_(&F, pr);
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
			cosine_weighted_sample(erand48(xseed), erand48(xseed), &sample_d);
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
