/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:23:52 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/15 20:53:48 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		environment_texture(t_scene *scene, t_ray *ray, t_vec *dest)
{
	double	x;
	double	y;
	double	z;
	double	maxaxis;
	double	u;
	double	v;
	int		index;
	t_vec	coord;
	double	absx;
	double	absy;
	double	absz;
	int		isxpositive;
	int		isypositive;
	int		iszpositive;

	x = ray->direction.x;
	y = ray->direction.y;
	z = ray->direction.z;
	absx = (double)fabs(ray->direction.x);
	absy = (double)fabs(ray->direction.y);
	absz = (double)fabs(ray->direction.z);
	isxpositive = ray->direction.x > 0 ? 1 : 0;
	isypositive = ray->direction.y > 0 ? 1 : 0;
	iszpositive = ray->direction.z > 0 ? 1 : 0;
	if (isxpositive && absx >= absy && absx >= absz)
	{
		maxaxis = absx;
		u = -z;
		v = y;
		index = RIGHT;
	}
	if (!isxpositive && absx >= absy && absx >= absz)
	{
		maxaxis = absx;
		u = z;
		v = y;
		index = LEFT;
	}
	if (isypositive && absy >= absx && absy >= absz)
	{
		maxaxis = absy;
		u = x;
		v = -z;
		index = TOP;
	}
	if (!isypositive && absy >= absx && absy >= absz)
	{
		maxaxis = absy;
		u = x;
		v = z;
		index = BOTTOM;
	}
	if (iszpositive && absz >= absx && absz >= absy)
	{
		maxaxis = absz;
		u = x;
		v = y;
		index = FRONT;
	}
	if (!iszpositive && absz >= absx && absz >= absy)
	{
		maxaxis = absz;
		u = -x;
		v = y;
		index = BACK;
	}
	u = 0.5 * (u / maxaxis + 1.0);
	v = 0.5 * (v / maxaxis + 1.0);
	coord = texture_coord(u, v, &scene->cam.environment, index);
	color_from_texture(&coord, &scene->cam.environment, dest, ENVIRONMENT);
}

void		cubemap_offset(t_vec *coord, int index, t_texture *texture)
{
	if (index == RIGHT)
	{
		coord->x += (texture->width * 2);
		coord->y += (texture->height * 1);
	}
	if (index == LEFT)
		coord->y += texture->height;
	if (index == TOP)
		coord->x += (texture->width * 3);
	if (index == BOTTOM)
	{
		coord->x += (texture->width * 3);
		coord->y += (texture->height * 2);
	}
	if (index == FRONT)
	{
		coord->x += (texture->width * 3);
		coord->y += texture->height;
	}
	if (index == BACK)
	{
		coord->x += texture->width;
		coord->y += texture->height;
	}
}
