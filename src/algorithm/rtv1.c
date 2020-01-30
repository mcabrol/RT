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
	unsigned short	xseed[3];
	int				num;
	t_vec			l;
	t_vec			u;
	// t_vec			cl;

	num = rand();
	init_scene(render);
	init_camera(render);
	render->y = 0;
	while (render->y < HEIGHT)
	{
		loading_text(render);
		init_seed(render);
		render->x = 0;
		while (render->x < WIDTH)
		{
			render->sy = 0;
			while (render->sy < 2)
			{
				render->sx = 0;
				while (render->sx < 2)
				{
					vec(0.0, 0.0, 0.0, &render->color);
					render->s = 0;
					while (render->s < render->samples)
					{
						prepare_ray(render);
						render->color = radiance(render, render->ray[0], render->ray[1], xseed);
						ndivide(&render->color, (double)render->samples, &l);
						// printv(&render->color);
						sum_(&render->color, &l);
						(render->s)++;
					}
					clamp3(&render->color, 0.0, 1.0, &u);
					nmulti(&u, 0.25, &render->color);
					put_pixel(render, WIDTH - render->x, HEIGHT - render->y, &render->color);
					(render->sx)++;
				}
				(render->sy)++;
			}
			(render->x)++;
		}
		(render->y)++;
	}
}
