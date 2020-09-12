/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 16:47:13 by mcabrol          ###   ########.fr       */
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

void		box_normal(t_obj *box, t_ray *ray)
{
	double			min[3];
	double			max[3];
	t_vec			rev_o;
	t_vec			p;

	divide3(1, &ray->direction, &rev_o);
	vec(box->position.x + box->width, box->position.y + box->height, box->position.z + box->depth, &p);
	if (rev_o.x >= 0)
	{
		min[0] = (box->position.x - ray->origin.x) * rev_o.x;
		max[0] = (p.x - ray->origin.x) * rev_o.x;
	}
	else
	{
		min[0] = (p.x - ray->origin.x) * rev_o.x;
		max[0] = (box->position.x - ray->origin.x) * rev_o.x;
	}
	if (rev_o.y >= 0)
	{
		min[1] = (box->position.y - ray->origin.y) * rev_o.y;
		max[1] = (p.y - ray->origin.y) * rev_o.y;
	}
	else
	{
		min[1] = (p.y - ray->origin.y) * rev_o.y;
		max[1] = (box->position.y - ray->origin.y) * rev_o.y;
	}
	if (rev_o.z >= 0)
	{
		min[2] = (box->position.z - ray->origin.z) * rev_o.z;
		max[2] = (p.z - ray->origin.z) * rev_o.z;
	}
	else
	{
		min[2] = (p.z - ray->origin.z) * rev_o.z;
		max[2] = (box->position.z - ray->origin.z) * rev_o.z;
	}
	check_box(ray, min, max, rev_o);
}

void 		check_box(t_ray *ray, double min[3], double max[3], t_vec rev_ov)
{
	double		t[2];
	int			face_in;
	int			face_out;

	if (min[0] > min[1])
	{
		t[0] = min[0];
		face_in = (rev_ov.x >= 0.0) ? 0 : 3;
	}
	else
	{
		t[0] = min[1];
		face_in = (rev_ov.y >= 0.0) ? 1 : 4;
	}
	if (min[2] > t[0])
	{
		t[0] = min[2];
		face_in = (rev_ov.z >= 0.0) ? 2 : 5;
	}
	if (max[0] < max[1])
	{
		t[1] = max[0];
		face_out = (rev_ov.x >= 0.0) ? 3 : 0;
	}
	else
	{
		t[1] = max[1];
		face_out = (rev_ov.y >= 0.0) ? 4 : 1;
	}
	if (max[2] < t[1])
	{
		t[1] = max[2];
		face_out = (rev_ov.z >= 0.0) ? 5 : 2;
	}
	if (t[0] < t[1] && t[1] > T_MIN && t[1] < T_MAX)
	{
		if (t[0] > T_MIN && t[0] < T_MAX)
			define_norm(ray, face_in);
		else
			define_norm(ray, face_out);
	}
}

void	define_norm(t_ray *ray, int face)
{
	if (face == 0)
		vec(-1.0, 0.0, 0.0, &ray->n);
	else if (face == 1)
		vec(0.0, -1.0, 0.0, &ray->n);
	else if (face == 2)
		vec(0.0, 0.0, -1.0, &ray->n);
	else if (face == 3)
		vec(1.0, 0.0, 0.0, &ray->n);
	else if (face == 4)
		vec(0.0, 1.0, 0.0, &ray->n);
	else
		vec(0.0, 0.0, 1.0, &ray->n);
}

double		ft_check_pnt_box(double min[3], double max[3])
{
	double		t[2];

	if (min[0] > min[1])
		t[0] = min[0];
	else
		t[0] = min[1];
	if (min[2] > t[0])
		t[0] = min[2];

	if (max[0] < max[1])
		t[1] = max[0];
	else
		t[1] = max[1];
	if (max[2] < t[1])
		t[1] = max[2];
	if (t[0] < t[1] && t[1] > T_MIN && t[1] < T_MAX)
	{
		if (t[0] > T_MIN && t[0] < T_MAX)
			min[0] = t[0];
		else
			min[0] = t[1];
		return (min[0]);
	}
	return (T_MAX);
}
