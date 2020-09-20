/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:23:52 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 13:03:10 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	void setup_data(t_env_texture *data, t_ray *ray)
{
	data->xyz[0] = ray->direction.x;
	data->xyz[1] = ray->direction.y;
	data->xyz[2] = ray->direction.z;
	data->abs[0] = (double)fabs(ray->direction.x);
	data->abs[1] = (double)fabs(ray->direction.y);
	data->abs[2] = (double)fabs(ray->direction.z);
	data->positive[0] = ray->direction.x > 0 ? 1 : 0;
	data->positive[1] = ray->direction.y > 0 ? 1 : 0;
	data->positive[2] = ray->direction.z > 0 ? 1 : 0;
}

static void positive(t_env_texture *data, int whichone)
{
	if (whichone == 0)
	{
		data->maxaxis = data->abs[0];
		data->uv[0] = data->xyz[2] * -1;
		data->uv[1] = data->xyz[1];
		data->index = RIGHT;
	}
	else if (whichone == 1)
	{
		data->maxaxis = data->abs[2];
		data->uv[0] = data->xyz[0];
		data->uv[1] = data->xyz[1];
		data->index = FRONT;
	}
	else if (whichone == 2)
	{
		data->maxaxis = data->abs[1];
		data->uv[0] = data->xyz[0];
		data->uv[1] = data->xyz[2] * -1;
		data->index = TOP;
	}
}

static void not_positive(t_env_texture *data, int whichone)
{
	if (whichone == 0)
	{
		data->maxaxis = data->abs[0];
		data->uv[0] = data->xyz[2];
		data->uv[1] = data->xyz[1];
		data->index = LEFT;
	}
	else if (whichone == 1)
	{
		data->maxaxis = data->abs[1];
		data->uv[0] = data->xyz[0];
		data->uv[1] = data->xyz[1];
		data->index = BOTTOM;
	}
	else if (whichone == 2)
	{
		data->maxaxis = data->abs[2];
		data->uv[0] = data->xyz[0] * -1;
		data->uv[1] = data->xyz[1];
		data->index = BACK;
	}

}

// static void debbug_struct(t_env_texture *data)
// {
// 	printf("xyz : [%f:%f:%f]\n", data->xyz[0], data->xyz[1], data->xyz[2]);
// 	printf("uv : [%f:%f]\n", data->uv[0], data->uv[1]);
// 	printf("abs: [%f:%f:%f]\n", data->xyz[0], data->xyz[1], data->xyz[2]);
// 	printf("positive : [%d:%d:%d]\n", data->positive[0], data->positive[1], data->positive[2]);
// 	printf("maxaxis : %f\n", data->maxaxis);
// 	printf("index : %d\n", data->index);
// }

void		environment_texture(t_scene *scene, t_ray *ray, t_vec *dest)
{
	t_env_texture		d;
	t_vec				coord;

	setup_data(&d, ray);
	if (d.positive[0] && d.abs[0] >= d.abs[1] && d.abs[0] >= d.abs[2])
		positive(&d, 0);
	if (d.positive[2] && d.abs[2] >= d.abs[0] && d.abs[2] >= d.abs[1])
		positive(&d, 1);
	if (d.positive[1] && d.abs[1] >= d.abs[0] && d.abs[1] >= d.abs[2])
		positive(&d, 2);
	if (!d.positive[0] && d.abs[0] >= d.abs[1] && d.abs[0] >= d.abs[2])
		not_positive(&d, 0);
	if (!d.positive[1] && d.abs[1] >= d.abs[0] && d.abs[1] >= d.abs[2])
		not_positive(&d, 1);
	if (!d.positive[2] && d.abs[2] >= d.abs[0] && d.abs[2] >= d.abs[1])
		not_positive(&d, 2);
	d.uv[0] = 0.5 * (d.uv[0] / d.maxaxis + 1.0);
	d.uv[1] = 0.5 * (d.uv[1] / d.maxaxis + 1.0);
	coord = texture_coord(d.uv[0], d.uv[1], &scene->cam.environment, d.index);
	color_from_texture(&coord, &scene->cam.environment, dest, ENVIRONMENT);
	printv(dest);
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
