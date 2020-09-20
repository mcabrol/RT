/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 19:38:45 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		print_obj(t_obj *obj)
{
	ft_printf("TYPE : %d\n", obj->type);
	ft_printf("RADIUS : %f\n", obj->radius);
	ft_printf("POSITION : ");
	printv(&obj->position);
	ft_printf("DIRECTION : ");
	printv(&obj->direction);
	ft_printf("COLOR : ");
	printv(&obj->color);
	ft_printf("EMISSION : ");
	printv(&obj->emission);
	ft_printf("REFLECTION : %d\n", obj->reflect);
	ft_printf("ANGLE : %f\n", obj->angle);
	ft_printf("HEIGHT : %f\n", obj->height);
	ft_printf("WIDTH : %f\n", obj->width);
	ft_printf("DEPTH : %f\n", obj->depth);
	ft_printf("ROTATION : ");
	printv(&obj->rotation);
	ft_printf("\n");
}
