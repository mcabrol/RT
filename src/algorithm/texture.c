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

t_vec		texture_coord(double u, double v, t_texture *texture)
{
	int		x;
	int		y;
	t_vec	res;

	x = (double)(texture->width - 1.0) * u * 0.5 * 2.0;
   	y = (double)(texture->height - 1.0) * v * 0.5 * 2.0;
   	x = x % (texture->width - 1);
    y = y % (texture->height - 1);
	vec((double)(texture->width - x), (double)(texture->height - y), 0.0, &res);
    return (res);
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

	double absX = (double)fabs(x);
  	double absY = (double)fabs(y);
  	double absZ = (double)fabs(z);

  	int isXPositive = x > 0 ? 1 : 0;
  	int isYPositive = y > 0 ? 1 : 0;
  	int isZPositive = z > 0 ? 1 : 0;

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
	coord = texture_coord(u, v, &scene->cam.environment[index]);
	color_from_texture(&coord, &scene->cam.environment[index], dest);
}
