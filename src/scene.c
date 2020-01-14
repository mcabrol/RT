/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_scene *scene, t_win *win)
{
	scene->samples = (win->ac == 2) ? atoi(win->av[1]) / 4 : 1;
	scene->obj[0] = sphere(1e5,
					veccp(1e5 + 1.0, 40.8, 81.6),
					veccp(0.0, 0.0, 0.0),
					veccp(0.75, 0.25, 0.25),
					DIFF); // Left
	scene->obj[1] = sphere(1e5,
					veccp(-1e5 + 99.0, 40.8, 81.6),
					veccp(0.0, 0.0, 0.0),
					veccp(0.25, 0.25, 0.75),
					DIFF); // Right
	scene->obj[2] = sphere(1e5,
					veccp(50.0, 40.8, 1e5),
					veccp(0.0, 0.0, 0.0),
					veccp(0.75, 0.75, 0.75),
					DIFF); //Back
	scene->obj[3] = sphere(1e5,
					veccp(50.0, 40.8, -1e5 + 170.0),
					veccp(0.0, 0.0, 0.0),
					veccp(0.0, 0.0, 0.0),
					DIFF); //Front
	scene->obj[4] = sphere(1e5,
					veccp(50.0, 1e5, 81.6),
					veccp(0.0, 0.0, 0.0),
					veccp(0.75, 0.75, 0.75),
					DIFF); //Bottom
	scene->obj[5] = sphere(1e5,
					veccp(50.0, -1e5 + 81.6, 81.6),
					veccp(0.0, 0.0, 0.0),
					veccp(0.75, 0.75, 0.75),
					DIFF); //Top
	scene->obj[6] = sphere(16.5,
					veccp(27.0, 16.5, 47.0),
					veccp(0.0, 0.0, 0.0),
					veccp(0.999, 0.999, 0.999),
					SPEC); //Mirror
	// scene->obj[7] = sphere(16.5,
	// 				veccp(73.0, 16.5, 78.0),
	// 				veccp(0.0, 0.0, 0.0),
	// 				veccp(0.999, 0.999, 0.999),
	// 				REFR); // Glass
	scene->obj[7] = sphere(16.5,
					veccp(73.0, 16.5, 78.0),
					veccp(0.0, 0.0, 0.0),
					veccp(0.75, 0.90, 0.12),
					DIFF); // Sphere diff
	scene->obj[8] = sphere(16.5,
					veccp(50.0, 50.0, 30.0),
					veccp(0.0, 0.0, 0.0),
					veccp(0.999, 0.999, 0.999),
					REFR); // Mirror red
	scene->obj[9] = sphere(5.00,
					veccp(80.0, 16.5, 20.0),
					veccp(12.0, 12.0, 12.0),
					veccp(0.75, 0.75, 0.25),
					DIFF); // Sphere diff
	scene->obj[10] = sphere(600,
					veccp(50.0, 681.6 - .27, 50.0),
					veccp(12.0, 12.0, 12.0),
					veccp(0.0, 0.0, 0.0),
					DIFF); // Light
}
