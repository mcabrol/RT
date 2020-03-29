/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/09 15:05:59 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(const char *s)
{
	double	res;
	double	fact;
	int		d;
	int		point_seen;

	res = 0.0;
	fact = (*s == '-') ? -1.0 : 1.0;
	s += (fact < 0) ? 1 : 0;
	point_seen = 0;
	while (*s)
	{
		if (*s == '.' || *s == ',')
			point_seen = 1;
		else
		{
			d = *s - '0';
			if (d >= 0 && d <= 9)
			{
				fact /= (point_seen) ? 10.0f : 1;
				res = res * 10.0f + (double)d;
			}
		}
		s++;
	}
	return (res * fact);
}
