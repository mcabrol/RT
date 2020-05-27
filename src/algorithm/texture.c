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
		sample = texture_coord(u, v, &shape->texture, NORMAL);
		color_from_texture(&sample, &shape->texture, &shape->color);
	}
	multi_(&ray->mask, &shape->color);
}

int 		load_texture(t_rtv1 *rtv1, char *path, t_texture *texture)
{
	texture->image = NULL;
	texture->path = path;
	if ((texture->image = mlx_png_file_to_image(&rtv1->mlx_ptr, path, &texture->width, &texture->height)) == NULL)
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

void 		cubemap_offset(t_vec *coord, int index, t_texture *texture)
{
	if (index == RIGHT)
	{
		coord->x += (texture->width * 2);
		coord->y += (texture->height * 1);
	}
	if (index == LEFT)
		coord->y += texture->height;
	if (index == TOP)
	{
		coord->x += (texture->width * 3);
	}
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

void		color_from_texture(t_vec *sample, t_texture *texture, t_vec *dest)
{
	int		x;
	int 	y;
	t_vec	img;

	x = texture->width - sample->x;
	y = sample->y;
	img = get_pixel_vector(texture, x, y);
	dest->x = img.x;
	dest->y = img.y;
	dest->z = img.z;
}

void 		environment_texture(t_scene *scene, t_ray *ray, t_vec *dest)
{
	double 	x;
	double	y;
	double	z;
	double 	maxAxis;
	double	u;
	double	v;
	int		index;
	t_vec	coord;

	x = ray->direction.x;
	y = ray->direction.y;
	z = ray->direction.z;

	double absX = (double)fabs(ray->direction.x);
  	double absY = (double)fabs(ray->direction.y);
  	double absZ = (double)fabs(ray->direction.z);

  	int isXPositive = ray->direction.x > 0 ? 1 : 0;
  	int isYPositive = ray->direction.y > 0 ? 1 : 0;
  	int isZPositive = ray->direction.z > 0 ? 1 : 0;

  	if (isXPositive && absX >= absY && absX >= absZ)
	{
    	maxAxis = absX;
    	u = -z;
    	v = y;
    	index = RIGHT;
  	}
  	if (!isXPositive && absX >= absY && absX >= absZ)
	{
    	maxAxis = absX;
    	u = z;
    	v = y;
    	index = LEFT;
  	}
  	if (isYPositive && absY >= absX && absY >= absZ)
	{
    	maxAxis = absY;
    	u = x;
    	v = -z;
    	index = TOP;
  	}
  	if (!isYPositive && absY >= absX && absY >= absZ)
	{
    	maxAxis = absY;
    	u = x;
    	v = z;
    	index = BOTTOM;
  	}
  	if (isZPositive && absZ >= absX && absZ >= absY)
	{
    	maxAxis = absZ;
    	u = x;
    	v = y;
    	index = FRONT;
  	}
  	if (!isZPositive && absZ >= absX && absZ >= absY)
  	{
    	maxAxis = absZ;
    	u = -x;
    	v = y;
    	index = BACK;
  	}
  	u = 0.5 * (u / maxAxis + 1.0);
  	v = 0.5 * (v / maxAxis + 1.0);
	coord = texture_coord(u, v, &scene->cam.environment, index);
	color_from_texture(&coord, &scene->cam.environment, dest);
}
