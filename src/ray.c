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

t_ray	ray(t_vec o, t_vec d, double tmin, double tmax, int depth)
{
	t_ray ray;

	ray.o = o;
	ray.d = d;
	ray.tmin = tmin;
	ray.tmax = tmax;
	ray.depth = depth;
	return (ray);
}

t_vec	eval(t_ray *r, double t)
{
	t_vec dt;

	dt = nmulti(&r->d, t);
	return (sum(&r->o, &dt));
}

void	printr(t_ray *r)
{
	ft_printf("o: [%f %f %f]\nd: [%f %f %f]\n",
	r->o.x, r->o.y, r->o.z, r->d.x, r->d.y, r->d.z);
}

void	printv(t_vec *v)
{
	ft_printf("[%f %f %f]\n", v->x, v->y, v->z);
}
