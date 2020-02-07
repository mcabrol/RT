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

t_obj		sphere(int t,
				   double r,
				   double h,
				   t_vec p,
				   t_vec d,
				   t_vec e,
				   t_vec c,
				   t_vec rot,
				   double a,
				   int cut,
				   int reflect)
{
	t_obj sphere;

	sphere.t = t;
	sphere.r = r;
	sphere.h = h;
	sphere.p = p;
	sphere.d = d;
	sphere.e = e;
	sphere.c = c;
	sphere.a = a;
	sphere.rot = rot;
	sphere.cut = cut;
	sphere.reflect = reflect;
	return (sphere);
}

void		cut_direction(t_obj *obj)
{
	if (obj->cut >= -3 && obj->cut <= 3 && obj->cut != 0)
	{
		if (obj->cut == 1 || obj->cut == -1)
			vec(1.0, 0.0, 0.0, &obj->cut_dir);
		else if (obj->cut == 2 || obj->cut == -2)
			vec(0.0, 1.0, 0.0, &obj->cut_dir);
		else if (obj->cut == 3 || obj->cut == -3)
			vec(0.0, 0.0, 1.0, &obj->cut_dir);
		if (obj->cut > 0)
			nmulti(&obj->cut_dir, -1.0, &obj->cut_dir);
	}
}

void		prepare_obj(t_obj *obj)
{
	if (obj->cut != 0 && obj->cut_dir.x == 0
	&& obj->cut_dir.y == 0 && obj->cut_dir.z == 0)
		cut_direction(obj);
	obj->d = rotate_vector(obj->rot, obj->d);
	obj->d = *norm(&obj->d);
	obj->cut_dir = rotate_vector(obj->rot, obj->cut_dir);
	obj->cut_dir = *norm(&obj->cut_dir);
	obj->cut_shift = rotate_vector(obj->rot, obj->cut_shift);
}
