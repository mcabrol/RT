/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:25:45 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/10 18:38:59 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		texture(t_ray *ray, t_obj *shape)
{
	double 	u;
	double 	v;
	t_vec	sample;

	if (shape->texture.path)
	{
		uv(ray, shape, &u, &v);
		sample = texture_coord(u, v, &shape->texture);
		color_from_texture(&sample, &shape->texture, &shape->color);
	}
	multi_(&ray->mask, &shape->color);
}

void		uv(t_ray *ray, t_obj *obj, double *u, double *v)
{
	if (obj->type == SPHERE)
	{
		*u = (double)(0.5 + (atan2(ray->n.z, ray->n.x) / (2.0 * M_PI)));
		*v = (double)(0.5 - (asin(ray->n.y) / M_PI));
	}
}

int 		load_texture(t_rtv1 *rtv1, char *path, t_texture *texture)
{
	texture->image = NULL;
	if ((texture->image = mlx_png_file_to_image(&rtv1->mlx_ptr, path, &texture->width, &texture->height)) == NULL)
		return (EXIT_FAILURE);
	texture->data = mlx_get_data_addr(texture->image,
									&(texture->bits_per_pixel),
									&(texture->size_line),
									&(texture->endian));
	return (EXIT_SUCCESS);
}

t_vec		texture_coord(double u, double v, t_texture *texture)
{
	int		x;
	int		y;
	t_vec	res;

	x = (double)(texture->width - 1) * u * 2;
   	y = (double)(texture->height - 1) * v * 2;
   	x = x % (texture->width - 1);
    y = y % (texture->height - 1);
	vec((double)x, (double)y, 0, &res);
    return (res);
}

void		color_from_texture(t_vec *sample, t_texture *texture, t_vec *dest)
{
	int		x;
	int 	y;
	t_vec	img;

	x = sample->x;
	y = sample->y;
	img = get_pixel_vector(texture, x, y);
	dest->z = img.x;
	dest->y = img.y;
	dest->x = img.z;
}
