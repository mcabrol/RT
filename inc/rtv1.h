/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/15 17:22:58 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"

# include <OpenCL/OpenCL.h>

# include <math.h>
# include <stdint.h>
# include <fcntl.h>

# define HEIGHT					400u
# define WIDTH					400u
# define ZERO					0.0, 0.0, 0.0
# define FALSE					0
# define TRUE					1

# define DIFF					0
# define SPEC					1
# define REFR					2

# define REFRACTIVE_INDEX_OUT	1.0
# define REFRACTIVE_INDEX_IN	1.5
# define PI 					3.14159265358979323846
# define EPSILON_SPHERE			1e-4
# define GAMMA 					2.2

# define RAND48_SEED_0			(0x330e)
# define RAND48_SEED_1			(0xabcd)
# define RAND48_SEED_2			(0x1234)
# define RAND48_MULT_0			(0xe66d)
# define RAND48_MULT_1			(0xdeec)
# define RAND48_MULT_2			(0x0005)
# define RAND48_ADD   			(0x000b)

typedef int 		BOOL;

typedef struct		s_vec
{
	double			x;
	double			y;
	double 			z;
}					t_vec;

typedef struct		s_algo
{
	int				x;			// Screen x counter
	int				y;			// Screen y counter
	int				s;			// Sample counter
	unsigned int	i;			// Cursor
	unsigned int	sx;			// Zone render x
	unsigned int	sy;			// Zone render y
	t_vec			l;
	t_vec			m;
	t_vec			l_t;
	unsigned short	xseed[3];	// Generate random float
	t_vec			*ls;		// Result
}					t_algo;

typedef struct		s_target
{
	t_vec			a;
	t_vec			b;
	t_vec			ab;
	t_vec			d_t;		// Directon tmp
	t_vec			eye_t;		// Eye tmp
	t_vec			d;			// Vector for ray
}					t_target;

typedef struct		s_ray
{
	t_vec			o; 			// Origin
	t_vec			d;			// Direction
	double			tmin;
	double			tmax;
	int				depth;
}					t_ray;

typedef struct		s_sphere
{
	double			r;			// radius
	t_vec			p;			// position
	t_vec			e;			// emission
	t_vec			f;			// reflection
	int				reflect;	// material type
}					t_sphere;

typedef struct		s_cam
{
	double			fov;
	t_vec			gaze;
	t_vec			eye;
	t_vec			cx;
	t_vec			cy;
}					t_cam;

typedef struct 		s_scene
{
	int				samples;
	t_sphere		obj[12];
}					t_scene;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_win
{
	int 			ac;
	char			**av;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	char			*tmp_data_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_win;

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
	char				*kernel_src;
	cl_mem				scene;
	cl_mem				objects;
	cl_mem				lights;
	cl_mem				camera;
	cl_mem				img_data;
}						t_opencl;

/*
**	rtv1.c
*/

void 				rtv1(t_win *win);


/*
**	vector.c
*/

void				vec(double a, double b, double c, t_vec *dest);
t_vec				vecp(double a, double b, double c);
void				veccp(t_vec *v, t_vec *dest);
t_vec				*norm(t_vec *v);
double 				norm_s(t_vec *v);

/*
**	ray.c
*/

void				ray(t_vec o, t_vec d, double tmin, double tmax, int depth, t_ray *dest);
void 				prepare_ray(t_algo *rt, t_target *target, t_cam *cam);
void				init_cam(t_cam *cam);
void				eval(t_ray *r, double t, t_vec *dest);
void				printr(t_ray *r);
void				printv(t_vec *v);

/*
**	radiance.c
*/

void				radiance(t_scene *scene, t_ray *ray, t_algo *rt);

/*
**	sphere.c
*/

t_sphere			sphere(double r, t_vec p, t_vec e, t_vec f, int reflect);

/*
**	sphere.c
*/

void 				init_scene(t_scene *scene, t_win *win);

/*
**	intersect.c
*/

BOOL 				intersect(t_ray *ray, size_t *id, t_scene *scene);
BOOL 				intersect_sphere(t_sphere *sphere, t_ray *ray);

/*
**	operator.c
*/

void				sum(t_vec *v1, t_vec *v2, t_vec *dest);
void				sub(t_vec *v1, t_vec *v2, t_vec *dest);
void				multiplication(t_vec *v1, t_vec *v2, t_vec *dest);
void				nmulti(t_vec *v1, double n, t_vec *dest);
void				divide(t_vec *v1, t_vec *v2, t_vec *dest);
void				ndivide(t_vec *v1, double n, t_vec *dest);
void				divide3(double a, t_vec *v, t_vec *dest);
void				minus(t_vec *v, t_vec *dest);
void				cross(t_vec *v1, t_vec *v2, t_vec *dest);
void				sum_(t_vec *v1, t_vec *v2);
void				multi_(t_vec *v1, t_vec *v2);
void				nmulti_(t_vec *v1, double n);
void				ndivide_(t_vec *v1, double n);

/*
**	calcul.c
*/

double				dot(t_vec *v1, t_vec *v2);
double				max(t_vec *v);
double				clamp(double x, double low, double high);
void				clamp3(t_vec *v, double low, double high, t_vec *dest);
uint8_t				to_byte(double x, double gamma);
double				reflectance(double n1, double n2);
double				schlick_reflectance(double n1, double n2, double c);

/*
**	sample.c
*/

void				cosine_weighted_sample(double u1, double u2, t_vec *dest);

/*
**	sample.c
*/

void				init_seed(t_algo *rt);

/*
**	specular.c
*/

void				specular_reflect(t_vec *d, t_vec *n, t_vec *dest);
t_vec				specular_transmit(t_vec *d, t_vec *n, double n_out,
					double n_in, double *pr, unsigned short xseed[3]);

/*
**	specular.c
*/

int					window(t_win *win);
void				erase(t_win *win);
int					expose_hook(t_win *win);
void				put_pixel(t_win *win, int x, int y, t_vec *v);
int					key(int keycode, t_win *win);

/*
**	opencl.c
*/

void 				opencl(void);

#endif
