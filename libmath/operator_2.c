/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:14:35 by judrion           #+#    #+#             */
/*   Updated: 2020/01/21 13:37:52 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

double		operator_distance(t_vec *p1, t_vec *p2)
{
	t_vec	p_tmp;
	double	dist;

	operator_subv(p1, p2, &p_tmp);
	dist = vector_dotproduct(&p_tmp, &p_tmp);
	return (sqrtf(dist));
}
