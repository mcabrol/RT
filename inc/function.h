/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:56:57 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/14 21:41:15 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

/*
**	ALGORITHM
*/

/*
**	box.c
*/

double			intersect_box(t_obj *box, t_ray *ray);
void			box_normal(t_obj *box, t_ray *ray);
double			ft_check_pnt_box(double min[3], double max[3]);
void			define_norm(t_ray *ray, int face);
void			check_box(t_ray *ray, double min[3], double max[3],
				t_vec rev_ov);

/*
**	camera.c
*/

int				init_cam(t_rtv1 *rtv1);
t_obj			*assign_camera(t_scene *scene);
int				set_camera(t_obj *camera, t_rtv1 *rtv1);
void			set_default_camera(t_rtv1 *rtv1);
void			build_camera(t_scene *scene);

/*
**	cubemap.c
*/

void			environment_texture(t_scene *scene, t_ray *ray, t_vec *dest);
void			cubemap_offset(t_vec *coord, int index, t_texture *texture);

/*
**	intersect.c
*/

BOOL			intersect(t_ray *ray, size_t *id, t_scene *scene);
double			intersect_sphere(t_obj *sphere, t_ray *ray);
double			intersect_plane(t_obj *sphere, t_ray *ray);
double			intersect_cylinder(t_obj *cylinder, t_ray *ray);
double			intersect_cone(t_obj *cone, t_ray *ray);

/*
**	light.c
*/

void			lighting(t_scene *scene, t_ray *ray, t_obj *shape);

/*
**	radiance.c
*/

void			radiance(t_scene *scene, t_ray *ray, t_render *render);

/*
**	ray.c
*/

void			init_ray(t_vec o, t_vec d, t_ray *dest);
void			prepare_ray(t_render *render, t_radiance *target,
				t_scene *scene);
void			eval(t_ray *r, double distance, t_vec *dest);

/*
**	reflect.c
*/

void			reflect(t_ray *ray, t_render *render, t_obj *shape);
t_vec			*specular_reflect(t_vec *d, t_vec *n);
void			diffuse_reflect(t_vec *d, t_vec *n, unsigned short xseed[3]);
void			refractive_reflect(t_ray *ray, unsigned short xseed[3],
				t_obj *obj);

/*
**	rtv1.c
*/

void			*pathtracer(void*var);
void			sampling(t_rtv1 *rtv1, t_render *render);
void			screen(t_render *render, t_rtv1 *rtv1);
int				error(char *strerror);
void			init_session(t_rtv1 *rtv1, int ac, char **av);

/*
**	srand48.c
*/

void			init_seed(t_render *rt);
int				russian_roulette(t_ray *ray, t_obj *shape, t_render *render);

/*
**	texture.c
*/

void			texture(t_ray *ray, t_obj *shape);
int				load_texture(t_rtv1 *rtv1, t_obj *obj);
t_vec			texture_coord(double u, double v, t_texture *texture,
				int index);
void			color_from_texture(t_vec *sample, t_texture *texture,
				t_vec *dest);

/*
**	uv.c
*/

void			uv(t_ray *ray, t_obj *obj, double *u, double *v);
void			uv_sphere(double *u, double *v, t_ray *ray);
void			uv_plane(double *u, double *v, t_ray *ray);
void			uv_cylinder(double *u, double *v, t_ray *ray, t_obj *obj);

/*
**	FILE
*/

/*
**	file_error.c
*/

void			throw_error_file(int errorcode, char **data,
				t_scene *scene, int d_allocated);
void			throw_error(int errorcode);
void			clean_opt(char **opt);

/*
**	file.c
*/

int				file(int ac, char **av, char **file);
int				check(int ac, char **av);

/*
**	parse.c
*/

int				parse(char *str, t_scene *scene);

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
int				set_depth(t_obj *obj, char *value);
int				set_camera_matrix(t_scene *scene);
int				set_fov(t_obj *obj, char *value);
int				set_ambient(t_obj *obj, char *value);
int				set_rotation(t_obj *obj, char *value);
int				set_texture(t_obj *obj, char *value);
int				set_texture_scale(t_obj *obj, char *value);
int				set_index(t_obj *obj, char *value);
int				set_map(t_obj *obj, char *value);

/*
**	GRAPHIC
*/

/*
**	button.c
*/

int				init_button(t_rtv1 *rtv1, int error);
int				load_button(t_rtv1 *rtv1, t_button *button, char *name);
void			*load(t_rtv1 *rtv1, char *pathname, char *attr);

/*
**	event.c
*/

void			hook(t_rtv1 *rtv1);
int				exit_hook(int keycode, t_rtv1 *rtv1);
int				is_hover(int x, int y, t_button *button, int xmin, int xmax,
				int ymin, int ymax);

/*
**	gui.c
*/

int				init_sprite(t_rtv1 *rtv1);
void			put_setup(t_rtv1 *rtv1);
void			toggle_button(t_rtv1 *rtv1, t_button *button, BOOL status);
void			put_sprite(t_rtv1 *rtv1, void*image, int window);

/*
**	hover.c
*/

int				hover(int x, int y, t_rtv1 *rtv1);
int				hover_setting(int x, int y, t_rtv1 *rtv1);

/*
**	image.c
*/

int				image(t_rtv1 *rtv1);
int				init_image(t_rtv1 *rtv1);
int				write_ppm(t_rtv1 *rtv1);

/*
**	key.c
*/

int				key(int keycode, t_rtv1 *rtv1);

/*
**	mouse.c
*/

int				mouse(int button, int x, int y, t_rtv1 *rtv1);

/*
**	pixel.c
*/

void			put_pixel_vector(t_rtv1 *rtv1, int x, int y, t_vec *v);
t_vec			get_pixel_vector(t_texture *texture, int x, int y);

/*
**	render.c
*/

int				render(t_rtv1 *rtv1);
int				multithread(t_rtv1 *rtv1);

/*
**	setting.c
*/

void			put_setting(t_rtv1 *rtv1);
void			create_setting(t_rtv1 *rtv1);
int				mouse_setting(int button, int x, int y, t_rtv1 *rtv1);

/*
**	window.c
*/

int				init_window(t_rtv1 *rtv1);
t_win			window(void*mlx_ptr, int width, int height, char *name);

/*
**	MATH
*/

/*
**	calcul.c
*/

double			len(t_vec *v);
double			dot(t_vec *v1, t_vec *v2);
double			max(t_vec *v);
double			check_point(t_vec *k, t_vec *direction, t_vec *origin,\
				t_obj *obj);

/*
**	clamp.c
*/

double			clamp(double x, double low, double high);
void			clamp3(t_vec *v, double low, double high, t_vec *dest);

/*
**	convert.c
*/

t_vec			hex_to_vec(int hex);
t_vec			hex_to_light(int hex);
double			deg_to_rad(double degree);
double			rad_to_deg(double radian);
int				hex_to_dec(char *hex);
uint8_t			to_byte(double x, double gamma);

/*
**	distance.c
*/

double			define_tmin(t_vec t);
double			define_ttmin(double t1, double t2);

/*
**	normal.c
*/

void			normal(t_ray *ray, t_obj *shape);
void			sphere_normal(t_obj *sphere, t_ray *ray);
void			plane_normal(t_obj *plane, t_ray *ray);
void			cylinder_normal(t_obj *cylinder, t_ray *ray);
void			cone_normal(t_obj *cone, t_ray *ray);

/*
**	quadratic.c
*/

double			quadratic(double k1, double k2, double k3);
void			quadratic_base(t_vec k, t_vec *t);

/*
**	reflectance.c
*/

double			reflectance(double n1, double n2);
double			schlick_reflectance(double n1, double n2, double c);

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
**	OBJECT-MANAGER
*/

/*
**	object.c
*/

int				prepare_obj(t_rtv1 *rtv1);

/*
**	scene.c
*/

int				init_scene(t_rtv1 *rtv1, char *file);
options_func	*setup_obj_setter(int nb_options);

/*
**	TOOLS
*/

/*
**	debbug.c
*/

void			loading_text(int height, int y);
char			*stamp(void);
void			timer(int time);
void			print_obj(t_obj *obj);
void			printr(t_ray *r);
void			printv(t_vec *v);
int				close_rcross(t_win *win);

/*
**	free.c
*/

void			free_scene(t_scene *scene);
void			free_obj(t_obj *obj);
void			free_texture(t_scene *scene);
void			clean_exit(t_rtv1 *rtv1);

#endif
