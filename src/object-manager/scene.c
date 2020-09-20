/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 19:06:36 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				size_of(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static void		protect_color_spec(t_rtv1 *rtv1)
{
	int		i;

	i = 0;
	while (i < rtv1->scene.n)
	{
		if (rtv1->scene.obj[i].reflect == SPEC)
		{
			if (rtv1->scene.obj[i].color.x == 1.0)
				rtv1->scene.obj[i].color.x -= 0.01;
			if (rtv1->scene.obj[i].color.y == 1.0)
				rtv1->scene.obj[i].color.y -= 0.01;
			if (rtv1->scene.obj[i].color.z == 1.0)
				rtv1->scene.obj[i].color.z -= 0.01;
		}
		i = i + 1;
	}
}

int				init_scene(t_rtv1 *rtv1, char *file)
{
	t_scene *scene;

	scene = &rtv1->scene;
	if (rtv1->setter == FALSE)
	{
		if ((scene->obj_type = get_opt(OBJ_TYPE_STR)) == NULL)
			return (EXIT_FAILURE);
		if ((scene->obj_options = get_opt(OBJ_OPT_STR)) == NULL)
			return (EXIT_FAILURE);
		scene->obj_setter = setup_obj_setter(size_of(scene->obj_options));
		rtv1->setter = TRUE;
	}
	scene->cam.environment.path = NULL;
	if (scene->obj_type && scene->obj_options && scene->obj_setter)
	{
		if (parse(file, scene) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (prepare_obj(rtv1) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		protect_color_spec(rtv1);
	}
	return (EXIT_SUCCESS);
}

t_options_func	*setup_obj_setter(int nb_options)
{
	t_options_func *obj_setter;

	obj_setter = (t_options_func*)ft_memalloc(sizeof(t_options_func) \
					* nb_options);
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
	obj_setter[16] = &set_map;
	return (obj_setter);
}

int				prepare_obj(t_rtv1 *rtv1)
{
	int		i;
	t_scene	*scene;
	t_obj	*obj;

	i = -1;
	scene = &rtv1->scene;
	while (++i < scene->n)
	{
		obj = &scene->obj[i];
		if (obj->rotation.x != 0 || obj->rotation.y != 0 \
			|| obj->rotation.z != 0)
			obj->direction = rotate_point(deg_to_rad(obj->rotation.x),
							deg_to_rad(obj->rotation.y),
							deg_to_rad(obj->rotation.z),
							*norm(&obj->direction));
		else
			obj->direction = *norm(&obj->direction);
	}
	return (EXIT_SUCCESS);
}
