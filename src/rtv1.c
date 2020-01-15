/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/13 20:09:35 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_win			win;

	win.ac = ac;
	win.av = av;
	window(&win);
	return (0);
}

void 		rtv1(t_win *win)
{
	t_ray			ry;
	t_cam 			cam;
	t_scene 		scene;
	t_target		target;
	t_algo			rt;

	init_scene(&scene, win);
	init_cam(&cam);
	rt.ls = (t_vec *)malloc(WIDTH * HEIGHT * sizeof(t_vec));
	rt.y = 0u;
	while ((unsigned int)rt.y < HEIGHT)
	{
		ft_dprintf(2, "\rRendering (%u spp) %5.2f%%", scene.samples * 4, 100.0 * rt.y / (HEIGHT - 1));
		init_seed(&rt);
		rt.x = 0u;
		while ((unsigned int)rt.x < WIDTH)
		{
			rt.sy = 0u;
			rt.i = (HEIGHT - 1u - rt.y) * WIDTH + rt.x;
			while (rt.sy < 2u)
			{
				rt.sx = 0u;
				while (rt.sx < 2u)
				{
					vec(0.0, 0.0, 0.0, &rt.m);
					rt.s = 0u;
					while (rt.s < scene.samples)
					{
						prepare_ray(&rt, &target, &cam);
						ray(target.eye_t, *norm(&target.d), EPSILON_SPHERE, INFINITY, 0, &ry);
						radiance(&scene, &ry, rt.xseed, &rt.l_t);
						ndivide(&rt.l_t, (double)scene.samples, &rt.l);
						sum_(&rt.m, &rt.l);
						(rt.s)++;
					}
					clamp3(&rt.m, 0.0, 1.0, &rt.l_t);
					nmulti(&rt.l_t, 0.25, &rt.l);
					sum_(&rt.ls[rt.i], &rt.l);
					put_pixel(win, (WIDTH - rt.x), (HEIGHT - rt.y), &rt.ls[rt.i]);
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

void		init_seed(t_algo *rt)
{
	rt->xseed[0] = 0;
	rt->xseed[1] = 0;
	rt->xseed[2] = (unsigned short)(rt->y * rt->y * rt->y);
}
