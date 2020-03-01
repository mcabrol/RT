/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 11:58:10 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_rtv1 *rtv1, char *file)
{
	t_scene *scene;
	int		i;

	scene = &rtv1->scene;
	scene->obj_type = ft_strsplit("SPHERE PLANE CYLINDER CONE BOX CAMERA", ' ');
	scene->obj_options = ft_strsplit("POSITION DIRECTION EMISSION COLOR REFLECTION RADIUS ANGLE HEIGHT WIDTH DEPTH", ' ');
	scene->obj_setter = setup_obj_setter();
	if (scene->obj_type && scene->obj_options && scene->obj_setter)
		parse(file, scene);
	init_cam(&rtv1->scene);
	i = 0;
	while (i < scene->n)
	{
		prepare_obj(&scene->obj[i]);
		i = i + 1;
	}
	// prepare_obj(&scene->obj[0]);
	// prepare_obj(&scene->obj[1]);
	// prepare_obj(&scene->obj[2]);
	// prepare_obj(&scene->obj[3]);
}

options_func *setup_obj_setter(void)
{
	options_func *obj_setter;

	obj_setter = (options_func*)ft_memalloc(sizeof(options_func) * 6);
	// if (!obj_setter)
	// 	throw_error();
	obj_setter[0] = &set_position;
	obj_setter[1] = &set_direction;
	obj_setter[2] = &set_emission;
	obj_setter[3] = &set_color;
	obj_setter[4] = &set_reflection;
	obj_setter[5] = &set_radius;
	obj_setter[6] = &set_angle;
	obj_setter[7] = &set_height;
	obj_setter[8] = &set_width;
	obj_setter[9] = &set_depth;
	return (obj_setter);
}
