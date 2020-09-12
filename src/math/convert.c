/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/12 17:04:42 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec		hex_to_vec(int hex)
{
	int		r;
	int		g;
	int		b;
	t_vec	color;

	r = (hex >> 16) & 0xFF;
	g = (hex >> 8) & 0xFF;
	b = hex & 0xFF;
	vec((double)r / 255, (double)g / 255, (double)b / 255, &color);
	return (color);
}

t_vec		hex_to_light(int hex)
{
	int		r;
	int		g;
	int		b;
	t_vec	color;

	r = (hex >> 16) & 0xFF;
	g = (hex >> 8) & 0xFF;
	b = hex & 0xFF;
	vec((double)r / 100, (double)g / 100, (double)b / 100, &color);
	return (color);
}

double		deg_to_rad(double degree)
{
	return (degree * M_PI / 180.0);
}

double		rad_to_deg(double radian)
{
	return (radian * 180.0 / M_PI);
}

int			hex_to_dec(char *hex)
{
	int		len;
	int		base;
	int		dec_val;
	int		i;

	base = 1;
	dec_val = 0;
	len = ft_strlen(hex);
	i = len - 1;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			dec_val += (hex[i] - 48) * base;
			base = base * 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			dec_val += (hex[i] - 55) * base;
			base = base * 16;
		}
		i = i - 1;
	}
	return (dec_val);
}

uint8_t		to_byte(double x, double gamma)
{
	return ((uint8_t)clamp(255.0 * pow(x, 1.0 / gamma), 0.0, 255.0));
}
