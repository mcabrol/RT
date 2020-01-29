/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/28 18:56:07 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		radiance(t_rtv1 *rtv1, t_ray *ray, unsigned int seed)
{
	t_radiance	radiance;
	t_ray		*r;
	int			id;
	// double		pr;
	// t_vec		p;
	// t_vec		n;
	// t_vec		u;
	// t_vec		v;
	// t_vec		sample_d;
	// t_vec		_x;
	// t_vec		_y;
	// t_vec		_z;
	// t_vec		_xy;
	// t_vec		d;
	// t_vec		w;
	t_vec		blank;
	t_vec		mask;
	t_vec		accucolor;
	t_vec		hitpoint;
	t_vec		nextdir;
	t_vec		tmp;
	t_vec 		ntmp;
	t_obj		*shape;
	int			ddd;
	int			depth;

	r = ray;
	depth = 0;
	vec(0.0, 0.0, 0.0, &blank);
	vec(0.0, 0.0, 0.0, &hitpoint);
	vec(0.0, 0.0, 0.0, &nextdir);
	vec(0.0, 0.0, 0.0, &accucolor);
	vec(1.0, 1.0, 1.0, &mask);
	ddd = 5;
	while (depth < ddd)
	{
		radiance.distance = T_MAX;
		intersect(r, &radiance, &id, &rtv1->scene);
		if (id < 0)
			break ;
		shape = &rtv1->scene.obj[id];
		if (shape->t == PLAN)
			plane_normal(r, &radiance, shape);
		else if (shape->t == SPHERE)
			sphere_normal(r, &radiance, shape);

		// eval(r, r->tmax, &p);
		// sub(&p, &shape->p, &n);
		// norm(&n);
		// multiplication(&mask, &shape->e, &l);
		// sum_(&blank, &l);
		// multi_(&mask, &shape->f);

		// Russian roulette
		// if (4u < (unsigned int)r->depth) {
		// 	double continue_probability = max(&shape->f);
		// 	if (erand48(rt->xseed) >= continue_probability) {
		// 		veccp(&blank, &rt->l_t);
		// 		return ;
		// 	}
		// 	ndivide_(&mask, continue_probability);
		// }


		multiplication(&mask, &shape->e, &tmp);
		sum_(&accucolor, &tmp);

		if (shape->reflect == DIFFUSE)
		{
			nmulti(&radiance.n, 0.001, &ntmp);
			sum(&radiance.x, &ntmp, &hitpoint);
			nextdir = hemisphere_ray(&radiance, radiance.n, seed, 1);
			multi_(&mask, &radiance.f);
		}
		ray->o = hitpoint;
		ray->d = nextdir;
		depth++;
	}
	return (accucolor);
}
