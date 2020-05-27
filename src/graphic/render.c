/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/07 12:28:25 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 	render(t_rtv1 *rtv1)
{
	time_t	before;
	time_t	after;
	double	second;

	mlx_put_image_to_window(rtv1->mlx_ptr,
							rtv1->main.win_ptr,
							rtv1->png.success, 0, 0);
	rtv1->screen = (t_vec *)malloc(rtv1->scene.width * rtv1->scene.height * sizeof(t_vec));
	init_cam(rtv1);
	before = time(NULL);
	// ft_printf("%s\n", rtv1->scene.cam.environment[RIGHT].path);
	if (multithread(rtv1))
		return (error("Thread error.\n"));
	after = time(NULL);
	second = difftime(after, before);
	timer(second);
	rtv1->state = RENDER;
	(rtv1->id_render)++;
	return (EXIT_SUCCESS);
}

int		multithread(t_rtv1 *rtv1)
{
	int			i;
	t_thread	thread[THREAD];

	i = -1;
	while (++i < THREAD)
	{
		thread[i].id = i + 1;
		thread[i].x = i * (rtv1->scene.width - 1) / THREAD;
		thread[i].max = (i + 1) * rtv1->scene.width / THREAD;
		thread[i].rtv1 = rtv1;
		if (pthread_create(&thread[i].thread, NULL, pathtracer, &thread[i]))
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < THREAD)
		if (pthread_join(thread[i].thread, NULL))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
