/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 19:15:05 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_rtv1 *rtv1, char *file)
{
	t_scene *scene;
	int		i;

	scene = &rtv1->scene;
	scene->obj_type = ft_strsplit("SPHERE PLANE CYLINDER CONE BOX CAMERA", ' ');
	scene->obj_options = ft_strsplit("POSITION DIRECTION EMISSION COLOR REFLECTION RADIUS ANGLE HEIGHT WIDTH DEPTH FOV AMBIENT ROTATION TEXTURE SCALE INDEX RIGHT LEFT TOP BOTTOM FRONT BACK", ' ');
	scene->obj_setter = setup_obj_setter();
	if (scene->obj_type && scene->obj_options && scene->obj_setter)
		parse(file, scene);
	// if (scene->m)
	// 	free(scene->m);
	// set_camera_matrix(scene);
	// matrix_print(scene->m, WOLFRAM);
	i = 0;
	while (i < scene->n)
	{
		if (scene->obj[i].texture.path)
			load_texture(rtv1, scene->obj[i].texture.path, &scene->obj[i].texture);
		prepare_obj(&scene->obj[i]);
		i = i + 1;
	}
}

options_func *setup_obj_setter(void)
{
	options_func *obj_setter;

	obj_setter = (options_func*)ft_memalloc(sizeof(options_func) * 22);
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
	obj_setter[10] = &set_fov;
	obj_setter[11] = &set_ambient;
	obj_setter[12] = &set_rotation;
	obj_setter[13] = &set_texture;
	obj_setter[14] = &set_texture_scale;
	obj_setter[15] = &set_index;
	obj_setter[16] = &set_right;
	obj_setter[17] = &set_left;
	obj_setter[18] = &set_top;
	obj_setter[19] = &set_bottom;
	obj_setter[20] = &set_front;
	obj_setter[21] = &set_back;

	return (obj_setter);
}
