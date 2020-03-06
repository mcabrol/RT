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

void 		*pathtracer(void *var)
{
	t_thread		*thread;
	t_scene 		*scene;
	t_render 		render;

	thread = (t_thread *)var;
	scene = &thread->rtv1->scene;
	init_cam(scene);
	init_seed(&render);
	render.y = -1;
	while (++(render.y) < scene->height)
	{
		loading_text(scene->samples, render.y, thread->max);
		render.x = thread->x;
		while (++(render.x) < thread->max)
			sampling(thread->rtv1, &render);
	}
	pthread_exit(EXIT_SUCCESS);
}

void 	sampling(t_rtv1 *rtv1, t_render *render)
{
	t_ray			ray;
	t_radiance		target;
	t_scene 		*scene;

	scene = &rtv1->scene;
	render->i = (scene->height - 1 - render->y) * scene->width + render->x;
	render->sy = -1;
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
			sum_(&rtv1->screen[render->i], &render->l);
		}
	}
}
