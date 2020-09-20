/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 15:56:11 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		intersect_box(t_obj *box, t_ray *ray)
{
	double		**minmax;
	double		ret;

	minmax = set_min_max(box, ray);
	ret = ft_check_pnt_box(minmax[0], minmax[1]);
	free(minmax);
	return (ret);
}

void		box_normal(t_obj *box, t_ray *ray)
{
	double		**minmax;
	t_vec		rev_ov;

	divide3(1, &ray->direction, &rev_ov);
	minmax = set_min_max(box, ray);
	check_box(ray, minmax[0], minmax[1], rev_ov);
	free(minmax);
}

void		check_box(t_ray *ray, double *min, double *max, t_vec rev_ov)
{
	double		t[2];
	int			facein;
	int			faceout;

	facein = face_in(min, &rev_ov, &t[0]);
	faceout = face_out(max, &rev_ov, &t[0]);
	if (t[0] < t[1] && t[1] > T_MIN && t[1] < T_MAX)
	{
		if (t[0] > T_MIN && t[0] < T_MAX)
			define_norm(ray, facein);
		else
			define_norm(ray, faceout);
	}
}

void		define_norm(t_ray *ray, int face)
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

double		ft_check_pnt_box(double *min, double *max)
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
