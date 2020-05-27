/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 17:26:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	free_scene(t_scene *scene)
{
	free(scene->file);
	ft_tabdel(scene->obj_type);
	ft_tabdel(scene->obj_options);
	// free_obj(&scene->cam);
}

void 	free_obj(t_obj *obj)
{
	if (obj->texture.path)
	{
		// free(obj->texture.path);
		// free(obj->texture.data);
		// free(obj->texture.image);
	}


}

void free_texture(t_scene *scene)
{
	int i;
	t_obj *obj;

	i = -1;
	obj = NULL;
	while (++i < scene->n)
	{
		obj = &scene->obj[i];
		if (obj->texture.path)
		{
			free(obj->texture.path);
			free(obj->texture.data);
			free(obj->texture.image);
		}
	}
}

// char 				*path;
// void				*image;
// char				*data;
// int					bits_per_pixel;
// int					size_line;
// int					endian;
// int 				width;
// int 				height;
// double				scale;

// int 				type;			// type
// double				radius;			// radius
// double 				height; 		// height
// double				width;
// double				depth;
// t_vec				position;		// position
// t_vec				direction;		// direction
// t_vec				emission;		// emission
// t_vec				color;			// color
// double				angle;			// angle
// t_vec				rotation;		// rotation
// int					reflect;		// material type
// double				fov;			// field-of-view
// double				intersect_type; // For closed obj
// t_vec				cx;				// cam_x
// t_vec				cy;				// cam_y
// t_vec				point;			// Plane bottom left point camera
// t_vec 				ambient;		// Ambient light
// t_texture 			texture;		// Texture struct
// t_texture 			environment;	// Environment cube map
// double				index_out;		// Index out refracton
// double				index_in;		// Index out refraction
// t_vec 				background; 	// Background Color

// char				*file;
// int 				width;
// int					height;
// int					samples;
// t_obj 				cam;
// char				**obj_type;
// char				**obj_options;
// t_obj				*obj;
// int					n;			// Number of object
// options_func		*obj_setter;
// t_matrix			*m;
