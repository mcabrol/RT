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

t_scene		init_scene(void)
{
	t_scene scene;
	t_vec	*c;

	scene.samples = 500;
	scene.camera = ray(vec(50,52,295.6), norm(vec(0,-0.042612,-1)));
	scene.cx = vec(w * .5135 / h);
	scene.cy = vec(norm(cx % cam.d), r, *c);
	return (scene);
}
