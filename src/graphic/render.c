/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/14 21:03:07 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		render(t_rtv1 *rtv1)
{
	time_t	before;
	time_t	after;
	double	second;

	rtv1->screen = (t_vec *)malloc((rtv1->scene.width * rtv1->scene.height) \
	* sizeof(t_vec));
	ft_bzero(rtv1->screen, rtv1->scene.width * rtv1->scene.height);
	if (init_cam(rtv1))
		return (EXIT_FAILURE);
	before = time(NULL);
	if (multithread(rtv1))
		return (error("Thread error.\n"));
	after = time(NULL);
	second = difftime(after, before);
	timer(second);
	rtv1->state = RENDER;
	return (EXIT_SUCCESS);
}

int		multithread(t_rtv1 *rtv1)
{
	int			i;
	t_thread	thread[THREAD];

	i = -1;
	// if (pthread_mutex_init(&rtv1->scene.lock, NULL) != 0) {
	//    printf("\n mutex init has failed\n");
	//    return 1;
   // }
	while (++i < THREAD)
	{
		thread[i].id = i + 1;
		thread[i].x = i * (rtv1->scene.width - 1) / THREAD;
		thread[i].max = (i + 1) * rtv1->scene.width / THREAD;
		if (i > 0 && thread[i - 1].max == thread[i].x)
			thread[i].x = thread[i].x - 1;
		thread[i].rtv1 = rtv1;
		// ft_printf("thread[%d] > %p\nthread.x > %d\nthread.max > %d", i, thread[i].id, thread[i].x, thread[i].max);

		if (pthread_create(&thread[i].thread, NULL, pathtracer, &thread[i]))
			return (EXIT_FAILURE);
	}
	i = -1;
	while (++i < THREAD)
	{

		if (pthread_join(thread[i].thread, NULL))
			return (EXIT_FAILURE);
	}
	// pthread_mutex_destroy(&rtv1->scene.lock);
	return (EXIT_SUCCESS);
}
