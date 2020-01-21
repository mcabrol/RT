// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   rtv1.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
// /*   Updated: 2020/01/20 16:16:34 by mcabrol          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */
//
// #include "rtv1.h"
//
// void 		rt(t_rtv1 *rtv1)
// {
// 	t_target		target;
// 	t_ray			ry;
//
// 	init_cam(rtv1);
// 	rtv1->rt.ls = (t_vec *)malloc(WIDTH * HEIGHT * sizeof(t_vec));
// 	rtv1->rt.y = 0u;
// 	while ((unsigned int)rtv1->rt.y < HEIGHT)
// 	{
// 		ft_dprintf(2, "\r%u samples %5.2f%%", rtv1->scene.samples, 100.0 * rtv1->rt.y / (HEIGHT - 1));
// 		init_seed(rtv1);
// 		rtv1->rt.x = 0u;
// 		while ((unsigned int)rtv1->rt.x < WIDTH)
// 		{
// 			rtv1->rt.sy = 0u;
// 			rtv1->rt.i = (HEIGHT - 1u - rtv1->rt.y) * WIDTH + rtv1->rt.x;
// 			while (rtv1->rt.sy < 2u)
// 			{
// 				rtv1->rt.sx = 0u;
// 				while (rtv1->rt.sx < 2u)
// 				{
// 					vec(0.0, 0.0, 0.0, &rtv1->rt.m);
// 					rtv1->rt.s = 0u;
// 					while (rtv1->rt.s < rtv1->scene.samples)
// 					{
// 						prepare_ray(rtv1, &target);
// 						ray(target.eye_t, *norm(&target.d), EPSILON_SPHERE, INFINITY, 0, &ry);
// 						radiance(rtv1, &ry);
// 						ndivide(&rtv1->rt.l_t, (double)rtv1->scene.samples, &rtv1->rt.l);
// 						sum_(&rtv1->rt.m, &rtv1->rt.l);
// 						(rtv1->rt.s)++;
// 					}
// 					clamp3(&rtv1->rt.m, 0.0, 1.0, &rtv1->rt.l_t);
// 					nmulti(&rtv1->rt.l_t, 0.25, &rtv1->rt.l);
// 					sum_(&rtv1->rt.ls[rtv1->rt.i], &rtv1->rt.l);
// 					put_pixel(rtv1, (WIDTH - rtv1->rt.x), (HEIGHT - rtv1->rt.y), &rtv1->rt.ls[rtv1->rt.i]);
// 					(rtv1->rt.sx)++;
// 				}
// 				(rtv1->rt.sy)++;
// 			}
// 			(rtv1->rt.x)++;
// 		}
// 		(rtv1->rt.y)++;
// 	}
// 	free(rtv1->rt.ls);
// }
