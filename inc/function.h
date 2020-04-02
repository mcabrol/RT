/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:56:57 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 18:48:22 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
**	rtv1.c
*/

void 			*pathtracer(void *var);
void 			sampling(t_rtv1 *rtv1, t_render *render);
int				error(char *strerror);

/*
**	ray.c
*/

void			init_ray(t_vec o, t_vec d, t_ray *dest);
void 			prepare_ray(t_render *render, t_radiance *target, t_scene *scene);
void			init_cam(t_scene *scene);
void			eval(t_ray *r, double distance, t_vec *dest);
void			printr(t_ray *r);
void			printv(t_vec *v);

/*
**	radiance.c
*/

void			radiance(t_scene *scene, t_ray *ray, t_render *render);

/*
**	object.c
*/

void			cut_direction(t_obj *obj);
void			prepare_obj(t_obj *obj);
void 			print_obj(t_obj *obj);

/*
**	convert.c
*/

t_vec 			hex_to_vec(int hex);
t_vec 			hex_to_light(int hex);
double 			deg_to_rad(double degree);
double 			rad_to_deg(double radian);
int 			hex_to_dec(char *hex);

/*
**	scene.c
*/

void 			init_scene(t_rtv1 *rtv1, char *file);
options_func 	*setup_obj_setter(void);
void 			build_camera(t_scene *scene);


/*
**	light.c
*/

void 			lighting(t_scene *scene, t_ray *ray, t_obj *shape);

/*
**	texture.c
*/

void 			texture(t_ray *ray, t_obj *shape);
void			uv(t_ray *ray, t_obj *obj, double *u, double *v);
int 			load_texture(t_rtv1 *rtv1, char *path, t_texture *texture);
t_vec			texture_coord(double u, double v, t_texture *texture);
void			color_from_texture(t_vec *sample, t_texture *texture, t_vec *dest);

/*
**	uv.c
*/

void 			uv_sphere(double *u, double *v, t_ray *ray);
void 			uv_plane(double *u, double *v, t_ray *ray);
void 			uv_cylinder(double *u, double *v, t_ray *ray, t_obj *obj);

/*
**	normal.c
*/

void 			normal(t_ray *ray, t_obj *shape);
void 			sphere_normal(t_obj *sphere, t_ray *ray);
void 			plane_normal(t_obj *plane, t_ray *ray);
void 			cylinder_normal(t_obj *cylinder, t_ray *ray);
void 			cylinder_normal_closed(t_obj *cylinder, t_ray *ray);
void 			cone_normal(t_obj *cone, t_ray *ray);
void			box_normal(t_obj *box, t_ray *ray);

/*
**	intersect.c
*/

BOOL 			intersect(t_ray *ray, size_t *id, t_scene *scene);
double 			intersect_sphere(t_obj *sphere, t_ray *ray);
double			intersect_plane(t_obj *sphere, t_ray *ray);
double			intersect_cylinder(t_obj *cylinder, t_ray *ray);
double 			intersect_cylinder_closed(t_obj *cylinder, t_ray *ray);
double			intersect_cone(t_obj *cone, t_ray *ray);
double			intersect_box(t_obj *box, t_ray *ray);
double			intersect_disk(t_obj *disk, t_ray *ray);

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
double			define_ttmin(double t1, double t2);
double 			check_pnt(t_vec *k, t_vec *direction, t_vec *origin, t_obj *obj);
double			ft_check_pnt_box(double min[3], double max[3]);
void			define_norm(t_ray *ray, int face);
void 			check_box(t_ray *ray, double min[3], double max[3], t_vec rev_ov);

/*
**	rotate.c
*/

t_vec			v_matrix_mult(double mat[4][4], t_vec pt);
t_vec			rotate_x(t_vec pt, double theta);
t_vec			rotate_y(t_vec pt, double theta);
t_vec			rotate_z(t_vec pt, double theta);
t_vec			rotate_point(double alpha, double beta, double gamma, t_vec pt);


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
**	reflect.c
*/

void 			reflect(t_ray *ray, t_render *render, t_obj *shape);
t_vec			*specular_reflect(t_vec *d, t_vec *n);
void 			refractive_reflect(t_ray *ray, unsigned short xseed[3], t_obj *obj);
void 			diffuse_reflect(t_vec *d, t_vec *n, unsigned short xseed[3]);

/*
**	window.c
*/

void 			init_window(t_rtv1 *rtv1);
t_win			window(void *mlx_ptr, int width, int height, char *name);

/*
**	pixel.c
*/

void			put_pixel_vector(t_rtv1 *rtv1, int x, int y, t_vec *v);
t_vec 			get_pixel_vector(t_texture *texture, int x, int y);

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
void 			format(t_rtv1 *rtv1, int width, int height);

/*
**	gui.c
*/

t_sprite 		init_sprite(void *mlx_ptr);
void 			put_setup(t_rtv1 *rtv1);
int 			is_hover(int x, int y, int *button, int xmin, int xmax, int ymin, int ymax);

/*
**	debbug.c
*/

void 	 		loading_text(int height, int y);
char 			*stamp(t_rtv1 *rtv1);
void			timer(int time);



/*
**	image.c
*/

void 			image(t_rtv1 *rtv1);
int				init_image(t_rtv1 *rtv1);
void 			write_ppm(t_rtv1 *rtv1);

/*
**	render.c
*/

int 			render(t_rtv1 *rtv1);
int				multithread(t_rtv1 *rtv1);

/*
**	file.c
*/

int				file(int ac, char **av, char **file);
int				check(int ac, char **av);

/*
**	parse.c
*/

int 			parse(char *str, t_scene *scene);

/*
**	setter.c
*/

int				set_position(t_obj *obj, char *value);
int				set_direction(t_obj *obj, char *value);
int				set_emission(t_obj *obj, char *value);
int				set_color(t_obj *obj, char *value);
int				set_reflection(t_obj *obj, char *value);
int				set_radius(t_obj *obj, char *value);
int				set_angle(t_obj *obj, char *value);
int				set_height(t_obj *obj, char *value);
int				set_width(t_obj *obj, char *value);
int 			set_depth(t_obj *obj, char *value);
int				set_camera_matrix(t_scene *scene);
int 			set_fov(t_obj *obj, char *value);
int				set_ambient(t_obj *obj, char *value);
int				set_rotation(t_obj *obj, char *value);
int 			set_texture(t_obj *obj, char *value);
int 			set_texture_scale(t_obj *obj, char *value);
int				set_index(t_obj *obj, char *value);

/*
**	file_error.c
*/

void			throw_error_file(int errorcode, char **data,
				t_scene *scene, int d_allocated);
void 			throw_error(int errorcode);
void 			clean_opt(char **opt);

#endif
