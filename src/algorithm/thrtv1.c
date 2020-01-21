/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                             :+:      :+:    :+:   */
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
	t_algo			rt;
	t_target		target;
	t_ray			ry;

	init_cam(rtv1);
	rt.ls = (t_vec *)malloc((max - x + 1) * HEIGHT * sizeof(t_vec));
	rt.y = 0u;
	while ((unsigned int)rt.y < HEIGHT)
	{
		ft_dprintf(2, "\r%u samples %5.1f%%", rtv1->scene.samples, 100.0 * rt.y / (HEIGHT - 1));
		init_seed(&rt);
		rt.x = x;
		while (rt.x < max)
		{
			rt.sy = 0u;
			rt.i = (HEIGHT - 1u - rt.y) * (max - x) + rt.x;
			while (rt.sy < 2u)
			{
				rt.sx = 0u;
				while (rt.sx < 2u)
				{
					vec(0.0, 0.0, 0.0, &rt.m);
					rt.s = 0u;
					while (rt.s < rtv1->scene.samples)
					{
						prepare_ray(rtv1, &rt, &target);
						ray(target.eye_t, *norm(&target.d), EPSILON_SPHERE,
						INFINITY, 0, &ry);
						radiance(rtv1, &rt, &ry);
						ndivide(&rt.l_t, (double)rtv1->scene.samples, &rt.l);
						sum_(&rt.m, &rt.l);
						(rt.s)++;
					}
					clamp3(&rt.m, 0.0, 1.0, &rt.l_t);
					nmulti(&rt.l_t, 0.25, &rt.l);
					sum_(&rt.ls[rt.i], &rt.l);
					put_pixel(rtv1, WIDTH - rt.x, HEIGHT - rt.y, &rt.ls[rt.i]);
					(rt.sx)++;
				}
				(rt.sy)++;
			}
			(rt.x)++;
		}
		(rt.y)++;
	}
	free(rt.ls);
}
