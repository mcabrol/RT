/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 21:19:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:00:42 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// int		multithread(t_rtv1 *rtv1)
// {
// 	int			i;
// 	t_thread	thread[THREAD];
//
// 	i = 0u;
// 	while (i < THREAD)
// 	{
// 		thread[i].x = i * WIDTH / THREAD;
// 		thread[i].max = (i + 1) * WIDTH / THREAD;
// 		thread[i].rtv1 = rtv1;
// 		if (pthread_create(&thread[i].thread, NULL, dispatcher, &thread[i]))
// 			return (EXIT_FAILURE);
// 		i++;
// 	}
// 	i = 0u;
// 	while (i < THREAD)
// 	{
// 		if (pthread_join(thread[i].thread, NULL))
// 			return (EXIT_FAILURE);
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }
//
// void	*dispatcher(void *var)
// {
// 	t_thread	*thread;
//
// 	thread = (t_thread *)var;
// 	thrtv1(thread->rtv1, thread->x, thread->max);
//
// 	pthread_exit(EXIT_SUCCESS);
// }
