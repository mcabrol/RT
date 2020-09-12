/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 13:48:55 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		intersect_box(t_obj *box, t_ray *ray)
{
	double		min[3];
	double		max[3];
	t_vec		rev_ov;
	t_vec		pos;

	divide3(1, &ray->direction, &rev_ov);
	vec(box->position.x + box->width,
		box->position.y + box->height,
		box->position.z + box->depth, &pos);
	if (rev_ov.x >= 0)
	{
		min[0] = (box->position.x - ray->origin.x) * rev_ov.x;
		max[0] = (pos.x - ray->origin.x) * rev_ov.x;
	}
	else
	{
		min[0] = (pos.x - ray->origin.x) * rev_ov.x;
		max[0] = (box->position.x - ray->origin.x) * rev_ov.x;
	}
	if (rev_ov.y >= 0)
	{
		min[1] = (box->position.y - ray->origin.y) * rev_ov.y;
		max[1] = (pos.y - ray->origin.y) * rev_ov.y;
	}
	else
	{
		min[1] = (pos.y - ray->origin.y) * rev_ov.y;
		max[1] = (box->position.y - ray->origin.y) * rev_ov.y;
	}
	if (rev_ov.z >= 0)
	{
		min[2] = (box->position.z - ray->origin.z) * rev_ov.z;
		max[2] = (pos.z - ray->origin.z) * rev_ov.z;
	}
	else
	{
		min[2] = (pos.z - ray->origin.z) * rev_ov.z;
		max[2] = (box->position.z - ray->origin.z) * rev_ov.z;
	}
	return (ft_check_pnt_box(min, max));
}
