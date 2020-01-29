/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:32:47 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		rtv1(t_render *render)
{
	unsigned int 	seed;
	int				num;

	num = rand();
	init_scene(render);
	init_camera(render);
	render->y = 0;
	while (render->y < HEIGHT)
	{
		// loading_text(render);
		render->x = 0;
		while (render->x < WIDTH)
		{
			seed = generate3((unsigned int)render->x * (unsigned int)num, (unsigned int)render->y * (unsigned int)num, (unsigned int)num);
			vec(0.0, 0.0, 0.0, &render->color);
			render->s = 0;
			while (render->s < render->samples)
			{
				prepare_ray(render, seed);
				printr(render->ray[0], render->ray[1]);
				render->color = radiance(render, render->ray[0], render->ray[1], seed);
				(render->s)++;
			}
			put_pixel(render, WIDTH - render->x, HEIGHT - render->y, &render->color);
			(render->x)++;
		}
		(render->y)++;
	}
}
