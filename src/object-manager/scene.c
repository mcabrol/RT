/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/27 09:47:09 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	scene->obj_type = (char**)malloc(sizeof(char *) * OBJ_TYPE);
	if (scene->obj_type)
	{
		scene->obj_type[0] = ft_strdup("SPHERE");
		scene->obj_type[1] = ft_strdup("PLANE");
		scene->obj_type[2] = ft_strdup("CYLINDRE");
		scene->obj_type[3] = ft_strdup("CONE");
		scene->obj_type[4] = ft_strdup("BOX");
		scene->obj_type[5] = ft_strdup("CAMERA");
	}
	init_cam(&rtv1->scene);
}
