/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 10:32:38 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	scene->obj_type = ft_strsplit("SPHERE PLANE CYLINDER CONE BOX CAMERA", ' ');
	scene->obj_options = ft_strsplit("POSITION DIRECTION EMISSION COLOR", ' ');
	scene->obj_setter = setup_obj_setter(&scene->obj_setter);
	if (scene->obj_setter)
		ft_printf("Alright!\n");
	if (scene->obj_type)
	{

	}
	init_cam(&rtv1->scene);
}

options_func *setup_obj_setter(void)
{
	options_func *obj_setter;

	obj_setter = (options_func*)ft_memalloc(sizeof(options_func) * 4);
	// if (!obj_setter)
	// 	throw_error();
	obj_setter[0] = &set_position;
	obj_setter[1] = &set_direction;
	obj_setter[2] = &set_emission;
	obj_setter[3] = &set_color;
}
