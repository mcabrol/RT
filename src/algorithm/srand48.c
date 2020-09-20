/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srand48.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:31:16 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 13:51:59 by judrion          ###   ########.fr       */
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
	double	continue_probability;

	continue_probability = max(&shape->color);
	if (4 < ray->depth)
	{
		if (erand48(render->xseed) >= continue_probability)
		{
			veccp(&ray->blank, &render->color);
			return (STOP);
		}
		ndivide_(&ray->mask, continue_probability);
	}
	return (CONTINUE);
}
