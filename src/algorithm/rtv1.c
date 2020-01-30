/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/30 19:53:55 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		rtv1(t_render *render)
{
	unsigned short	xseed[3];
	double 			samp;
	t_vec			u;
	// t_vec			cl;

	init_scene(render);
	init_camera(render);
	samp = 1.0f / render->samples;
	ft_printf("samp> %f\n", samp);
	render->y = 0;
	while (render->y < HEIGHT)
	{
		loading_text(render);
		init_seed(xseed, render->y);
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
						nmulti_(&render->color, samp);
						(render->s)++;
					}
					clamp3(&render->color, 0.0, 1.0, &u);
					put_pixel(render, WIDTH - render->x, HEIGHT - render->y, &u);
					(render->sx)++;
				}
				(render->sy)++;
			}
			(render->x)++;
		}
		(render->y)++;
	}
}
