/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:25:45 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 14:30:49 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		texture(t_ray *ray, t_obj *shape)
{
	double	u;
	double	v;
	t_vec	sample;

	if (shape->texture.path)
	{
		uv(ray, shape, &u, &v);
		sample = texture_coord(u, v, &shape->texture, NORMAL);
		color_from_texture(&sample, &shape->texture, &shape->color, TEXTURE);
	}
	multi_(&ray->mask, &shape->color);
}

int			load_texture(t_rtv1 *rtv1, t_obj *obj)
{
	obj->texture.image = NULL;
	obj->environment.image = NULL;
	if (obj->type == CAMERA)
	{
		if (!(obj->environment.image = mlx_png_file_to_image(rtv1->mlx_ptr, \
			obj->environment.path, &obj->environment.width, \
			&obj->environment.height)))
			return (EXIT_FAILURE);
		obj->environment.data = mlx_get_data_addr(obj->environment.image,
										&(obj->environment.bits_per_pixel),
										&(obj->environment.size_line),
										&(obj->environment.endian));
	}
	else
	{
		if (!(obj->texture.image = mlx_png_file_to_image(rtv1->mlx_ptr, \
			obj->texture.path, &obj->texture.width, &obj->texture.height)))
			return (EXIT_FAILURE);
		obj->texture.data = mlx_get_data_addr(obj->texture.image,
										&(obj->texture.bits_per_pixel),
										&(obj->texture.size_line),
										&(obj->texture.endian));
	}
	return (EXIT_SUCCESS);
}

t_vec		texture_coord(double u, double v, t_texture *texture, int index)
{
	int		x;
	int		y;
	int		environment;
	t_vec	res;

	environment = (index >= 0) ? TRUE : FALSE;
	if (environment)
		texture->scale = 1.0;
	x = (double)(texture->width - 1.0) * u * texture->scale;
	y = (double)(texture->height - 1.0) * v * texture->scale;
	x = x % (texture->width - 1);
	y = y % (texture->height - 1);
	if (environment)
		vec((double)(texture->width - x), \
			(double)(texture->height - y), 0.0, &res);
	else
		vec((double)(x), (double)(y), 0.0, &res);
	cubemap_offset(&res, index, texture);
	return (res);
}

void		color_from_texture(t_vec *sample, t_texture *texture, \
								t_vec *dest, int type)
{
	int		x;
	int		y;
	t_vec	img;

	x = texture->width - sample->x;
	y = sample->y;
	img = get_pixel_vector(texture, x, y, type);
	dest->x = img.x;
	dest->y = img.y;
	dest->z = img.z;
}
