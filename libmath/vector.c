/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:05:00 by adefonta          #+#    #+#             */
/*   Updated: 2020/01/30 18:22:08 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void		vector_init(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = 1;
}

void		vector_initv(t_vec *dest, t_vec *src)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
	dest->w = src->w;
}



//check if p_test is between p_start and p_end
//
// int			vector_areInline(t_vec *p_start, t_vec *p_end, t_vec *p_test)
// {
// 	t_vec	p_tmp1;
// 	t_vec	p_tmp2;
// 	t_vec	v_crossprod;
// 	double	data;
//
// 	data = -200000;
// 	operator_subv(p_test, p_start, &p_tmp1);
// 	operator_subv(p_end, p_start, &p_tmp2);
// 	vector_crossprod(&p_tmp1, &p_tmp2, &v_crossprod);
// 	if (v_crossprod.x <= 0.00001 && v_crossprod.y <= 0.00001 && v_crossprod.z <= 0.00001)
// 	{
// 		operator_subv(p_test, p_start, &p_tmp1);
// 		operator_subv(p_end, p_test, &p_tmp2);
// 		data = vector_scalar(&p_tmp1, &p_tmp2);
// 	}
// 	return ((data > 0) ? TRUE : FALSE);
// }
