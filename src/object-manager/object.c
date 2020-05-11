/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 19:19:49 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		prepare_obj(t_obj *obj)
{
	if (obj->rotation.x > 0 || obj->rotation.y > 0 || obj->rotation.z > 0)
	{
		obj->direction = rotate_point(deg_to_rad(obj->rotation.x),
	 				 	 deg_to_rad(obj->rotation.y),
					 	 deg_to_rad(obj->rotation.z),
					 	 *norm(&obj->direction));
	}
	else
		obj->direction = *norm(&obj->direction);
}
