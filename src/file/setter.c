/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/03/07 15:34:33 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
double		ft_atod(const char *s);
int			value_is_vector(const char *str)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (*(str + i))
	{
		if (!ft_isdigit(*(str + i)))
		{
			if (*(str + i) != '.' && *(str + i) != ',' && *(str + i) != ' ' && *(str + i) != '-')
				return (-1);
		}
		if (*(str + i) == ' ')
			space = space + 1;
		i = i + 1;
	}
	if (space != 3)
		return (-2);
	return (0);
}

int			value_is_double(const char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (!ft_isdigit(*(str + i)))
		{
			if (*(str + i) != '.' && *(str + i) != ',' && *(str + i) != '-')
				return (-1);
		}
		i = i + 1;
	}
	return (0);
}

int	set_position(t_obj *obj, char *value)
{
	char	**data;
	int		i;

	if (value_is_vector(value) != 0)
	{
		throw_error_file(VECTOR_BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	data = ft_strsplit(value, ' ');
	if (!data)
		return (-1);
	vec(ft_atod(data[0]), ft_atod(data[1]), ft_atod(data[2]), &obj->position);
	i = 0;
	while (data[i])
	{
		free(data[i]);
		i = i + 1;
	}
	free(data);
	return (0);
}

int	set_direction(t_obj *obj, char *value)
{
	char	**data;
	int		i;

	if (value_is_vector(value) != 0)
	{
		throw_error_file(VECTOR_BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	data = ft_strsplit(value, ' ');
	if (!data)
		return (-1);
	vec(ft_atod(data[0]), ft_atod(data[1]), ft_atod(data[2]), &obj->direction);
	i = 0;
	while (data[i])
	{
		free(data[i]);
		i = i + 1;
	}
	free(data);
	return (0);
}

int	set_emission(t_obj *obj, char *value)
{
	int		color;

	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	color = hexadecimalToDecimal(&value[1]);
	obj->emission = to_vec_(color);
	return (0);
}

int	set_color(t_obj *obj, char *value)
{
	int		color;

	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	color = hexadecimalToDecimal(&value[1]);
	obj->color = to_vec(color);
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
	else if (ft_strcmp(value, " DIFFUSE") == 0)
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
	obj->angle = ft_atod(value);
	return (0);
}

int	set_height(t_obj *obj, char *value)
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

int	set_width(t_obj *obj, char *value)
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

int set_depth(t_obj *obj, char *value)
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
