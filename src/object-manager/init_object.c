/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 15:21:35 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		obj(int t, double r, t_vec p, t_vec e, t_vec f, int reflect)
{
	t_obj obj;

	obj.t = t;
	obj.r = r;
	obj.p = p;
	obj.e = e;
	obj.f = f;
	obj.reflect = reflect;
	return (obj);
}

t_obj		plan(double r, t_vec p, t_vec e, t_vec f, int reflect)
{
	t_obj obj;

	obj.r = r;
	obj.t = PLAN;
	obj.p = p;
	obj.e = e;
	obj.f = f;
	obj.reflect = reflect;
	return (obj);
}
