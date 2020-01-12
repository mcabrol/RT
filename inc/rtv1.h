/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:42:53 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 23:22:40 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define HEIGHT	100
# define WIDTH	100
# define ZERO	0.0, 0.0, 0.0

typedef enum 		s_reflect	// material types, used in radiance()
{
	DIFF,
	SPEC,
	REFR
}					e_reflect;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_ray
{
	t_vec			o; 			// Origin
	t_vec			d; 			// Direction
}					t_ray;

typedef struct		s_sphere
{
	double			radius;
	t_vec			position;
	t_vec			emission;
	t_vec			color;
	e_reflect		reflect;
}					t_sphere;

typedef struct 		s_scene
{
	int				samples;
	t_ray			camera;
	t_vec			cx;
	t_vec			cy;
}					t_scene;

typedef struct		s_point
{

	int				x;
	int				y;
}					t_point;

/*
**	rtv1.c
*/

void 				loop(t_scene *scene);

/*
**	vector.c
*/

t_vec				vec(double a, double b, double c);
t_vec 				norm(t_vec vec);

/*
**	ray.c
*/

t_ray				ray(t_vec i, t_vec j);

/*
**	sphere.c
*/

t_sphere			sphere(double radius, t_vec position, t_vec emission,
					t_vec color, e_reflect reflect);

/*
**	scene.c
*/

t_scene				init_scene(void);

/*
**	intersect.c
*/

int				 	intersect(const t_ray *r, double *t, int *id);

/*
**	operator.c
*/

t_vec				add(t_vec v1, t_vec v2);
t_vec				sub(t_vec v1, t_vec v2);
t_vec				mult(t_vec v1, t_vec v2);
t_vec				multn(t_vec v1, double n);
t_vec				divn(t_vec v1, double n);

/*
**	calcul.c
*/

double				clamp(double x);

#endif
