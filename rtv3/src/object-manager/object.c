/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 16:47:28 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		sphere(int t, double r, t_vec p, t_vec d, t_vec e, t_vec c, int reflect)
{
	t_obj sphere;

	sphere.t = t;
	sphere.r = r;
	sphere.p = p;
	sphere.d = d;
	sphere.e = e;
	sphere.c = c;
	sphere.reflect = reflect;
	return (sphere);
}
