/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 20:12:22 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// t_vec		radiance(t_render *render, t_vec origin, t_vec direction)
// {
// 	t_radiance	radiance;
// 	t_vec		ambient;
// 	t_vec		blank;
// 	t_vec		mask;
// 	t_vec		accucolor;
// 	t_vec		p;
// 	t_vec		hitpoint;
// 	// t_vec		n;
// 	t_vec		nextdir;
// 	// t_vec 		hit;
// 	t_object	*shape;
// 	int			depth;
// 	t_vec		light;
// 	// t_vec		l;
// 	double		continue_probability;
// 	// t_vec		q;
//
// 	depth = 0;
// 	vec(0.0, 0.0, 0.0, &blank);
// 	vec(0.0, 0.0, 0.0, &ambient);
// 	vec(0.0, 0.0, 0.0, &hitpoint);
// 	vec(0.0, 0.0, 0.0, &nextdir);
// 	vec(0.0, 0.0, 0.0, &accucolor);
// 	vec(0.0, 0.0, 0.0, &light);
// 	vec(1.0, 1.0, 1.0, &mask);
// 	while (TRUE)
// 	{
// 		radiance.distance = T_MAX;
// 		intersect(&origin, &direction, &radiance, render);
// 		if (radiance.id < 0)
// 			return (blank);
// 		shape = &render->object[radiance.id];
// 		// if (shape->type == PLANE)
// 		// 	plane_normal(&radiance, &origin, &direction, shape);
// 		// else if (shape->type == SPHERE)
// 		// 	sphere_normal(&radiance, &origin, &direction, shape);
// 		// else if (shape->type == CYLINDER)
// 		// 	cylinder_normal(&radiance, &origin, &direction, shape);
//
//
// 		// // Texture
// 		// radiance.f = shape->reflection;
// 		//
// 		// // Light
// 		//
// 		// if (shape->reflect == DIFFUSE)
// 		// {
// 		// 	sum(&shape->emission, &radiance.f, &l);
// 		// 	multi(&mask, &l, &light);
// 		// 	sum_(&accucolor, &light);
// 		// }
// 		// else
// 		// {
// 		// 	multi(&mask, &shape->emission, &light);
// 		// 	sum_(&accucolor, &light);
// 		// }
// 		//
// 		//
// 		// sub(&mask, &shape->reflection, &radiance.f);
//
// 		eval(&origin, &direction, radiance.distance, &p);
// 		sub(&p, &shape->position, &radiance.n);
// 		norm(&radiance.n);
//
// 		multi(&mask, &shape->emission, &light);
// 		sum_(&accucolor, &light);
//
//
//
// 		multi_(&mask, &shape->reflection);
//
// 		if (4 < depth)
// 		{
// 			continue_probability = max(&shape->reflection);
// 			if (erand48(render->xseed) >= continue_probability)
// 				return (blank);
// 			ndivide_(&mask, continue_probability);
// 		}
//
// 		// sub(&mask, &shape->reflection, &radiance.f);
//
//
// 		// if (shape->reflect == DIFFUSE)
// 		// {
// 		// 	hitpoint = radiance.x;
// 		// 	nextdir = ideal_diffuse(&radiance, direction, render->xseed);
// 		// 	// multi_(&mask, &radiance.f);
// 		// 	origin = hitpoint;
// 		// 	direction = nextdir;
// 		// 	depth++;
// 		// 	break ;
// 		// }
// 		// else if (shape->reflect == SPECULAR)
// 		// {
// 		// 	hitpoint = radiance.x;
// 		// 	nextdir = specular_reflect(&direction, &radiance.n);
// 		// 	// multi_(&mask, &radiance.f);
// 		// 	origin = hitpoint;
// 		// 	direction = nextdir;
// 		// 	depth++;
// 		// 	break ;
// 		// }
//
// 		switch (shape->reflect) {
//
// 		case SPECULAR: {
// 			origin = p;
// 			direction = specular_reflect(&radiance.direction, &radiance.n);
// 			depth++;
// 			break;
// 		}
//
// 		default:
// 		{
// 			direction = ideal_diffuse(&radiance, direction, render->xseed);
// 			origin = p;
// 			depth++;
// 		}
// 		}
// 	}
// }

void		radiance(t_render *render, t_vec origin, t_vec direction, t_vec *color)
{
	t_radiance	radiance;
	// double		pr;
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
	t_object	*shape;

	radiance.depth = 0;
	vec(0.0, 0.0, 0.0, &blank);
	vec(1.0, 1.0, 1.0, &roll);
	while (TRUE) {
		radiance.distance = INFINITY;
		intersect(&origin, &direction, &radiance, render);
		if (radiance.id < 0)
			veccp(&blank, color);
		shape = &render->object[radiance.id];
		eval(&origin, &direction, INFINITY, &p);
		sub(&p, &shape->position, &n);
		norm(&n);
		multi(&roll, &shape->emission, &l);
		sum_(&blank, &l);
		multi_(&roll, &shape->reflection);

		// Russian roulette
		if (4u < (unsigned int)radiance.depth) {
			double continue_probability = max(&shape->reflection);
			if (erand48(render->xseed) >= continue_probability) {
				veccp(&blank, color);
				return ;
			}
			ndivide_(&roll, continue_probability);
		}

		// Next path segment
		switch (shape->reflect) {

		case SPECULAR: {
			origin = p;
			d = specular_reflect(&direction, &n);
			radiance.depth++;
			break;
		}

		default: {
			 if (0.0 > dot(&n, &direction))
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
			cosine_weighted_sample(erand48(render->xseed), erand48(render->xseed), &sample_d);
			nmulti(&u, sample_d.x, &_x);
			nmulti(&v, sample_d.y, &_y);
			nmulti(&w, sample_d.z, &_z);
			sum(&_x, &_y, &_xy);
			sum(&_xy, &_z, &d);
			origin = p;
			direction = *norm(&d);;
			radiance.depth++;
		}
		}
	}
}
