/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/26 17:32:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 		pathtracer(t_rtv1 *rtv1)
{
	t_ray			ray;
	t_radiance		target;
	t_scene 		*scene;
	t_render 		*render;

	scene = &rtv1->scene;
	render = &rtv1->render;
	render->screen = (t_vec *)malloc(rtv1->scene.width * rtv1->scene.height * sizeof(t_vec));
	init_cam(scene);
	render->y = -1;
	init_seed(render);
	while (++(render->y) < scene->height)
	{
		loading_text(scene->samples, render->y, scene->height);
		render->x = -1;
		while (++(render->x) < scene->width)
		{
			render->sy = -1;
			render->i = (scene->height - 1 - render->y) * scene->width + render->x;
			while (++(render->sy) < 3)
			{
				render->sx = -1;
				while (++(render->sx) < 3)
				{
					vec(0.0, 0.0, 0.0, &render->accucolor);
					render->s = -1;
					while (++(render->s) < scene->samples)
					{
						prepare_ray(render, &target, scene);
						init_ray(target.eye_t, *norm(&target.d), 0, &ray);
						radiance(scene, &ray, render);
						ndivide(&render->color, (double)scene->samples, &render->l);
						sum_(&render->accucolor, &render->l);
						(render->s)++;
					}
					clamp3(&render->accucolor, 0.0, 1.0, &render->color);
					nmulti(&render->color, 0.25, &render->l);
					sum_(&render->screen[render->i], &render->l);
				}
			}
		}
	}
}
