/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/06 19:37:11 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	scene->samples = SAMPLES / 4;
	scene->n = sizeof(scene->obj) / sizeof(t_obj);

	scene->obj[0] = obj(SPHERE,							// type
					30.0,								// radius
					0.0,								// height
					vecp(50.0, 30.0, 50.0), 			// position
					vecp(0.0, 1.0, 0.0), 				// direction
					vecp(12.0, 12.0, 12.0),				// emission
					vecp(0.0, 0.0, 1.0),				// color
					vecp(0.0, 0.0, 0.0),				// rotation
					0,									// Angle
					0,									// Cut direction
					0, 0, 0,							// Box rect
					DIFF);								// material

	scene->obj[1] = obj(BOX,							// type
					0.0,								// radius
					0.0,								// height
					vecp(0.0, 0.0, 0.0), 				// position
					vecp(0.0, 1.0, 0.0), 				// direction
					vecp(0.0, 0.0, 0.0),				// emission
					vecp(0.999, 0.999, 0.999),			// color
					vecp(0.0, 0.0, 0.0),				// rotation
					0,									// Angle
					0,									// Cut direction
					100.0, 100.0, 300.0,				// Box rect
					DIFF);								// material

	prepare_obj(&scene->obj[0]);
	prepare_obj(&scene->obj[1]);
}
