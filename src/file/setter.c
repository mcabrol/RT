/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/03/02 14:54:16 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
double		ft_atod(const char *s);

int	set_position(t_obj *obj, char *value)
{
	char	**data;
	int		i;

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
	char	**data;
	int		i;

	data = ft_strsplit(value, ' ');
	if (!data)
		return (-1);
	vec(ft_atod(data[0]), ft_atod(data[1]), ft_atod(data[2]), &obj->emission);
	i = 0;
	while (data[i])
	{
		free(data[i]);
		i = i + 1;
	}
	free(data);
	return (0);
}

int	set_color(t_obj *obj, char *value)
{
	int		color;

	color = hexadecimalToDecimal(&value[1]);
	obj->color = to_vec(color);
	return (0);
}

int	set_reflection(t_obj *obj, char *value)
{
	if (ft_strcmp(value, " SPECULAR") == 0)
		obj->reflect = SPEC;
	else if (ft_strcmp(value, " DIFFUSE") == 0)
		obj->reflect = DIFF;
	return (0);
}

int	set_radius(t_obj *obj, char *value)
{
	obj->radius = ft_atod(value);
	return (0);
}

int	set_angle(t_obj *obj, char *value)
{
	obj->angle = ft_atod(value);
	return (0);
}

int	set_height(t_obj *obj, char *value)
{
	obj->height = ft_atod(value);
	return (0);
}

int	set_width(t_obj *obj, char *value)
{
	obj->width = ft_atod(value);
	return (0);
}

int set_depth(t_obj *obj, char *value)
{
	obj->depth = ft_atod(value);
	return (0);
}
