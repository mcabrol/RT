/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/09/17 18:12:06 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			value_is_vector(const char *str)
{
	char 	**vector;
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

int	set_position(t_obj *obj, char *value)
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

int	set_direction(t_obj *obj, char *value)
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

int	set_emission(t_obj *obj, char *value)
{
	int		color;

	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	color = hex_to_dec(&value[1]);
	obj->emission = hex_to_light(color);
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

int set_fov(t_obj *obj, char *value)
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

int	set_rotation(t_obj *obj, char *value)
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

int	set_index(t_obj *obj, char *value)
{
	char	**data;

	data = ft_strsplit(value, ' ');
	if (!data)
		return (-1);
	obj->index_in = ft_atod(data[0]);
	obj->index_out = ft_atod(data[1]);
	ft_tabdel(data);
	return (0);
}

int set_texture(t_obj *obj, char *value)
{
	obj->texture.path = NULL;
	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	obj->texture.path = ft_strdup(value + 1);
	return (EXIT_SUCCESS);
}

int set_texture_scale(t_obj *obj, char *value)
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
	obj->texture.scale = ft_atod(value);
	return (EXIT_SUCCESS);
}

int set_map(t_obj *obj, char *value)
{
	obj->environment.path = NULL;
	if (!value)
	{
		throw_error_file(BAD_VALUE, NULL, NULL, -1);
		return (-1);
	}
	obj->environment.path = ft_strdup(value + 1);
	return (EXIT_SUCCESS);
}
