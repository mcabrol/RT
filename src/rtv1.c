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
	t_vec 			*ls;
	unsigned int 	i;
	t_vec			l;
	t_vec			m;
	t_vec			l_t;
	t_ray			ry;
	t_cam 			cam;
	t_scene 		scene;
	t_target		target;
	t_algo			rt;

	init_scene(&scene, win);
	init_cam(&cam);
	ls = (t_vec *)malloc(WIDTH * HEIGHT * sizeof(t_vec));
	rt.y = 0u;
	while ((unsigned int)rt.y < HEIGHT)
	{
		ft_dprintf(2, "\rRendering (%u spp) %5.2f%%", scene.samples * 4, 100.0 * rt.y / (HEIGHT - 1));
		cam.xseed[0] = 0;
		cam.xseed[1] = 0;
		cam.xseed[2] = (unsigned short)(rt.y * rt.y * rt.y);
		rt.x = 0u;
		while ((unsigned int)rt.x < WIDTH)
		{
			rt.sy = 0u;
			i = (HEIGHT - 1u - rt.y) * WIDTH + rt.x;
			while (rt.sy < 2u)
			{
				rt.sx = 0u;
				while (rt.sx < 2u)
				{
					vec(0.0, 0.0, 0.0, &m);
					rt.s = 0u;
					while (rt.s < scene.samples)
					{
						prepare_ray(&rt, &target, &cam);
						ray(target.eye_t, *norm(&target.d), EPSILON_SPHERE, INFINITY, 0, &ry);
						radiance(&scene, &ry, cam.xseed, &l_t);
						ndivide(&l_t, (double)scene.samples, &l);
						sum_(&m, &l);
						(rt.s)++;
					}
					clamp3(&m, 0.0, 1.0, &l_t);
					nmulti(&l_t, 0.25, &l);
					sum_(&ls[i], &l);
					// ft_printf("ls[%d] = ", i);
					//printv(&ls[i]);
					put_pixel(win, (WIDTH - rt.x), (HEIGHT - rt.y), &ls[i]);
					(rt.sx)++;
				}
				(rt.sy)++;
			}
			(rt.x)++;
		}
		(rt.y)++;
	}
	// for (size_t i = 0; i < WIDTH * HEIGHT; ++i) {
	// 	ft_printf("%d %d %d ", to_byte(ls[i].x, GAMMA),
	// 		                   to_byte(ls[i].y, GAMMA),
	// 		                   to_byte(ls[i].z, GAMMA));
	// 					   }
	free(ls);
}
