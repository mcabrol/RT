/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/17 21:46:14 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		rtv1(t_win *win)
{
	t_ray			ry;
	t_cam 			cam;
	t_radiance		target;
	t_render		render;
	t_scene 		scene;

	init_scene(&scene);
	init_cam(&cam);
	render.screen = (t_vec *)malloc(WIDTH * HEIGHT * sizeof(t_vec));
	render.y = 0u;
	while ((unsigned int)render.y < HEIGHT)
	{
		loading_text(scene.samples, render.y);
		init_seed(&render);
		render.x = 0u;
		while ((unsigned int)render.x < WIDTH)
		{
			render.sy = 0u;
			render.i = (HEIGHT - 1u - render.y) * WIDTH + render.x;
			while (render.sy < 2u)
			{
				render.sx = 0u;
				while (render.sx < 2u)
				{
					vec(0.0, 0.0, 0.0, &render.m);
					render.s = 0u;
					while (render.s < scene.samples)
					{
						prepare_ray(&render, &target, &cam);
						ray(target.eye_t, *norm(&target.d), EPSILON_SPHERE, INFINITY, 0, &ry);
						radiance(&scene, &ry, &render);
						ndivide(&render.color, (double)scene.samples, &render.l);
						sum_(&render.m, &render.l);
						(render.s)++;
					}
					clamp3(&render.m, 0.0, 1.0, &render.color);
					nmulti(&render.color, 0.25, &render.l);
					sum_(&render.screen[render.i], &render.l);
					put_pixel_vector(win, (WIDTH - render.x), (HEIGHT - render.y), &render.screen[render.i]);
					(render.sx)++;
				}
				(render.sy)++;
			}
			(render.x)++;
		}
		(render.y)++;
	}
	free(render.screen);
}
