/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 15:57:30 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	**minmax_create(void)
{
	double		**minmax;

	if (!(minmax = (double**)ft_memalloc(sizeof(double*) * 2)))
		return (NULL);
	if (!(minmax[0] = (double*)ft_memalloc(sizeof(double) * 3)))
	{
		free(minmax);
		return (NULL);
	}
	if (!(minmax[1] = (double*)ft_memalloc(sizeof(double) * 3)))
	{
		free(minmax[0]);
		free(minmax);
		return (NULL);
	}
	return (minmax);
}

static void		min_max_x(t_vec *rev_ov, t_obj *box, t_ray *ray, \
						double **minmax)
{
	t_vec		pos;

	vec(box->position.x + box->width,
		box->position.y + box->height,
		box->position.z + box->depth, &pos);
	if (rev_ov->x >= 0)
	{
		minmax[0][0] = (box->position.x - ray->origin.x) * rev_ov->x;
		minmax[1][0] = (pos.x - ray->origin.x) * rev_ov->x;
	}
	else
	{
		minmax[0][0] = (pos.x - ray->origin.x) * rev_ov->x;
		minmax[1][0] = (box->position.x - ray->origin.x) * rev_ov->x;
	}
}

static void		min_max_y(t_vec *rev_ov, t_obj *box, t_ray *ray, \
						double **minmax)
{
	t_vec		pos;

	vec(box->position.x + box->width,
		box->position.y + box->height,
		box->position.z + box->depth, &pos);
	if (rev_ov->y >= 0)
	{
		minmax[0][1] = (box->position.y - ray->origin.y) * rev_ov->y;
		minmax[1][1] = (pos.y - ray->origin.y) * rev_ov->y;
	}
	else
	{
		minmax[0][1] = (pos.y - ray->origin.y) * rev_ov->y;
		minmax[1][1] = (box->position.y - ray->origin.y) * rev_ov->y;
	}
}

static void		min_max_z(t_vec *rev_ov, t_obj *box, t_ray *ray, \
						double **minmax)
{
	t_vec		pos;

	vec(box->position.x + box->width,
		box->position.y + box->height,
		box->position.z + box->depth, &pos);
	if (rev_ov->z >= 0)
	{
		minmax[0][2] = (box->position.z - ray->origin.z) * rev_ov->z;
		minmax[1][2] = (pos.z - ray->origin.z) * rev_ov->z;
	}
	else
	{
		minmax[0][2] = (pos.z - ray->origin.z) * rev_ov->z;
		minmax[1][2] = (box->position.z - ray->origin.z) * rev_ov->z;
	}
}

double			**set_min_max(t_obj *box, t_ray *ray)
{
	t_vec		rev_ov;
	double		**minmax;

	divide3(1, &ray->direction, &rev_ov);
	minmax = minmax_create();
	if (minmax)
	{
		min_max_x(&rev_ov, box, ray, minmax);
		min_max_y(&rev_ov, box, ray, minmax);
		min_max_z(&rev_ov, box, ray, minmax);
		return (minmax);
	}
	return (NULL);
}
