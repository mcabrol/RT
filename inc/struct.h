/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:21:04 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/17 21:28:39 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_vec
{
	double				x;
	double				y;
	double 				z;
}						t_vec;

typedef struct			s_algo
{
	int					x;			// Screen x counter
	int					y;			// Screen y counter
	int					s;			// Sample counter
	unsigned int		i;			// Cursor
	unsigned int		sx;			// Zone render x
	unsigned int		sy;			// Zone render y
	t_vec				l;
	t_vec				m;
	t_vec				l_t;
	unsigned short		xseed[3];	// Generate random float
	t_vec				*ls;		// Result
}						t_algo;

typedef struct			s_target
{
	t_vec				a;
	t_vec				b;
	t_vec				ab;
	t_vec				d_t;		// Directon tmp
	t_vec				eye_t;		// Eye tmp
	t_vec				d;			// Vector for ray
}						t_target;

typedef struct			s_ray
{
	t_vec				o; 			// Origin
	t_vec				d;			// Direction
	double				tmin;
	double				tmax;
	int					depth;
}						t_ray;

typedef struct			s_sphere
{
	double				r;			// radius
	t_vec				p;			// position
	t_vec				e;			// emission
	t_vec				f;			// reflection
	int					reflect;	// material type
}						t_sphere;

typedef struct			s_cam
{
	double				fov;
	t_vec				gaze;
	t_vec				eye;
	t_vec				cx;
	t_vec				cy;
}						t_cam;

typedef struct 			s_scene
{
	int					samples;
	t_sphere			obj[12];
}						t_scene;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_win
{
	int 				ac;
	char				**av;
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*data_ptr;
	char				*tmp_data_ptr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_win;

typedef struct			s_opencl
{
	cl_context			context;
	cl_command_queue	queue;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_uint				ret_num_devices;
	cl_device_id		device_id;
	cl_program			program;
	cl_kernel			kernel;
	char				**kernel_src;
	cl_mem				scene;
	cl_mem				objects;
	cl_mem				lights;
	cl_mem				camera;
	cl_mem				img_data;
}						t_opencl;

#endif
