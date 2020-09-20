/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 11:06:26 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	set_color(t_obj *obj, char *value)
{
	int		color;

	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	color = hex_to_dec(&value[1]);
	obj->color = hex_to_vec(color);
	return (0);
}

int	set_ambient(t_obj *obj, char *value)
{
	int		color;

	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	color = hex_to_dec(&value[1]);
	obj->ambient = hex_to_vec(color);
	return (0);
}

int	set_reflection(t_obj *obj, char *value)
{
	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	if (ft_strcmp(value, " SPECULAR") == 0)
		obj->reflect = SPEC;
	else if (ft_strcmp(value, " REFRACTION") == 0)
		obj->reflect = REFR;
	else
		obj->reflect = DIFF;
	return (0);
}

int	set_radius(t_obj *obj, char *value)
{
	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	if (value_is_double(&value[1]) != 0)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	obj->radius = ft_atod(value);
	return (0);
}

int	set_angle(t_obj *obj, char *value)
{
	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	if (value_is_double(&value[1]) != 0)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	obj->angle = deg_to_rad(ft_atod(value));
	return (0);
}
