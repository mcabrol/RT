/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adefonta <adefonta@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:14:14 by adefonta          #+#    #+#             */
/*   Updated: 2019/11/05 10:12:46 by adefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "macro.h"

int		quadratic(double var[3], double t[2])
{
	double	delta;

	delta = var[1] * var[1] - 4 * var[0] * var[2];
	if (delta < 0.0)
		return (FALSE);
	delta = sqrtf(delta);
	t[0] = (-var[1] - delta) / (2 * var[0]);
	t[1] = (-var[1] + delta) / (2 * var[0]);
	if (t[0] < 0 && t[1] < 0)
		return (FALSE);
	if (t[0] > t[1] && t[1] > 0)
	{
		delta = t[1];
		t[1] = t[0];
		t[0] = delta;
	}
	return ((delta == t[0]) ? TRUE : 2);
}
