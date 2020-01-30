/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:21:04 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 18:15:33 by mcabrol          ###   ########.fr       */
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

typedef struct			s_object
{
	int					type;			// object type
	double				radius;			// radius
	t_vec				position;		// position
	t_vec 				direction;		// direction
	t_vec				emission;		// emission
	t_vec				color;			// color
	t_vec				normal;			// normal
	t_vec				center;			// center
	t_vec				reflection;		// reflection
	int 				cut;
	t_vec				cut_shift;
	t_vec				cut_dir;
	double 				height;
	t_vec				axis;			// axis
	float				angle;			// angle
	int					reflect;		// material type
}						t_object;

typedef struct			s_camera
{
	t_vec				position;
	t_vec				direction;
	int					i;
}						t_camera;

typedef struct			s_radiance
{
	t_object			elena;
	t_vec				x;
	t_vec				n;
	t_vec				nl;
	t_vec				f;
	t_vec				res;
	double				distance;
	double				type_inter;
	double				p;
	double				pdf;
	int					id;
	int					l_id;
	int					neg;
}						t_radiance;

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

typedef struct			s_render
{
	t_vec				ray[2];		// Ray[0] = origin Ray[1] = direction
	t_vec				cx;
	t_vec				cy;
	t_vec				color;
	double				dx;
	double				dy;
	double				rand;
	t_vec 				bottom_left;// View plane bottom left point
	int					x;			// Screen x counter
	int					y;			// Screen y counter
	int					sx;
	int					sy;
	int					s;			// Samples counter
	int 				num;		// Random start number
	unsigned short		xseed[3];
	int 				samples;
	t_camera 			camera;
	t_object			object[11];
	t_win				win;
}						t_render;

typedef struct			s_thread
{
	pthread_t			thread;
	unsigned int 		x;
	unsigned int 		max;
	t_render			*render;
}						t_thread;

#endif
