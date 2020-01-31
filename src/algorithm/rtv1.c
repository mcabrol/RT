/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 18:01:50 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		rtv1(t_render *render)
{
	t_vec 			samp;
	t_vec			u;
	t_vec 			blank;
	t_vec			color;
	int				i;
	// t_vec			cl;

	init_scene(render);
	init_camera(render);
	vec(0.0, 0.0, 0.0, &blank);
	render->y = 0;
	render->screen = (t_vec *)malloc(HEIGHT * WIDTH * sizeof(t_vec));
	while (render->y < HEIGHT)
	{
		loading_text(render);
		init_seed(render);
		render->x = 0;
		while (render->x < WIDTH)
		{
			render->sy = 0;
			i = (HEIGHT - 1 - render->y) * WIDTH + render->x;
			while (render->sy < 2)
			{
				render->sx = 0;
				while (render->sx < 2)
				{
					vec(0.0, 0.0, 0.0, &color);
					render->s = 0;
					while (render->s < render->samples)
					{
						prepare_ray(render);
						color = radiance(render, render->ray[0], render->ray[1]);
						ndivide(&color, (double)render->samples, &samp);
						sum_(&color, &samp);
						(render->s)++;
					}
					clamp3(&samp, 0.0, 1.0, &u);
					nmulti(&u, 0.25, &render->color);
					sum_(&render->screen[i], &render->color);
					// put_pixel(render, WIDTH - render->x, HEIGHT - render->y, &render->color);
					(render->sx)++;
				}
				(render->sy)++;
			}
			(render->x)++;
		}
		(render->y)++;
	}
}
