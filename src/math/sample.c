/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/15 09:30:48 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		cosine_weighted_sample(double u1, double u2, t_vec *dest)
{
	double cos_theta;
	double sin_theta;
	double phi;

	cos_theta = sqrt(1.0 - u1);
	sin_theta = sqrt(u1);
	phi = 2.0 * PI * u2;
	return (vec(cos(phi) * sin_theta, sin(phi) * sin_theta, cos_theta, dest));
}
