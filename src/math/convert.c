/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 16:25:28 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		deg_to_rad(double degree)
{
	return (degree * M_PI / 180.0);
}

double		rad_to_deg(double radian)
{
	return (radian * 180.0 / M_PI);
}

uint8_t		to_byte(double x, double gamma)
{
	return ((uint8_t)clamp(255.0 * pow(x, 1.0 / gamma), 0.0, 255.0));
}
