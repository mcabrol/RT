/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		cosine_weighted_sample(double u1, double u2)
{
	double cos_theta;
	double sin_theta;
	double phi;

	cos_theta = sqrt(1.0 - u1);
	sin_theta = sqrt(u1);
	phi = 2.0 * PI * u2;
	return (vec(cos(phi) * sin_theta, sin(phi) * sin_theta, cos_theta));
}
