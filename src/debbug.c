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

void		timer(int time)
{
	int 	second;
	int 	minute;
	int 	hour;

	second = 0;
	minute = 0;
	hour = 0;
	while (time)
	{
		if (time > 60 * 60)
		{
			hour++;
			time -= 60 * 60;
		}
		else if (time > 60)
		{
			minute++;
			time -= 60;
		}
		else
		{
			second++;
			time--;
		}
	}
	ft_printf(" -> %.2d:%.2d:%.2d", hour, minute, second);
}

void 		print_obj(t_obj *obj)
{
	ft_printf("TYPE : %d\n", obj->type);
	ft_printf("RADIUS : %f\n", obj->radius);
	ft_printf("POSITION : ");
	printv(&obj->position);
	ft_printf("DIRECTION : ");
	printv(&obj->direction);
	ft_printf("COLOR : ");
	printv(&obj->color);
	// ft_printf("COLOR : %#.8X\n", obj->color);
	ft_printf("EMISSION : ");
	printv(&obj->emission);
	ft_printf("REFLECTION : %d\n", obj->reflect);
	ft_printf("ANGLE : %f\n", obj->angle);
	ft_printf("HEIGHT : %f\n", obj->height);
	ft_printf("WIDTH : %f\n", obj->width);
	ft_printf("DEPTH : %f\n", obj->depth);
}
