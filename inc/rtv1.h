/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/22 15:50:58 by mcabrol          ###   ########.fr       */
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
# include <pthread.h>
# include "struct.h"

# define THREAD 				32
# define OPT					9

# define HEIGHT					400u
# define WIDTH					400u
# define ZERO					0.0, 0.0, 0.0
# define FALSE					0
# define TRUE					1

# define PLAN 					0
# define SPHERE					1
# define CUBE					2
# define CYLINDER				3
# define CONE					4
# define TONUS 					5

# define DIFF					0
# define SPEC					1
# define REFR					2

# define TYPE					0
# define RADIUS 				1
# define X						2
# define Y						3
# define Z						4
# define LIGHT 					5
# define R						6
# define G						7
# define B						8

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

/*
**	rtv1.c
*/

void 			rt(t_rtv1 *rtv1);
int				check(int ac, char **av);
int				error(char *strerror);
void 			thrtv1(t_rtv1 *rtv1, int x, int max);



/*
**	vector.c
*/

void			vec(double a, double b, double c, t_vec *dest);
t_vec			vecp(double a, double b, double c);
void			veccp(t_vec *v, t_vec *dest);
t_vec			*norm(t_vec *v);
double 			norm_s(t_vec *v);

/*
**	ray.c
*/

void			ray(t_vec o, t_vec d, double tmin, double tmax, int depth,
				t_ray *dest);
void 			prepare_ray(t_rtv1 *rtv1, t_algo *rt, t_target *target);
void			init_cam(t_rtv1 *rtv1);
void			eval(t_ray *r, double t, t_vec *dest);
void			printr(t_ray *r);
void			printv(t_vec *v);

/*
**	radiance.c
*/

void			radiance(t_rtv1 *rtv1, t_algo *rt, t_ray *ray);

/*
**	sphere.c
*/

t_obj			obj(int t, double r, t_vec p, t_vec e, t_vec f, int reflect);

/*
**	sphere.c
*/

void 			init_scene(char **av, t_rtv1 *rtv1);

/*
**	intersect.c
*/

BOOL 			intersect(t_ray *ray, size_t *id, t_scene *scene);
BOOL 			intersect_sphere(t_obj *sphere, t_ray *ray);
BOOL			intersect_plan(t_obj *plan, t_ray *ray);


/*
**	operator.c
*/

void			sum(t_vec *v1, t_vec *v2, t_vec *dest);
void			sub(t_vec *v1, t_vec *v2, t_vec *dest);
void			multiplication(t_vec *v1, t_vec *v2, t_vec *dest);
void			nmulti(t_vec *v1, double n, t_vec *dest);
void			divide(t_vec *v1, t_vec *v2, t_vec *dest);
void			ndivide(t_vec *v1, double n, t_vec *dest);
void			divide3(double a, t_vec *v, t_vec *dest);
void			minus(t_vec *v, t_vec *dest);
void			cross(t_vec *v1, t_vec *v2, t_vec *dest);
void			sum_(t_vec *v1, t_vec *v2);
void			multi_(t_vec *v1, t_vec *v2);
void			nmulti_(t_vec *v1, double n);
void			ndivide_(t_vec *v1, double n);
void			norm_(t_vec *v, t_vec *dest);



/*
**	calcul.c
*/

double			dot(t_vec *v1, t_vec *v2);
double			ndot(t_vec *v1, double n);
double			max(t_vec *v);
double			clamp(double x, double low, double high);
void			clamp3(t_vec *v, double low, double high, t_vec *dest);
uint8_t			to_byte(double x, double gamma);
double			to_vec(int x, double gamma);
double			reflectance(double n1, double n2);
double			schlick_reflectance(double n1, double n2, double c);

/*
**	sample.c
*/

void			cosine_weighted_sample(double u1, double u2, t_vec *dest);

/*
**	sample.c
*/

void			init_seed(t_algo *rt);

/*
**	specular.c
*/

void			specular_reflect(t_vec *d, t_vec *n, t_vec *dest);
t_vec			specular_transmit(t_vec *d, t_vec *n, double n_out,
				double n_in, double *pr, unsigned short xseed[3]);

/*
**	mlx.c
*/

int				init_window(char **av, t_rtv1 *rtv1);
void			erase(t_rtv1 *rtv1);
int				expose_hook(t_rtv1 *rtv1);
void			put_pixel(t_rtv1 *rtv1, int x, int y, t_vec *v);
int				key(int keycode, t_rtv1 *rtv1);

/*
**	opencl.c
*/

void 			init_opencl(t_opencl *cl);

/*
**	multithread.c
*/

int				multithread(t_rtv1 *rtv1);
void			*dispatcher(void *var);

/*
**	parse.c
*/

char 			**file(char **av);
int				parse(char **av, t_rtv1 *rtv1);
int				size(char **av);

#endif
