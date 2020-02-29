/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/27 14:19:43 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"

# include <math.h>
# include <stdint.h>
# include <fcntl.h>
# include <time.h>

# define SAMPLES 				8

# define HEIGHT					550
# define WIDTH					600

# define H_MAIN					600
# define W_MAIN					400

# define ZERO					0.0, 0.0, 0.0
# define FALSE					0
# define TRUE					1
# define CONTINUE				0
# define STOP					1

# define SETUP					0
# define RENDER					1

# define MAIN					0
# define RENDER 				1

# define OBJ_TYPE				6
# define SPHERE					0
# define PLANE					1
# define CYLINDER				2
# define CONE					3
# define BOX					4
# define CAMERA					5

# define DIFF					0
# define SPEC					1
# define REFR					2

# define PLUS_X 				1
# define MINUS_X 				-1
# define PLUS_Y 				2
# define MINUS_Y 				-2
# define PLUS_Z 				3
# define MINUS_Z 				-3

# define F_GREY					0xd1d1d1
# define F_BLUE					0x0000FF
# define F_RED					0xFF0000
# define F_GREEN				0x00FF00
# define F_WHITE				0xFFFFFF
# define F_BLACK				0x000000

# define REFRACTIVE_INDEX_OUT	1.0
# define REFRACTIVE_INDEX_IN	1.5
# define PI 					3.14159265358979323846
# define EPSILON_SPHERE			1e-4
# define GAMMA 					2.2
# define T_MIN					0.01
# define T_MAX 					1e20

typedef int 		BOOL;

# include "struct.h"

/*
**	rtv1.c
*/

void 			pathtracer(t_rtv1 *rtv1);
int				error(char *strerror);

/*
**	vector.c
*/

void			vec(double a, double b, double c, t_vec *dest);
t_vec			vecp(double a, double b, double c);
void			veccp(t_vec *v, t_vec *dest);
t_vec			*norm(t_vec *v);
double 			norm_s(t_vec *v);
t_vec			rotate_vector(t_vec obj_rotation, t_vec dir);

/*
**	ray.c
*/

void			init_ray(t_vec o, t_vec d, int depth, t_ray *dest);
void 			prepare_ray(t_render *render, t_radiance *target, t_scene *scene);
void			init_cam(t_scene *scene);
void			eval(t_ray *r, double t, t_vec *dest);
void			printr(t_ray *r);
void			printv(t_vec *v);

/*
**	radiance.c
*/

void			radiance(t_scene *scene, t_ray *ray, t_render *render);

/*
**	object.c
*/

t_obj		   	obj(int t,
				   double r,
				   double h,
				   t_vec p,
				   t_vec d,
				   t_vec e,
				   t_vec c,
				   t_vec rot,
				   double a,
				   int cut,
				   double ca,
				   double cb,
				   double cc,
				   int reflect);
void			cut_direction(t_obj *obj);
void			prepare_obj(t_obj *obj);
t_vec 			to_vec(int hex);
void 			print_obj(t_obj *obj);


/*
**	scene.c
*/

void 			init_scene(t_rtv1 *rtv1);

/*
**	light.c
*/

void 			lighting(t_obj *shape, t_ray *ray);

/*
**	normal.c
*/

void 			normal(t_ray *ray, t_obj *shape);
void 			sphere_normal(t_obj *sphere, t_ray *ray);
void 			plane_normal(t_obj *plane, t_ray *ray);
void 			cylinder_normal(t_obj *cylinder, t_ray *ray);
void 			cone_normal(t_obj *cone, t_ray *ray);
void			box_normal(t_obj *box, t_ray *ray);

/*
**	intersect.c
*/

BOOL 			intersect(t_ray *ray, size_t *id, t_scene *scene);
double 			intersect_sphere(t_obj *sphere, t_ray *ray);
double			intersect_plane(t_obj *sphere, t_ray *ray);
double			intersect_cylinder(t_obj *cylinder, t_ray *ray);
double			intersect_cone(t_obj *cone, t_ray *ray);
double			intersect_box(t_obj *box, t_ray *ray);
double			intersect_disk(t_obj *disk, t_ray *ray);

/*
**	operator.c
*/

void			sum(t_vec *v1, t_vec *v2, t_vec *dest);
void			sub(t_vec *v1, t_vec *v2, t_vec *dest);
void			sub_(t_vec *v1, t_vec *v2);
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

/*
**	calcul.c
*/

double			len(t_vec *v);
double			dot(t_vec *v1, t_vec *v2);
double			max(t_vec *v);
double			clamp(double x, double low, double high);
void			clamp3(t_vec *v, double low, double high, t_vec *dest);
uint8_t			to_byte(double x, double gamma);
double			reflectance(double n1, double n2);
double			schlick_reflectance(double n1, double n2, double c);
double			quadratic(double k1, double k2, double k3);
void    		quadratic_base(t_vec k, t_vec *t);
double			check_cut(double t_min, t_obj *obj, t_vec *p);
double			define_tmin(t_vec t);
double 			check_pnt(t_vec *k, t_vec *direction, t_vec *origin, t_obj *obj);
double			ft_check_pnt_box(double min[3], double max[3]);
void			define_norm(t_ray *ray, int face);
void 			check_box(t_ray *ray, double min[3], double max[3], t_vec rev_ov);

/*
**	sample.c
*/

void			cosine_weighted_sample(double u1, double u2, t_vec *dest);

/*
**	srand48.c
*/

void			init_seed(t_render *rt);
int 			russian_roulette(t_ray *ray, t_obj *shape, t_render *render);

/*
**	specular.c
*/

void 			specular(t_ray *ray, t_render *render, t_obj *shape);
void			specular_reflect(t_vec *d, t_vec *n);
void 			specular_diffuse(t_vec *d, t_vec *n, unsigned short xseed[3]);

/*
**	window.c
*/

t_win			window(void *mlx_ptr, int width, int height, char *name);

/*
**	pixel.c
*/

void			put_pixel_vector(t_rtv1 *rtv1, int x, int y, t_vec *v);

/*
**	hook.c
*/

void 			hook(t_rtv1 *rtv1);
int 			hover(int x, int y, t_rtv1 *rtv1);
int				exit_hook(int keycode, t_rtv1 *rtv1);


/*
**	key.c
*/

int				key(int keycode, t_rtv1 *rtv1);

/*
**	mouse.c
*/

int				mouse(int button, int x, int y, t_rtv1 *rtv1);

/*
**	gui.c
*/

t_png 			init_png(void *mlx_ptr);
void 			put_setup(t_rtv1 *rtv1);


/*
**	debbug.c
*/

void 	 		loading_text(int samples, int y, int height);

/*
**	image.c
*/

void 			image(t_rtv1 *rtv1);
void 			write_ppm(t_rtv1 *rtv1);

/*
**	file.c
*/

int				file(int ac, char **av, t_scene *scene);
int				check(int ac, char **av);

/*
**	parse.c
*/

int 			parse(char *str, t_scene *scene);

#endif
