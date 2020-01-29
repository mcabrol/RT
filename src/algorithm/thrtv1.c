/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 16:16:34 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		thrtv1(t_rtv1 *rtv1, int x, int max)
{
	t_algo			render;
	t_target		target;
	t_ray			ry;
	t_cam			cam;
	unsigned int 	seed;
	int				num;

	init_cam(cam);
	num = rand();
	render.ls = (t_vec *)malloc((max - x + 1) * HEIGHT * sizeof(t_vec));
	render.y = 0u;
	while ((unsigned int)render.y < HEIGHT)
	{
		ft_dprintf(2, "\r%u samples %5.1f%%", rtv1->scene.samples, 100.0 * render.y / (HEIGHT - 1));
		render.x = x;
		seed = generate3((unsigned int)render.x * (unsigned int)num, (unsigned int)render.y * (unsigned int)num, (unsigned int)num);
		while (render.x < max)
		{
			render.sy = 0u;
			while (render.sy < 2u)
			{
				render.sx = 0u;
				while (render.sx < 2u)
				{
					vec(0.0, 0.0, 0.0, &render.color);
					render.s = 0u;
					while (render.s < rtv1->scene.samples)
					{
						prepare_ray(rtv1, &render, &target, seed);
						ray(target.eye_t, *norm(&target.d), EPSILON_SPHERE,
						INFINITY, 0, &ry);
						render.color = radiance(rtv1, &ry, seed);
						(render.s)++;
					}
					put_pixel(rtv1, WIDTH - render.x, HEIGHT - render.y, &render.color);
					(render.sx)++;
				}
				(render.sy)++;
			}
			(render.x)++;
		}
		(render.y)++;
	}
	free(render.ls);
}
