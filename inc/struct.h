/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:21:04 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 18:57:06 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum			e_error
{
	OBJECT_SETTINGS_NOT_FOUND_FILE = 1,
	CAMERA_SETTINGS_NOT_FOUND_FILE,
	INIT_SCENE_OBJ_FAILED,
	INIT_OBJ_BAD_ARGS,
	OBJECT_BAD_FORMAT,
	EXTRACT_DATA_FAILED,
	BAD_TYPE_OBJECT,
	SET_OBJECT_FAILED,
	BAD_OPTIONS,
	SETUP_OBJ_FAILED,
	VECTOR_BAD_VALUE,
	BAD_VALUE,
}						t_error;

typedef struct			s_render
{
	int					x;			// Screen x counter
	int					y;			// Screen y counter
	int					s;			// Sample counter
	unsigned int		i;			// Cursor
	int					sx;			// Zone render x
	int					sy;			// Zone render y
	t_vec				l;
	t_vec				accucolor;  // Color accumulation
	t_vec				color;		// Color calculated
	unsigned short		xseed[3];	// Generate random float
}						t_render;

typedef struct			s_radiance
{
	t_vec				a;
	t_vec				b;
	t_vec				ab;
	t_vec				d_t;		// Directon tmp
	t_vec				origin;		// Eye tmp
	t_vec				d;			// Vector for ray
	t_vec				direction;
}						t_radiance;

typedef struct 			s_texture
{
	char 				*path;
	void				*image;
	char				*data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int 				width;
	int 				height;
}						t_texture;

typedef struct			s_ray
{
	t_vec				origin; 		// Origin
	t_vec				direction;		// Direction
	double				distance;		// Distance
	int					depth;			// Depth
	t_vec				x;				// Point intersect
	t_vec				n;				// Norm obj
	t_vec 				mask;			// Mask
	t_vec				light;			// Light
	t_vec				blank;			// Blank
	double				pr;				// Light mask refraction
}						t_ray;

typedef struct			s_obj
{
	int 				type;			// type
	double				radius;			// radius
	double 				height; 		// height
	double				width;
	double				depth;
	t_vec				position;		// position
	t_vec				direction;		// direction
	t_vec				emission;		// emission
	t_vec				color;			// color
	double				angle;			// angle
	t_vec				rotation;		// rotation
	int					cut;			// type of cut
	t_vec 				cut_direction;	// cut direction
	t_vec 				cut_shift;		// cut shift
	int					reflect;		// material type
	double				fov;			// field-of-view
	double				intersect_type; // For closed obj
	t_vec				cx;				// cam_x
	t_vec				cy;				// cam_y
	t_vec				point;			// Plane bottom left point camera
	t_vec 				ambient;		// Ambient light
	t_texture 			texture;		// Texture struct
	double				index_out;		// Index out refracton
	double				index_in;		// Index out refraction
}						t_obj;

typedef					int (*options_func)(t_obj *obj, char *value);

typedef struct 			s_scene
{
	char				*file;
	int 				width;
	int					height;
	int					samples;
	t_obj 				cam;
	char				**obj_type;
	char				**obj_options;
	t_obj				*obj;
	int					n;			// Number of object
	options_func		*obj_setter;
	t_matrix			*m;
}						t_scene;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_win
{
	void				*win_ptr;
	void				*img_ptr;
	char				*data_ptr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_win;

typedef struct 			t_sprite
{
	int 				h_render;
	int 				h_cancel;
	int 				h_save;
	int 				h_show;
	void 				*background;
	void 				*success;
	void 				*failure;
	void 				*render;
	void 				*cancel;
	void 				*save;
	void 				*show;
	void 				*f480;
	void 				*f720;
	void 				*f1080;
	void 				*s8;
	void 				*s40;
	void 				*s200;
	void 				*s500;
	void 				*s1000;
}						t_sprite;

typedef struct			s_rtv1
{
	int					ac;
	char				**av;
	int					id_win;
	int					id_ppm;
	t_sprite 			png;
	int 				state;
	void				*mlx_ptr;
	t_win 				main;
	t_win 				*image;
	t_scene				scene;
	t_vec				*screen;	// Result
}						t_rtv1;

typedef struct			s_thread
{
	pthread_t			thread;
	int 				id;
	int					x;
	int					max;
	t_rtv1				*rtv1;
}						t_thread;

#endif
