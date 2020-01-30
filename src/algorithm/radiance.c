/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:15:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		radiance(t_render *render, t_vec origin, t_vec direction, unsigned short xseed[3])
{
	t_radiance	radiance;
	t_vec		ambient;
	t_vec		blank;
	t_vec		mask;
	t_vec		accucolor;
	t_vec		hitpoint;
	t_vec		nextdir;
	t_vec 		hit;
	t_object	*shape;
	int			depth;
	t_vec		light;
	// t_vec		q;

	depth = 0;
	vec(0.0, 0.0, 0.0, &blank);
	vec(0.0, 0.0, 0.0, &ambient);
	vec(0.0, 0.0, 0.0, &hitpoint);
	vec(0.0, 0.0, 0.0, &nextdir);
	vec(0.0, 0.0, 0.0, &accucolor);
	vec(1.0, 1.0, 1.0, &mask);
	while (depth < 5)
	{
		radiance.distance = T_MAX;
		intersect(&origin, &direction, &radiance, render);
		if (radiance.id < 0)
			break ;
		shape = &render->object[radiance.id];
		if (shape->type == PLANE)
			plane_normal(&radiance, &origin, &direction, shape);
		else if (shape->type == SPHERE)
			sphere_normal(&radiance, &origin, &direction, shape);
		else if (shape->type == CYLINDER)
			cylinder_normal(&radiance, &origin, &direction, shape);



		// eval(r, r->tmax, &p);
		// sub(&p, &shape->p, &n);
		// norm(&n);
		// multiplication(&mask, &shape->e, &l);
		// sum_(&blank, &l);
		// multi_(&mask, &shape->f);

		// // Russian roulette mask
		// if (4u < (unsigned int)depth) {
		// 	double continue_probability = max(&shape->f);
		// 	if (erand48(rt->xseed) >= continue_probability) {
		// 		veccp(&blank, &rt->l_t);
		// 		return ;
		// 	}
		// 	ndivide_(&mask, continue_probability);
		// }

		// Light

		// sum(&shape->emission, &shape->reflection, &q);
		multi(&mask, &shape->emission, &light);
		sum_(&accucolor, &light);

		// Texture
		sub(&mask, &shape->reflection, &radiance.f);

		if (shape->reflect == DIFFUSE)
		{
			nmulti(&radiance.n, 0.001f, &hit);
			sum(&radiance.x, &hit, &hitpoint);
			nextdir = hemisphere_ray(&radiance, radiance.n, xseed, 1);
			multi_(&mask, &radiance.f);
		}
		else if (shape->reflect == SPECULAR)
		{
			nmulti(&radiance.n, 0.001f, &hit);
			sum(&radiance.x, &hit, &hitpoint);
			nextdir = mirror_refl(&radiance.n, &direction);
			multi_(&mask, &radiance.f);
		}
		origin = hitpoint;
		direction = nextdir;
		depth++;
	}
	return (accucolor);
}
