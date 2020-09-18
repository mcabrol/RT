/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srand48.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:31:16 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/18 22:11:51 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_seed(t_render *rt)
{
	rt->xseed[0] = 0;
	rt->xseed[1] = 0;
	rt->xseed[2] = (unsigned short)(rt->y * rt->y * rt->y);
}

int			russian_roulette(t_ray *ray, t_obj *shape, t_render *render)
{
	double continue_probability;

	continue_probability = max(&shape->color);
	if (4 < ray->depth)
	{
		// ft_printf("[Stop]\n");
		// ft_printf("%f\n", continue_probability);
		if (erand48(render->xseed) >= continue_probability)
		{
			veccp(&ray->blank, &render->color);
			return (STOP);
		}
		ndivide_(&ray->mask, continue_probability);
	}
	// else
	// 	ft_printf("[Ok]\n");
	return (CONTINUE);
}
