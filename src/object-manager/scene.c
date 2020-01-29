/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/28 17:02:36 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	init_scene(char **av, t_rtv1 *rtv1)
{
	rtv1->scene.samples = 100;
	ft_printf("av[1] = %s\n", av[1]);
	rtv1->scene.obj[0] = obj(SPHERE, 16.5,
						 vecp(50.0, 45.0, 50.0),
						 vecp(0.0, 1.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 DIFFUSE);
	rtv1->scene.obj[1] = obj(PLAN, 16.5,
						 vecp(50.0, 20.0, 50.0),
						 vecp(1.0, 1.0, 0.0),
						 vecp(0.0, 0.0, 0.0),
						 vecp(0.69, 0.69, 0.69),
						 DIFFUSE);
	rtv1->scene.obj[2] = obj(SPHERE, 200,
						 vecp(50.0,  300, 50.0),
						 vecp(0.0, 1.0, 0.0),
						 vecp(12.0, 12.0, 12.0),
						 vecp(0.0, 0.0, 0.0),
						 DIFFUSE);
}
