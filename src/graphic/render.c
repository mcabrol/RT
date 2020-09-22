/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:28:42 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 14:48:39 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	prepare_texture(t_rtv1 *rtv1)
{
	int i;

	i = -1;
	while (++i < rtv1->scene.n)
	{
		if (rtv1->scene.obj[i].texture.path)
		{
			if (load_texture(rtv1, &rtv1->scene.obj[i]))
			{
				rtv1->state = ERROR;
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int			render(t_rtv1 *rtv1)
{
	time_t	before;
	time_t	after;
	double	second;

	if (rtv1->screen)
		free(rtv1->screen);
	rtv1->screen = (t_vec *)malloc((rtv1->scene.width * rtv1->scene.height) \
	* sizeof(t_vec));
	if (!rtv1->screen)
		return (EXIT_FAILURE);
	ft_bzero(rtv1->screen, sizeof(t_vec) * rtv1->scene.width * \
	rtv1->scene.height);
	if (prepare_texture(rtv1))
		return (EXIT_FAILURE);
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

int			multithread(t_rtv1 *rtv1)
{
	int			i;
	t_thread	thread[THREAD];

	i = -1;
	while (++i < THREAD)
	{
		thread[i].id = i + 1;
		thread[i].x = i * (rtv1->scene.width - 1) / THREAD;
		thread[i].max = (i + 1) * rtv1->scene.width / THREAD;
		if (i > 0 && thread[i - 1].max == thread[i].x)
			thread[i].x = thread[i].x - 1;
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
