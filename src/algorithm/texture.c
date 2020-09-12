/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:25:45 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 14:25:09 by mcabrol          ###   ########.fr       */
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
		color_from_texture(&sample, &shape->texture, &shape->color);
	}
	multi_(&ray->mask, &shape->color);
}

int			load_texture(t_rtv1 *rtv1, char *path, t_texture *texture)
{
	texture->image = NULL;
	texture->path = path;
	if ((texture->image = mlx_png_file_to_image(rtv1->mlx_ptr, path, \
		&texture->width, &texture->height)) == NULL)
		return (EXIT_FAILURE);
	texture->data = mlx_get_data_addr(texture->image,
									&(texture->bits_per_pixel),
									&(texture->size_line),
									&(texture->endian));
	return (EXIT_SUCCESS);
}

t_vec		texture_coord(double u, double v, t_texture *texture, int index)
{
	int		x;
	int		y;
	t_vec	res;

	if (index >= 0)
		texture->scale = 0.5;
	x = (double)(texture->width - 1.0) * u * texture->scale * 2.0;
	y = (double)(texture->height - 1.0) * v * texture->scale * 2.0;
	x = x % (texture->width - 1);
	y = y % (texture->height - 1);
	vec((double)(texture->width - x), (double)(texture->height - y), 0.0, &res);
	cubemap_offset(&res, index, texture);
	return (res);
}

void		color_from_texture(t_vec *sample, t_texture *texture, t_vec *dest)
{
	int		x;
	int		y;
	t_vec	img;

	x = texture->width - sample->x;
	y = sample->y;
	img = get_pixel_vector(texture, x, y);
	dest->x = img.x;
	dest->y = img.y;
	dest->z = img.z;
}
