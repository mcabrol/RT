/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:53:17 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 16:53:43 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		define_tmin(t_vec t)
{
	if (t.x >= T_MIN && t.x < T_MAX && t.x < t.z)
		t.z = t.x;
	if (t.y >= T_MIN && t.y < T_MAX && t.y < t.z)
		t.z = t.y;
	return (t.z);
}

double		define_ttmin(double t1, double t2)
{
	double	t_min;

	t_min = T_MAX;
	if (t1 >= T_MIN && t1 < T_MAX && t1 < t_min)
		t_min = t1;
	if (t2 >= T_MIN && t2 < T_MAX && t2 < t_min)
		t_min = t2;
	return (t_min);
}
