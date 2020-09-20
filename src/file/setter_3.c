/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 11:50:39 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		set_height(t_obj *obj, char *value)
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
	obj->height = ft_atod(value);
	return (0);
}

int		set_width(t_obj *obj, char *value)
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
	obj->width = ft_atod(value);
	return (0);
}

int		set_depth(t_obj *obj, char *value)
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
	obj->depth = ft_atod(value);
	return (0);
}

int		set_fov(t_obj *obj, char *value)
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
	obj->fov = ft_atoi(value);
	return (0);
}

int		set_rotation(t_obj *obj, char *value)
{
	char	**data;

	if (value_is_vector(value) != 0)
	{
		throw_error_file(VECTOR_BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	data = ft_strsplit(value, ' ');
	if (!data)
		return (-1);
	vec(ft_atod(data[0]), ft_atod(data[1]), ft_atod(data[2]), &obj->rotation);
	ft_tabdel(data);
	return (0);
}
