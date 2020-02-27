/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/27 14:55:26 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		obj(int t,
				   double r,
				   double h,
				   t_vec p,
				   t_vec d,
				   t_vec e,
				   t_vec c,
				   t_vec rot,
				   double a,
				   int cut,
				   double ca,
				   double cb,
				   double cc,
				   int reflect)
{
	t_obj obj;

	obj.type = t;
	obj.radius = r;
	obj.height = h;
	obj.position = p;
	obj.direction = d;
	obj.emission = e;
	obj.color = c;
	obj.angle = a;
	obj.rotation = rot;
	obj.cut = cut;
	obj.a = ca,
	obj.b = cb,
	obj.c = cc,
	obj.reflect = reflect;
	return (obj);
}

void	init_cam(t_scene *scene)
{
	vec(0, 0, 0, &scene->cam.position);
	vec(0, 0, -1, &scene->cam.direction);
	norm(&scene->cam.direction);
	scene->cam.fov = 30 * M_PI / 180;
	vec(scene->width * scene->cam.fov / scene->height, 0.0, 0.0, &scene->cam.cx);
	cross(&scene->cam.cx, &scene->cam.direction, &scene->cam.cy);
	norm(&scene->cam.cy);
	nmulti_(&scene->cam.cy, scene->cam.fov);
}

void 		obj_default(t_obj *obj)
{
	vec(0.0, 0.0, 0.0, &obj->position);
	vec(0.0, 0.0, 0.0, &obj->direction);
	vec(0.0, 0.0, 0.0, &obj->emission);
	vec(0.0, 0.0, 0.0, &obj->color);
	vec(0.0, 0.0, 0.0, &obj->rotation);
	obj->type = 0;
	obj->reflect = 0;
	obj->radius = 0.0;
	obj->height = 0.0;
	obj->angle = 0.0;
	obj->cut = 0;
	obj->a = 0.0;
	obj->b = 0.0;
	obj->c = 0.0;
}

void		cut_direction(t_obj *obj)
{
	if (obj->cut >= -3 && obj->cut <= 3 && obj->cut != 0)
	{
		if (obj->cut == 1 || obj->cut == -1)
			vec(1.0, 0.0, 0.0, &obj->cut_direction);
		else if (obj->cut == 2 || obj->cut == -2)
			vec(0.0, 1.0, 0.0, &obj->cut_direction);
		else if (obj->cut == 3 || obj->cut == -3)
			vec(0.0, 0.0, 1.0, &obj->cut_direction);
		if (obj->cut > 0)
			nmulti(&obj->cut_direction, -1.0, &obj->cut_direction);
	}
}

void		prepare_obj(t_obj *obj)
{
	if (obj->cut != 0 && obj->cut_direction.x == 0
	&& obj->cut_direction.y == 0 && obj->cut_direction.z == 0)
		cut_direction(obj);
	obj->direction = rotate_vector(obj->rotation, obj->direction);
	obj->direction = *norm(&obj->direction);
	obj->cut_direction = rotate_vector(obj->rotation, obj->cut_direction);
	obj->cut_direction = *norm(&obj->cut_direction);
	obj->cut_shift = rotate_vector(obj->rotation, obj->cut_shift);
}

t_vec 		to_vec(int hex)
{
	int r;
	int g;
	int b;
	t_vec color;

	r = (hex >> 16) & 0xFF;
	g = (hex >> 8) & 0xFF;
	b = hex & 0xFF;
	vec((double)b / 255, (double)g / 255, (double)r / 255, &color);
	return (color);
}

void print_obj(t_obj *obj)
{
	ft_printf("TYPE : %d\n", obj->type);
	ft_printf("RADIUS : %f\n", obj->radius);
	ft_printf("POSITION : ");
	printv(&obj->position);
	ft_printf("DIRECTION : ");
	printv(&obj->direction);
	ft_printf("COLOR : ");
	printv(&obj->color);
	ft_printf("EMISSION : ");
	printv(&obj->emission);
}
