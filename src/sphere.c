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

t_sphere	sphere(double radius, t_vec position, t_vec emission, t_vec color, e_reflect reflect)
{
	t_sphere sphere;

	sphere.radius = radius;
	sphere.position = position;
	sphere.emission = emission;
	sphere.color = color;
	sphere.reflect = reflect;
	return (sphere);
}
