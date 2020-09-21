/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/09/21 19:07:00 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			value_is_vector(const char *str)
{
	char	**vector;
	int		i;

	vector = ft_strsplit(str, ' ');
	i = 0;
	while (vector[i])
	{
		free(vector[i]);
		i = i + 1;
	}
	free(vector);
	if (i != 3)
		return (-1);
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

int			set_position(t_obj *obj, char *value)
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
	vec(ft_atod(data[0]), ft_atod(data[1]), ft_atod(data[2]), &obj->position);
	ft_tabdel(data);
	return (0);
}

int			set_direction(t_obj *obj, char *value)
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
	vec(ft_atod(data[0]), ft_atod(data[1]), ft_atod(data[2]), &obj->direction);
	ft_tabdel(data);
	return (0);
}

int			set_emission(t_obj *obj, char *value)
{
	int		color;

	if (!value || value[1] != '#')
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	color = hex_to_dec(&value[1]);
	obj->emission = hex_to_light(color);
	return (0);
}
