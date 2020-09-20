/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:21:04 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 16:22:31 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum			e_error
{
	OBJECT_STNGS_NOT_FOUND_FILE = 1,
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
	unsigned short		xseed[3];
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

typedef struct			s_texture
{
	char 				*path;
	void				*image;
	char				*data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	int 				width;
	int 				height;
	double				scale;
}						t_texture;

typedef	struct			s_env_texture
{
	double				xyz[3];
	double				maxaxis;
	double				uv[2];
	int					index;
	double				abs[3];
	int					positive[3];
}						t_env_texture;

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
	int					reflect;		// material type
	double				fov;			// field-of-view
	double				intersect_type; // For closed obj
	t_vec				cx;				// cam_x
	t_vec				cy;				// cam_y
	t_vec				point;			// Plane bottom left point camera
	t_vec 				ambient;		// Ambient light
	t_texture 			texture;		// Texture struct
	t_texture 			environment;	// Environment cube map
	double				index_out;		// Index out refracton
	double				index_in;		// Index out refraction
	t_vec 				background; 	// Background Color
}						t_obj;

typedef int				(*options_func)(t_obj *obj, char *value);

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
	double 				loading;
	pthread_mutex_t 	lock;
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
	int					id_window;
	int					available;
}						t_win;

typedef struct			s_position
{
	int 				xmin;
	int 				xmax;
	int					ymin;
	int 				ymax;
}						t_position;


typedef struct			s_button
{
	BOOL 				is_hover;
	BOOL 				is_active;
	void 				*active;
	void 				*disabled;
	void 				*hover;
	void 				*hover_disabled;
	t_position			position;
}						t_button;

typedef struct 			s_sprite
{
	void 				*background;
	void 				*background_setting;
	t_button			setup;
	t_button			close;
	t_button			retry;
	t_button			save;
	t_button			display;
	t_button			render;
	t_button			error;
	t_button			sample;
	t_button			format;
	t_button			close_setting;
	t_button			x8;
	t_button			x20;
	t_button			x200;
	t_button			x500;
	t_button			x1000;
	t_button			x5000;
	t_button			f320;
	t_button			f854;
	t_button			f1024;
	t_button			f1280;
	t_button			f1400;
	t_button			f1920;
}						t_sprite;

typedef struct			s_rtv1
{
	int					ac;
	char				**av;
	char				*file_str;
	int					id_win;
	int					id_render;
	int					id_ppm;
	int					id_parse;
	int 				id_setting;
	BOOL				setter;
	t_sprite 			sprite;
	int 				state;
	int 				tabs;
	void				*mlx_ptr;
	t_win 				main;
	t_win 				setting;
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
