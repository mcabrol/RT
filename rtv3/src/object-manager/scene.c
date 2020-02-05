/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/04 18:14:08 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_rtv1 *rtv1)
{
	t_scene *scene;

	scene = &rtv1->scene;
	scene->samples = SAMPLES / 4;
	scene->obj[0] = sphere(PLANE, 1e5, 0.0,					// type // radius 		// RIGHT
					vecp(1.0, 40.8, 81.6), 				// position
					vecp(15.0, 0.0, 0.0), 				// direction
					vecp(0.0, 0.0, 0.0),				// emission
					vecp(0.5, 0.5, 0.5),				// color
					0, 0, DIFF);								// material
	scene->obj[1] = sphere(PLANE, 1e5, 0.0,											// LEFT
					vecp(99.0, 40.8, 81.6),
					vecp(15.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.5, 0.5, 0.5),
					0, 0, DIFF);
	scene->obj[2] = sphere(PLANE, 1e5, 0.0,											// TOP
					vecp(50.0, 82.0, 1e5),
					vecp(0.0, 1.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.5, 0.5, 0.5),
					0, 0, DIFF);
	scene->obj[3] = sphere(PLANE, 1e5, 0.0,											// FLOOR
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 1.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.5, 0.5, 0.5),
					0, 0, DIFF);
	scene->obj[4] = sphere(PLANE, 1e5, 0.0,											// BACK
					vecp(73.0, 16.5, 0.0),
					vecp(0.0, 0.0, -15.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75,0.25,0.25),
					0, 0, DIFF);
	scene->obj[5] = sphere(PLANE, 1e5, 0.0,											// FRONT
					vecp(73.0, 16.5, 180.0),
					vecp(0.0, 0.0, -15.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.25,0.25,0.75),
					0, 0, DIFF);
	scene->obj[6] = sphere(CONE, 7.0, 50.0,										// SPHERE
					vecp(50.0, 35.0, 47.0),
					vecp(1.0, 1.0, 4.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.5, 0.5, 0.5),
					25.0, 1, SPEC);
	scene->obj[7] = sphere(CYLINDER, 5.0, 0.0,									// CYLINDER LEFT TOP
					vecp(99.0, 82.0, 0.0),
					vecp(0.0, 0.0, 1.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[8] = sphere(CYLINDER, 5.0, 0.0,									// CYLINDER RIGHT TOP
					vecp(0.0, 82.0, 0.0),
					vecp(0.0, 0.0, 1.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.25, 0.25, 0.25),
					0, 0, DIFF);
	scene->obj[9] = sphere(CYLINDER, 5.0, 0.0,									// CYLINDER LEFT BOTTOM
					vecp(99.0, 0.0, 0.0),
					vecp(0.0, 0.0, 1.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.0, 0.0, 0.0),
					0, 0, DIFF);
	scene->obj[10] = sphere(CYLINDER, 5.0, 0.0,									// CYLINDER RIGHT BOTTOM
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 1.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.25, 0.25, 0.25),
					0, 0, DIFF);
	// scene->obj[8] = sphere(SPHERE, 600, 0.0,
	// 				vecp(50.0, 681.6 - .27, 50.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(12.0, 12.0, 12.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				0, DIFF); 														// LIGHT
}
