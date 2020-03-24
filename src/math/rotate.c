/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/11 19:27:33 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	rotate_x(t_vec pt, double theta)
{
	double mat[4][4];

	mat[0][0] = 1;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = cos(theta);
	mat[2][1] = -sin(theta);
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = sin(theta);
	mat[2][2] = cos(theta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	rotate_y(t_vec pt, double theta)
{
	double mat[4][4];

	mat[0][0] = cos(theta);
	mat[1][0] = 0;
	mat[2][0] = sin(theta);
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = 1;
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = -sin(theta);
	mat[1][2] = 0;
	mat[2][2] = cos(theta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	rotate_z(t_vec pt, double theta)
{
	double mat[4][4];

	mat[0][0] = cos(theta);
	mat[1][0] = -sin(theta);
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = sin(theta);
	mat[1][1] = cos(theta);
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = 1;
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	rotate_point(double alpha, double beta, double gamma, t_vec pt)
{
	double mat[4][4];

	mat[0][0] = cos(beta) * cos(gamma);
	mat[1][0] = cos(gamma) * sin(alpha) * sin(beta) - cos(alpha) * sin(gamma);
	mat[2][0] = cos(alpha) * cos(gamma) * sin(beta) + sin(alpha) * sin(gamma);
	mat[3][0] = 0;
	mat[0][1] = cos(beta) * sin(gamma);
	mat[1][1] = cos(alpha) * cos(gamma) + sin(alpha) * sin(beta) * sin(gamma);
	mat[2][1] = -cos(gamma) * sin(alpha) + cos(alpha) * sin(beta) * sin(gamma);
	mat[3][1] = 0;
	mat[0][2] = -sin(beta);
	mat[1][2] = cos(beta) * sin(alpha);
	mat[2][2] = cos(alpha) * cos(beta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_matrix_mult(mat, pt));
}

t_vec	v_matrix_mult(double mat[4][4], t_vec pt)
{
	t_vec	out;

	out.x = (mat[0][0] * pt.x) + (mat[1][0] * pt.y) +
			(mat[2][0] * pt.z) + (mat[3][0] * 1);
	out.y = (mat[0][1] * pt.x) + (mat[1][1] * pt.y) +
			(mat[2][1] * pt.z) + (mat[3][1] * 1);
	out.z = (mat[0][2] * pt.x) + (mat[1][2] * pt.y) +
			(mat[2][2] * pt.z) + (mat[3][2] * 1);
	return (out);
}
