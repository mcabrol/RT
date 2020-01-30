/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:07:05 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object	obj(int t, double r, double h, t_vec p, t_vec d, t_vec e, t_vec f, int reflect)
{
	t_object obj;

	obj.type = t;
	obj.radius = r;
	obj.height = h;
	obj.position = p;
	obj.direction = d;
	obj.emission = e;
	obj.reflection = f;
	obj.reflect = reflect;
	return (obj);
}
