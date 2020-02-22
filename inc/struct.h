/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:21:04 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/19 15:57:52 by judrion          ###   ########.fr       */
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
	t_vec				*screen;	// Result
}						t_render;

typedef struct			s_radiance
{
	t_vec				a;
	t_vec				b;
	t_vec				ab;
	t_vec				d_t;		// Directon tmp
	t_vec				eye_t;		// Eye tmp
	t_vec				d;			// Vector for ray
}						t_radiance;

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
}						t_ray;

typedef struct			s_obj
{
	int 				type;			// type
	double				radius;			// radius
	double 				height; 		// height
	t_vec				position;		// position
	t_vec				direction;		// direction
	t_vec				emission;		// emission
	t_vec				color;			// color
	double				angle;			// angle
	t_vec				rotation;		// rotation
	int					cut;			// type of cut
	t_vec 				cut_direction;	// cut direction
	t_vec 				cut_shift;		// cut shift
	double 				a;				// box a
	double 				b;				// box b
	double 				c;				// box c
	int					reflect;		// material type
}						t_obj;

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
	int 				width;
	int					height;
	int					samples;
	t_obj				obj[4];
	int					n;			// Number of object
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

typedef struct 			s_png
{
	void 				*background;
	void 				*success;
	void 				*failure;
	void 				*f480;
	void 				*f720;
	void 				*f1080;
	void 				*s8;
	void 				*s40;
	void 				*s200;
	void 				*s500;
	void 				*s1000;
	int 				format1;
	int 				format2;
	int 				format3;
	int 				sample1;
	int 				sample2;
	int 				sample3;
	int 				sample4;
	int 				sample5;
}						t_png;

typedef struct			s_rtv1
{
	t_png 				png;
	int 				state;
	void				*mlx_ptr;
	t_win 				main;
	t_win 				image;
	t_scene				scene;
	t_render 			render;
}						t_rtv1;

#endif
