/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 17:26:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	 	loading_text(int height, int y)
{
	ft_dprintf(1, "\r%3.0f%%", 100.0 * y / (height - 1));
}

char 		*stamp(t_rtv1 *rtv1)
{
	char 	*num;
	char 	*dimension;
	char 	*sample;
	char 	*stamp;

	num = ft_strcat(ft_itoa(rtv1->id_ppm), " - ");
	dimension = ft_strcat(ft_itoa(rtv1->scene.width), "x");
	dimension = ft_strcat(dimension, ft_itoa(rtv1->scene.height));
	sample = ft_strcat(dimension, " x");
	sample = ft_strcat(sample, ft_itoa(rtv1->scene.samples));
	stamp = ft_strcat(num, sample);
	stamp = ft_strcat(stamp, ".ppm");
	return (stamp);
}
