/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 19:19:49 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cam(t_scene *scene)
{
	int		i;
	t_obj	*obj;

	i = 0;
	obj = NULL;
	while (i < scene->n)
	{
		if (scene->obj[i].type == CAMERA)
			obj = &scene->obj[i];
		i = i + 1;
	}
	if (obj)
	{
		veccp(&obj->position, &scene->cam.position);
		veccp(&obj->direction, &scene->cam.direction);
		norm(&scene->cam.direction);
		scene->cam.fov = deg_to_rad(obj->fov * 0.5);
		scene->cam.ambient = obj->ambient;
	}
	else
	{
		vec(0, 0, 0, &scene->cam.position);
		vec(0, 0, -1, &scene->cam.direction);
		scene->cam.fov = deg_to_rad(FOV * 0.5);
		vec(0, 0, 0, &scene->cam.ambient);
	}
	build_camera(scene);
}

void 		build_camera(t_scene *scene)
{
	t_vec	up;
	double	half_height;
	double	half_width;
	t_vec 	horizontal;
	t_vec 	vertical;
	t_vec	tmp;

	vec(0, 1, 0, &up);

	half_height = tan(scene->cam.fov);
	half_width = ((double)scene->width / (double)scene->height) * half_height;

	cross(&scene->cam.direction, &up, &horizontal);
	norm(&horizontal);

	cross(&horizontal, &scene->cam.direction, &vertical);
	norm(&vertical);
	minus_(&vertical);

	sum(&scene->cam.position, &scene->cam.direction, &scene->cam.point);

	nmulti(&vertical, half_height, &tmp);
	sub_(&scene->cam.point, &tmp);

	nmulti(&horizontal, half_width, &tmp);
	sub_(&scene->cam.point, &tmp);

	nmulti(&horizontal, 2.0 * half_width, &scene->cam.cx);
	nmulti(&vertical, 2.0 * half_height, &scene->cam.cy);

	ndivide_(&scene->cam.cx, (double)scene->width);
	ndivide_(&scene->cam.cy, (double)scene->height);
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
	// if (obj->cut != 0 && obj->cut_direction.x == 0
	// && obj->cut_direction.y == 0 && obj->cut_direction.z == 0)
	// 	cut_direction(obj);
	if (obj->rotation.x > 0 || obj->rotation.y > 0 || obj->rotation.z > 0)
	{
		obj->direction = rotate_point(deg_to_rad(obj->rotation.x),
	 				 deg_to_rad(obj->rotation.y),
					 deg_to_rad(obj->rotation.z),
					 *norm(&obj->direction));
	}
	else
		obj->direction = *norm(&obj->direction);
	// obj->direction = *norm(&obj->direction);
	// obj->cut_direction = rotate_vector(obj->rotation, obj->cut_direction);
	// obj->cut_direction = *norm(&obj->cut_direction);
	// obj->cut_shift = rotate_vector(obj->rotation, obj->cut_shift);
}

void 		print_obj(t_obj *obj)
{
	ft_printf("TYPE : %d\n", obj->type);
	ft_printf("RADIUS : %f\n", obj->radius);
	ft_printf("POSITION : ");
	printv(&obj->position);
	ft_printf("DIRECTION : ");
	printv(&obj->direction);
	ft_printf("COLOR : ");
	printv(&obj->color);
	// ft_printf("COLOR : %#.8X\n", obj->color);
	ft_printf("EMISSION : ");
	printv(&obj->emission);
	ft_printf("REFLECTION : %d\n", obj->reflect);
	ft_printf("ANGLE : %f\n", obj->angle);
	ft_printf("HEIGHT : %f\n", obj->height);
	ft_printf("WIDTH : %f\n", obj->width);
	ft_printf("DEPTH : %f\n", obj->depth);
}
