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
// # include "../minilibx/mlx.h"
# include <math.h>
# include <stdint.h>


# define HEIGHT			100
# define WIDTH			100
# define ZERO			0.0, 0.0, 0.0
# define FALSE			0
# define TRUE			1

# define DIFF	0
# define SPEC	1
# define REFR	2

# define RAND48_SEED_0	(0x330e)
# define RAND48_SEED_1	(0xabcd)
# define RAND48_SEED_2	(0x1234)
# define RAND48_MULT_0	(0xe66d)
# define RAND48_MULT_1	(0xdeec)
# define RAND48_MULT_2	(0x0005)
# define RAND48_ADD   	(0x000b)

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

t_vec				eval(t_ray *r, double t);
void				printr(t_ray *r);

/*
**	sphere.c
*/

/*
**	scene.c
*/


/*
**	intersect.c
*/

int 				intersect(t_ray *ray, size_t *id);
int 				intersect_sphere(t_sphere *sphere, t_ray *ray);

/*
**	operator.c
*/

t_vec				sum(t_vec *v1, t_vec *v2);
t_vec				sub(t_vec *v1, t_vec *v2);
t_vec				multi(t_vec *v1, t_vec *v2);
t_vec				nmulti(t_vec *v1, double n);
t_vec				divide(t_vec *v1, t_vec *v2);
t_vec				ndivide(t_vec *v1, double n);
double				dot(t_vec *v1, t_vec *v2);
double				max(t_vec *v);
t_vec				minus(t_vec *v);
t_vec				cross(t_vec *v1, t_vec *v2);




/*
**	calcul.c
*/

double				clamp(double x, double low, double high);
uint8_t				to_byte(double x, double gamma);


#endif
