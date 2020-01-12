/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	radiance(t_ray *ray, unsigned short xseed[3])
{
	t_ray		*r;
	t_vec		p;
	t_vec		n;
	t_vec		l1;
	t_vec		l2;
	t_vec		f;
	size_t		id;
	t_sphere	*shape;
	double		prob;
	double		pr;
	t_vec		w;
	t_vec		u;

	l1 = vec(0.0, 0.0, 0.0);
	f = vec(1.0, 1.0, 1.0);
	while (TRUE)
	{
		if (!intersect(r, &id))
			return (l1);
		shape = &sphere[id];
		p = eval(r, r->tmax);
		n = sub(&p, &shape->p);
		norm(&n);

		l2 = multi(&f, &shape->e);
		l1 = sum(&l1, &l2);
		f = multi(&f, &shape->f);

		if (4u < (unsigned)r->depth)
		{
			prob = max(&shape->f);
			if (erand48(xseed) >= prob)
				return (l1);
			f = ndivide(&f, prob);
		}

		if (shape->reflect = SPEC)
		{
			r->o = p;
			r->d = specular_reflect(&r->d, &n);
			r->tmin = EPSILON_SPHERE;
			r->tmax = INFINITY;
			r->depth++;
			break ;
		}
		else if (shape->reflect = REFR)
		{
			r->o = p;
			r->d = specular_transmit(&r->d, &n, REFRACTIVE_INDEX_OUT, REFRACTIVE_INDEX_IN, &pr, xseed);
			f = nmulti(&f, pr);
			r->tmin = EPSILON_SPHERE;
			r->tmax = INFINITY;
			r->depth++;
			break ;
		}
		else
		{
			w = (0.0 > dot(&n, &r->d)) ? n : minus(&n);
			u = vec(ZERO);
			if (fabs(w.x) > 0.1)
				u.y = 1.0;
			else
				u.x = 1.0;
			u = cross(&u, &w);
		}
	}
}
