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
	scene->obj[0] = sphere(PLANE, 1e5, 15.0,				// type // radius 		// RIGHT
					vecp(0.0, 40.8, 81.6), 				// position
					vecp(15.0, 0.0, 0.0), 				// direction
					vecp(0.0, 0.0, 0.0),				// emission
					vecp(0.75, 0.25, 0.25),				// color
					vecp(0.0, 0.0, 0.0),				// rotation
					0, PLUS_X, DIFF);					// material
	scene->obj[1] = sphere(PLANE, 1e5, 0.0,										// LEFT
					vecp(99.0, 40.8, 81.6),
					vecp(15.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.25, 0.75, 0.25),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[2] = sphere(PLANE, 1e5, 0.0,										// TOP
					vecp(50.0, 82.0, 1e5),
					vecp(0.0, 1.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.25, 0.25, 0.75),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[3] = sphere(PLANE, 1e5, 0.0,										// FLOOR
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 1.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.25, 0.75),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[4] = sphere(PLANE, 1e5, 0.0,										// BACK
					vecp(73.0, 16.5, 0.0),
					vecp(0.0, 0.0, -15.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.75, 0.25),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[5] = sphere(PLANE, 1e5, 0.0,										// FRONT
					vecp(73.0, 16.5, 180.0),
					vecp(0.0, 0.0, -15.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.25, 0.75, 0.75),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[6] = sphere(CONE, 10.0, 40.0,								// CONE
					vecp(50.0, 42.0, 50.0),
					vecp(0.0, -1.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.999, 0.999, 0.999),
					vecp(0.0, 0.0, 0.0),
					1.0, 0.0, SPEC);
	// scene->obj[7] = sphere(SPHERE, 30.0, 2.0,								// SPHERE
	// 				vecp(50.0, 30.0, 50.0),
	// 				vecp(0.0, 1.0, 0.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.999, 0.999, 0.999),
	// 				vecp(0.0, 0.0, 0.0),
	// 				0.0, 0.0, SPEC);
	scene->obj[7] = sphere(CYLINDER, 30.0, 2.0,								// BIG LIGHT CYL
					vecp(50.0, 81.0, 50.0),
					vecp(0.0, 1.0, 0.0),
					vecp(20.0, 20.0, 20.0),
					vecp(0.5, 0.5, 0.5),
					vecp(0.0, 0.0, 0.0),
					0.0, 0.0, DIFF);
	scene->obj[8] = sphere(CYLINDER, 15.0, 2.0,								// MIDDLE LIGHT CYL
					vecp(50.0, 81.0, 50.0),
					vecp(0.0, 1.0, 0.0),
					vecp(20.0, 20.0, 20.0),
					vecp(0.5, 0.5, 0.5),
					vecp(0.0, 0.0, 0.0),
					0.0, 0.0, DIFF);
	scene->obj[9] = sphere(CYLINDER, 5.0, 2.0,								// LITTLE LIGHT CYL
					vecp(50.0, 81.0, 50.0),
					vecp(0.0, 1.0, 0.0),
					vecp(20.0, 20.0, 20.0),
					vecp(0.5, 0.5, 0.5),
					vecp(0.0, 0.0, 0.0),
					0.0, 0.0, DIFF);

	// scene->obj[15] = sphere(SPHERE, 600, 0.0,
	// 				vecp(50.0, 681.6 - .27, 50.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(12.0, 12.0, 12.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				0, DIFF);													// LIGHT

	// prepare_obj(&scene->obj[0]);
	prepare_obj(&scene->obj[6]);
}
