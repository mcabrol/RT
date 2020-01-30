/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:09:58 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(t_render *render)
{
	render->samples = SAMPLES / 4;
	render->object[0] = obj(PLANE, 1e5, 0,					// type // radius // RIGHT
						 vecp(1.0, 40.8, 81.6), 		// position
						 vecp(15.0, 0.0, 0.0), 			// direction
						 vecp(0.0, 0.0, 0.0),			// emission
						 vecp(0.0, 0.0, 0.0),		// color
						 DIFFUSE);						// material
	render->object[1] = obj(PLANE, 1e5, 0,								// LEFT
						 vecp(99.0, 40.8, 81.6),
						 vecp(15.0, 0.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 DIFFUSE);
	render->object[2] = obj(PLANE, 1e5, 0,								// TOP
						vecp(50.0, 82.0, 1e5),
						vecp(0.0, 1.0, 0.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
					 	DIFFUSE);
	render->object[3] = obj(PLANE, 1e5, 0,								// FLOOR
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 1.0, 0.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
					 	DIFFUSE);
	render->object[4] = obj(PLANE, 1e5, 0,										// BACK
						vecp(73.0, 16.5, 0.0),
						vecp(0.0, 0.0, -15.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
					 	DIFFUSE);
	render->object[5] = obj(SPHERE, 5.0, 0,										// LIGHT BACK LEFT
						vecp(100.0 - 10.0, 0.0 + 10.0, 0.0 + 10.0),
						vecp(0.0, 1.0, 0.0),
						vecp(15.0, 15.0, 15.0),
						vecp(0.0, 0.0, 0.0),
					 	DIFFUSE);
	render->object[6] = obj(SPHERE, 5.0, 0.0,									// LIGHT BACK RIGHT
						vecp(0.0 + 10.0, 0.0 + 10.0, 0.0 + 10.0),
						vecp(0.0, 0.0, 0.0),
						vecp(12.0, 12.0, 12.0),
						vecp(0.0, 0.0, 0.0),
						DIFFUSE);
	render->object[7] = obj(SPHERE, 600.0, 0.0,									// LIGHT TOP
						vecp(50.0, 681.6 - .27, 81.6),
						vecp(0.0, 0.0, 0.0),
						vecp(12.0, 12.0, 12.0),
						vecp(0.0, 0.0, 0.0),
						DIFFUSE);
	render->object[8] = obj(SPHERE, 5.0, 0,										// LIGHT FRONT LEFT
						vecp(100.0 - 10.0, 0.0 + 10.0, 120.0 + 10.0),
						vecp(0.0, 1.0, 0.0),
						vecp(15.0, 15.0, 15.0),
						vecp(0.0, 0.0, 0.0),
					 	DIFFUSE);
	render->object[9] = obj(SPHERE, 5.0, 0.0,									// LIGHT FRONT RIGHT
						vecp(0.0 + 10.0, 0.0 + 10.0, 120.0 + 10.0),
						vecp(0.0, 0.0, 0.0),
						vecp(12.0, 12.0, 12.0),
						vecp(0.0, 0.0, 0.0),
						DIFFUSE);
	// render->object[7] = obj(CYLINDER, 50.0, 0.0,								// CYLINDER
	// 					vecp(72.0, 16.5, 50.0),
	// 					vecp(0.0, 1.0, 0.0),
	// 					vecp(0.0, 0.0, 0.0),
	// 					vecp(25.0, 25.0, 80.0),
	// 					DIFFUSE);
	render->object[10] = obj(SPHERE, 16.5, 0,									// SPHERE
						vecp(73.0, 16.5, 78.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
						DIFFUSE);
	render->object[11] = obj(SPHERE, 16.5, 0,									// SPHERE SPEC
						vecp(30.0, 16.5, 78.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
						vecp(0.0, 0.0, 0.0),
						SPECULAR);
}
