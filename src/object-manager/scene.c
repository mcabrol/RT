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
	render->samples = 100;
	render->object[0] = obj(SPHERE, 16.5,
						 vecp(50.0, 45.0, 50.0),
						 vecp(0.0, 1.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 DIFFUSE);
	render->object[1] = obj(PLANE, 16.5,
						 vecp(50.0, 20.0, 50.0),
						 vecp(1.0, 1.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 vecp(0.69, 0.69, 0.69),
						 DIFFUSE);
	render->object[2] = obj(SPHERE, 500,
						 vecp(50.0,  300, 50.0),
						 vecp(0.0, 1.0, 0.0),
						 vecp(12.0, 12.0, 12.0),
						 vecp(0.0, 0.0, 0.0),
						 DIFFUSE);
}
