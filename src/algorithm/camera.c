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

void		init_cam(t_rtv1 *rtv1)
{
	t_obj	*camera;
	t_scene *scene;

	scene = &rtv1->scene;
	camera = assign_camera(scene);
	if (camera)
		set_camera(camera, rtv1);
	else
		set_default_camera(rtv1);
	build_camera(scene);
}

t_obj		*assign_camera(t_scene *scene)
{
	int 	i;

	i = -1;
	while (++i < scene->n)
		if (scene->obj[i].type == CAMERA)
			return (&scene->obj[i]);
	return (NULL);
}

void 		set_camera(t_obj *camera, t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	veccp(&camera->position, &scene->cam.position);
	veccp(&camera->direction, &scene->cam.direction);
	norm(&scene->cam.direction);
	scene->cam.fov = deg_to_rad(camera->fov * 0.5);
	scene->cam.ambient = camera->ambient;
	if (camera->environment.path)
	{
		load_texture(rtv1, camera->environment.path, &scene->cam.environment);
		scene->cam.environment.width /= 4.0;
		scene->cam.environment.height /= 3.0;
	}
}

void 		set_default_camera(t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	vec(0, 0, 0, &scene->cam.position);
	vec(0, 0, -1, &scene->cam.direction);
	vec(0, 0, 0, &scene->cam.ambient);
	scene->cam.fov = deg_to_rad(30 * 0.5);
	scene->cam.environment.path = NULL;
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
