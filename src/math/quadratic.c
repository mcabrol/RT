/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:33:51 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 16:38:35 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		quadratic(double k1, double k2, double k3)
{
	double	des;
	double	t1;
	double	t2;
	double	t_min;

	t_min = T_MAX;
	if ((des = k2 * k2 - 4 * k1 * k3) >= 0)
	{
		t1 = (-k2 + sqrt(des)) / (2 * k1);
		t2 = (-k2 - sqrt(des)) / (2 * k1);
		if (t1 >= T_MIN && t1 < T_MAX && t1 < t_min)
			t_min = t1;
		if (t2 >= T_MIN && t2 < T_MAX && t2 < t_min)
			t_min = t2;
	}
	return (t_min);
}

void		quadratic_base(t_vec k, t_vec *t)
{
	double	des;

	if ((des = k.y * k.y - 4 * k.x * k.z) >= 0)
	{
		t->x = (-k.y + sqrt(des)) / (2 * k.x);
		t->y = (-k.y - sqrt(des)) / (2 * k.x);
	}
	else
	{
		t->x = T_MAX;
		t->y = T_MAX;
		t->z = T_MAX;
	}
}
