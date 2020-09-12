/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflectance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:35:44 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 16:39:28 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
