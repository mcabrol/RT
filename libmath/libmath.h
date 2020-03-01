/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmath.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:54:08 by judrion           #+#    #+#             */
/*   Updated: 2020/01/29 19:22:23 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H

# define X_AXE 0
# define Y_AXE 1
# define Z_AXE 2

# define WOLFRAM 1
# define TERM 2

# define FILL 0
# define NO_FILL 1

# include <stdio.h>
# include <math.h>

typedef struct		s_matrix
{
	double			data[4][4];
}					t_matrix;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vec;

void 		operator_addv(t_vec *src_1, t_vec *src_2, t_vec *dest);
void 		operator_subv(t_vec *src_1, t_vec *src_2, t_vec *dest);
void 		operator_mult(t_vec *src_1, double determinant, t_vec *dest);
void 		operator_multv(t_vec *src_1, t_vec *src_2, t_vec *dest);
void 		operator_div(t_vec *src_1, double determinant, t_vec *dest);
double		operator_distance(t_vec *p1, t_vec *p2);

void 		matrix_create(t_matrix *m, int fill);
void 		matrix_scaling(t_matrix *m, t_vec *scaling);
void 		matrix_identity(t_matrix *m);
void 		matrix_rotate(t_matrix *m, double angle, int axe);
void 		matrix_mult(t_matrix *a, t_matrix *b, t_matrix *dest);
void 		matrix_transpose(t_matrix *a, t_matrix *dst);
void 		matrix_translate(t_matrix *a, t_vec *translate);
void 		matrix_print(t_matrix *m, int format);

void 		point_matrix_scaling(t_vec *p, t_matrix *m, t_vec *dst);
void 		point_matrix_rotate(t_vec *p, t_matrix *m, t_vec *dst);
void 		point_matrix_mult(t_vec *p, t_matrix *m, t_vec *dst);
void 		point_translate(t_vec *p, t_matrix *m, t_vec *dst);

void		vector_init(t_vec *vec, double x, double y, double z);
void		vector_initv(t_vec *dest, t_vec *src);
void		vector_normalize(t_vec *src, t_vec *dst);
double		vector_dotproduct(t_vec *a, t_vec *b);
void		vector_crossprod(t_vec *a, t_vec *b, t_vec *dest);
double		vector_length(t_vec *a);

void 		vector_print(t_vec *a, int format);
void 		matrix_print(t_matrix *m, int format);


void 		vector_matrix_mult(t_vec *src, t_matrix *m, t_vec *dst);

#endif
