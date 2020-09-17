/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/17 15:27:25 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			init_cam(t_rtv1 *rtv1)
{
	t_obj	*camera;
	t_scene *scene;

	scene = &rtv1->scene;
	camera = assign_camera(scene);
	if (camera)
	{
		if (set_camera(camera, rtv1))
			return (EXIT_FAILURE);
	}
	else
		set_default_camera(rtv1);
	build_camera(scene);
	return (EXIT_SUCCESS);
}

t_obj		*assign_camera(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->n)
		if (scene->obj[i].type == CAMERA)
			return (&scene->obj[i]);
	return (NULL);
}

int			set_camera(t_obj *camera, t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	veccp(&camera->position, &scene->cam.position);
	veccp(&camera->direction, &scene->cam.direction);
	norm(&scene->cam.direction);
	scene->cam.type = CAMERA;
	scene->cam.fov = deg_to_rad(camera->fov * 0.5);
	scene->cam.ambient = camera->ambient;
	scene->cam.environment.path = camera->environment.path;
	veccp(&camera->rotation, &scene->cam.rotation);
	if (camera->environment.path)
	{
		if (load_texture(rtv1, &rtv1->scene.cam))
			return (EXIT_FAILURE);
		scene->cam.environment.width /= 4.0;
		scene->cam.environment.height /= 3.0;
	}
	return (EXIT_SUCCESS);
}

void		set_default_camera(t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	vec(0, 0, 0, &scene->cam.position);
	vec(0, 0, -1, &scene->cam.direction);
	vec(0, 0, 0, &scene->cam.ambient);
	scene->cam.fov = deg_to_rad(30 * 0.5);
	scene->cam.environment.path = NULL;
}

void		build_camera(t_scene *scene)
{
	t_vec	up;
	double	half[2];
	t_vec	horizontal;
	t_vec	vertical;
	t_vec	tmp;

	vec(0, 1, 0, &up);
	half[0] = tan(scene->cam.fov);
	half[1] = ((double)scene->width / (double)scene->height) * half[0];
	cross(&scene->cam.direction, &up, &horizontal);
	norm(&horizontal);
	cross(&horizontal, &scene->cam.direction, &vertical);
	norm(&vertical);
	minus_(&vertical);
	sum(&scene->cam.position, &scene->cam.direction, &scene->cam.point);
	nmulti(&vertical, half[0], &tmp);
	sub_(&scene->cam.point, &tmp);
	nmulti(&horizontal, half[1], &tmp);
	sub_(&scene->cam.point, &tmp);
	nmulti(&horizontal, 2.0 * half[1], &scene->cam.cx);
	nmulti(&vertical, 2.0 * half[0], &scene->cam.cy);
	ndivide_(&scene->cam.cx, (double)scene->width);
	ndivide_(&scene->cam.cy, (double)scene->height);
}
