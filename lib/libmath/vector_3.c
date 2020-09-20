/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 17:21:16 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec		rotate_vector(t_vec obj_rotation, t_vec dir)
{
	double	y;
	double	z;
	double	x1;
	double	z1;

	y = (dir.y) * cos(obj_rotation.x) + (dir.z) * sin(obj_rotation.x);
	z = (dir.z) * cos(obj_rotation.x) - (dir.y) * sin(obj_rotation.x);
	x1 = (dir.x) * cos(obj_rotation.y) + z * sin(obj_rotation.y);
	z1 = z * cos(obj_rotation.y) - (dir.x) * sin(obj_rotation.y);
	(dir.x) = x1 * cos(obj_rotation.z) - y * sin(obj_rotation.z);
	(dir.y) = x1 * sin(obj_rotation.z) + y * cos(obj_rotation.z);
	(dir.z) = z1;
	return (dir);
}
