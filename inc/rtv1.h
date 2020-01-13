/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/13 18:00:58 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include <OpenCL/opencl.h>
# include <math.h>
# include <stdint.h>

# define HEIGHT					500u
# define WIDTH					600u
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

typedef struct 		s_scene
{
	int				samples;
	t_sphere		obj[9];
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

/*
**	rtv1.c
*/

void 				rtv1(t_win *win);

/*
**	vector.c
*/

t_vec				vec(double a, double b, double c);
t_vec				*cpy(t_vec *v1, t_vec *v2);
t_vec				*norm(t_vec *v);
double 				norm_s(t_vec *v);

/*
**	ray.c
*/

t_ray				ray(t_vec o, t_vec d, double tmin, double tmax, int depth);
t_vec				eval(t_ray *r, double t);
void				printr(t_ray *r);
void				printv(t_vec *v);

/*
**	radiance.c
*/

t_vec 				radiance(t_scene *scene, t_ray *ray, unsigned short xseed[3]);

/*
**	sphere.c
*/

t_sphere			sphere(double r, t_vec p, t_vec e, t_vec f, int reflect);

/*
**	sphere.c
*/

t_scene 			init_scene(void);

/*
**	intersect.c
*/

BOOL 				intersect(t_ray *ray, size_t *id);
BOOL 				intersect_sphere(t_sphere *sphere, t_ray *ray);

/*
**	operator.c
*/

t_vec				sum(t_vec *v1, t_vec *v2);
t_vec				sub(t_vec *v1, t_vec *v2);
t_vec				multi(t_vec *v1, t_vec *v2);
t_vec				nmulti(t_vec *v1, double n);
t_vec				divide(t_vec *v1, t_vec *v2);
t_vec				ndivide(t_vec *v1, double n);
t_vec				divide3(double a, t_vec *v);
double				dot(t_vec *v1, t_vec *v2);
double				max(t_vec *v);
t_vec				minus(t_vec *v);
t_vec				cross(t_vec *v1, t_vec *v2);

/*
**	calcul.c
*/

double				clamp(double x, double low, double high);
t_vec				clamp3(t_vec *v, double low, double high);
uint8_t				to_byte(double x, double gamma);
double				reflectance(double n1, double n2);
double				schlick_reflectance(double n1, double n2, double c);

/*
**	sample.c
*/

t_vec				cosine_weighted_sample(double u1, double u2);

/*
**	specular.c
*/

t_vec				specular_reflect(t_vec *d, t_vec *n);
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


#endif
