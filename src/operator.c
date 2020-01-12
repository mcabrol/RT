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

t_vec		add(t_vec v1, t_vec v2)
{
	return (vec(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vec		sub(t_vec v1, t_vec v2)
{
	return (vec(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec		mult(t_vec v1, t_vec v2)
{
	return (vec(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z));
}

t_vec		multn(t_vec v1, double n)
{
	return (vec(v1.x * n, v1.y * n, v1.z * n));
}

t_vec		divn(t_vec v1, double n)
{
	return (vec(v1.x / n, v1.y / n, v1.z / n));
}
