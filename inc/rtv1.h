/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/29 20:09:37 by mcabrol          ###   ########.fr       */
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

# define THREAD 				16
# define OPT					9

# define T_MIN					0.01
# define T_MAX 					1e20

# define HEIGHT					600
# define WIDTH					600
# define ZERO					0.0, 0.0, 0.0
# define FALSE					0
# define TRUE					1

# define PLANE 					0
# define SPHERE					1
# define CUBE					2
# define CYLINDER				3
# define CONE					4
# define TONUS 					5

# define DIFFUSE				0
# define SPECULAR				1
# define REFRACT				2

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

typedef int 		BOOL;

/*
**	rtv1.c
*/

void 			rtv1(t_render *render);
int				check(int ac, char **av);
int				error(char *strerror);
// void 			thrtv1(t_render *rtv1, int x, int max);

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

void			prepare_ray(t_render *render, unsigned int seed);
void			init_camera(t_render *render);
void			printr(t_vec origin, t_vec direction);
void			printv(t_vec *v);

/*
**	radiance.c
*/

t_vec			radiance(t_render *render, t_vec origin, t_vec direction, unsigned int seed);

/*
**	sphere.c
*/

t_object		obj(int t, double r, t_vec p, t_vec d, t_vec e, t_vec f, int reflect);

/*
**	scene.c
*/

void 			init_scene(t_render *render);

/*
**	intersect.c
*/

void 			intersect(t_vec *origin, t_vec *direction, t_radiance *radiance, t_render *render);
double 			intersect_sphere(t_object *obj, t_vec *origin, t_vec *directon);
double			intersect_plane(t_object *obj, t_vec *origin, t_vec *directon);

/*
**	operator.c
*/

void			sum(t_vec *v1, t_vec *v2, t_vec *dest);
void			sub(t_vec *v1, t_vec *v2, t_vec *dest);
void			multi(t_vec *v1, t_vec *v2, t_vec *dest);
void			nmulti(t_vec *v1, double n, t_vec *dest);
void			divide(t_vec *v1, t_vec *v2, t_vec *dest);
void			ndivide(t_vec *v1, double n, t_vec *dest);
void			divide3(double a, t_vec *v, t_vec *dest);
void			minus(t_vec *v, t_vec *dest);
void			minus_(t_vec *v);
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
double			quadratic(double k1, double k2, double k3);

/*
**	normal.c
*/

void			plane_normal(t_radiance *radiance, t_vec *origin, t_vec *direction, t_object *obj);
void			sphere_normal( t_radiance *radiance, t_vec *origin, t_vec *direction, t_object *obj);

/*
**	sample.c
*/

void			cosine_weighted_sample(double u1, double u2, t_vec *dest);

/*
**	srand48.c
*/

double			rand_ri(unsigned int *seed);
unsigned int	generate(unsigned int x);
unsigned int	generate3(unsigned int x, unsigned int y, unsigned int z);

/*
**	specular.c
*/

t_vec			hemisphere_ray(t_radiance *radiance, t_vec w, unsigned int seed, float alpha);
// void			specular_reflect(t_vec *d, t_vec *n, t_vec *dest);
// t_vec			specular_transmit(t_vec *d, t_vec *n, double n_out,
// 				double n_in, double *pr, unsigned short xseed[3]);

/*
**	mlx.c
*/

int				init_window(char **av, t_render *rtv1);
void			erase(t_render *rtv1);
int				expose_hook(t_render *rtv1);
void			put_pixel(t_render *rtv1, int x, int y, t_vec *v);
int				key(int keycode, t_render *rtv1);

/*
**	opencl.c
*/

void 			init_opencl(t_opencl *cl);

/*
**	multithread.c
*/

int				multithread(t_render *rtv1);
void			*dispatcher(void *var);

/*
**	parse.c
*/

char 			**file(char **av);
int				parse(char **av, t_render *rtv1);
int				data(char *line);
int				size(char **av);

/*
**	debbug.c
*/

void 			loading_text(t_render *render);

#endif
