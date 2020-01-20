/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 15:25:24 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(char **av, t_rtv1 *rtv1)
{
	rtv1->scene.samples = 10;
	ft_printf("av[1] = %s\n", av[1]);
	// rtv1->scene.obj[0] = obj(1e5,
	// 				vecp(1e5 + 1.0, 40.8, 81.6),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.75, 0.25, 0.25),
	// 				DIFF); // Left
	// rtv1->scene.obj[1] = obj(1e5,
	// 				vecp(-1e5 + 99.0, 40.8, 81.6),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.25, 0.25, 0.75),
	// 				DIFF); // Right
	rtv1->scene.obj[0] = obj(1e5,
					vecp(50.0, 40.8, 1e5),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.75, 0.75),
					DIFF); //Back
	rtv1->scene.obj[1] = obj(1e5,
					vecp(50.0, 40.8, -1e5 + 170.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.0, 0.0, 0.0),
					DIFF); //Front
	rtv1->scene.obj[2] = obj(1e5,
					vecp(50.0, 1e5, 81.6),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.75, 0.75),
					DIFF); //Bottom
	// rtv1->scene.obj[5] = obj(1e5,
	// 				vecp(50.0, -1e5 + 81.6, 81.6),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.75, 0.75, 0.75),
	// 				DIFF); //Top
	rtv1->scene.obj[3] = obj(16.5,
					vecp(27.0, 16.5, 47.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.999, 0.999, 0.999),
					SPEC); //Mirror
	// rtv1->scene.obj[7] = obj(16.5,
	// 				vecp(73.0, 16.5, 78.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				vecp(0.999, 0.999, 0.999),
	// 				REFR); // Glass
	rtv1->scene.obj[4] = obj(16.5,
					vecp(73.0, 16.5, 78.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.75, 0.90, 0.12),
					DIFF); // obj diff
	rtv1->scene.obj[5] = obj(16.5,
					vecp(50.0, 56.0, 30.0),
					vecp(0.0, 0.0, 0.0),
					vecp(0.25, 0.25, 0.75),
					DIFF); // Mirror red
	rtv1->scene.obj[6] = obj(5.00,
					vecp(80.0, 16.5, 20.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.75, 0.25),
					DIFF); // obj diff
	rtv1->scene.obj[7] = obj(10.00,
					vecp(130.0, 16.5, 80.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.55, 0.15),
					DIFF); // obj diff
	rtv1->scene.obj[8] = obj(10.00,
					vecp(-50.0, 16.5, 80.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.55, 0.15),
					DIFF); // obj diff
	rtv1->scene.obj[9] = obj(10.00,
					vecp(150.0, 16.5, 20.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.25, 0.25),
					DIFF); // obj diff
	rtv1->scene.obj[10] = obj(10.00,
					vecp(-50.0, 16.5, 20.0),
					vecp(12.0, 12.0, 12.0),
					vecp(0.75, 0.25, 0.25),
					DIFF); // obj diff
	rtv1->scene.obj[11] = obj(20.0,
					vecp(50.0, 130.0, 30.0),
					vecp(18.0, 18.0, 18.0),
					vecp(0.75, 0.25, 0.25),
					DIFF); // Mirror red
	// rtv1->scene.obj[10] = obj(600,
	// 				vecp(50.0, 681.6 - .27, 50.0),
	// 				vecp(12.0, 12.0, 12.0),
	// 				vecp(0.0, 0.0, 0.0),
	// 				DIFF); // Light
}
