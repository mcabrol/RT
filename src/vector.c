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

t_vec		vec(double a, double b, double c)
{
	t_vec vector;

	vector.x = a;
	vector.y = b;
	vector.z = c;
	return (vector);
}

t_vec 		norm(t_vec vec)
{
	t_vec norm;

	norm.x *= (1 / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
	norm.y *= (1 / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
	norm.z *= (1 / sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
	return (norm);
}
