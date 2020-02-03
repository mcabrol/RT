/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/17 22:11:32 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_scene *scene)
{
	scene->samples = SAMPLES / 4;
	// scene->obj[0] = sphere(1e5,
	// 				vecp(1e5 + 1.0, 40.8, 81.6),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.75, 0.25, 0.25),
	// 				DIFF); // Left
	// scene->obj[1] = sphere(1e5,
	// 				vecp(-1e5 + 99.0, 40.8, 81.6),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.25, 0.25, 0.75),
	// 				DIFF); // Right
	scene->obj[0] = sphere(SPHERE, 1e5,
					vecp(50.0, 40.8, 1e5),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.75, 0.75),
					DIFF); //Back
	scene->obj[1] = sphere(SPHERE, 1e5,
					vecp(50.0, 40.8, -1e5 + 170.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					DIFF); //Front
	scene->obj[2] = sphere(SPHERE, 1e5,
					vecp(50.0, 1e5, 81.6),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.75, 0.75),
					DIFF); //Bottom
	// scene->obj[5] = sphere(1e5,
	// 				vecp(50.0, -1e5 + 81.6, 81.6),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.75, 0.75, 0.75),
	// 				DIFF); //Top
	scene->obj[3] = sphere(SPHERE, 40,
					vecp(27.0, 40, 47.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.999, 0.999, 0.999),
					SPEC); //Mirror
	// scene->obj[7] = sphere(16.5,
	// 				vecp(73.0, 16.5, 78.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.999, 0.999, 0.999),
	// 				REFR); // Glass
	scene->obj[4] = sphere(SPHERE, 16.5,
					vecp(73.0, 16.5, 78.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.90, 0.12),
					DIFF); // Sphere diff
	scene->obj[5] = sphere(SPHERE, 16.5,
					vecp(50.0, 56.0, 30.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.25, 0.25, 0.75),
					DIFF); // Mirror red
	scene->obj[6] = sphere(SPHERE, 5.00,
					vecp(80.0, 16.5, 20.0),
					vecp(0.0, 0.0, 0.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.75, 0.25),
					DIFF); // Sphere diff
	scene->obj[7] = sphere(SPHERE, 10.00,
					vecp(130.0, 16.5, 80.0),
					vecp(0.0, 0.0, 0.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.55, 0.15),
					DIFF); // Sphere diff
	scene->obj[8] = sphere(SPHERE, 10.00,
					vecp(-50.0, 16.5, 80.0),
					vecp(0.0, 0.0, 0.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.55, 0.15),
					DIFF); // Sphere diff
	scene->obj[9] = sphere(SPHERE, 10.00,
					vecp(150.0, 16.5, 20.0),
					vecp(0.0, 0.0, 0.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.25, 0.25),
					DIFF); // Sphere diff
	scene->obj[10] = sphere(SPHERE, 10.00,
					vecp(-50.0, 16.5, 20.0),
					vecp(0.0, 0.0, 0.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.25, 0.25),
					DIFF); // Sphere diff
	scene->obj[11] = sphere(SPHERE, 20.0,
					vecp(50.0, 130.0, 30.0),
					vecp(0.0, 0.0, 0.0),
					vecp(18.0, 18.0, 18.0),
					vecp(0.75, 0.25, 0.25),
					DIFF); // Mirror red
	// scene->obj[12] = sphere(PLANE, 1e5,					// type // radius // RIGHT
	// 					 vecp(1.0, 40.8, 81.6), 			// position
	// 					 vecp(15.0, 0.0, 0.0), 				// direction
	// 					 vecp(0.0, 0.0, 0.0),			// emission
	// 					 vecp(0.0, 0.0, 0.0),			// emission
	// 					 DIFF);
	// scene->obj[10] = sphere(600,
	// 				vecp(50.0, 681.6 - .27, 50.0),
	// 				vecp(12.0, 12.0, 12.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				DIFF); // Light
}
