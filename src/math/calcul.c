/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:55:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 19:02:06 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double		ndot(t_vec *v1, double n)
{
	return (v1->x * n + v1->y * n + v1->z * n);
}

double		max(t_vec *v)
{
	if (v->x > v->y && v->x > v->z)
		return (v->x);
	else
		if (v->y > v->z)
			return (v->y);
		else
			return (v->z);
}

double		clamp(double x, double low, double high)
{
	if (x < high)
		if (x > low)
			return (x);
		else
			return (low);
	else
		return (high);
}

void		clamp3(t_vec *v, double low, double high, t_vec *dest)
{
	vec(clamp(v->x, low, high),
		clamp(v->y, low, high),
		clamp(v->z, low, high),
		dest);
}

uint8_t		to_byte(double x, double gamma)
{
	return ((uint8_t)clamp(255.0 * pow(x, 1.0 / gamma), 0.0, 255.0));
}

double		to_vec(int x, double gamma)
{
	return (pow((double)x, 1.0 / gamma) / 255.0);
}

double		reflectance(double n1, double n2)
{
	double sqrt_r;

	sqrt_r = (n1 - n2) / (n1 + n2);
	return (sqrt_r * sqrt_r);
}

double		schlick_reflectance(double n1, double n2, double c)
{
	double ro;
	ro = reflectance(n1, n2);
	return (ro + (1 - ro) * c * c * c * c * c);
}
