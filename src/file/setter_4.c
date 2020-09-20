/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 09:38:01 by judrion           #+#    #+#             */
/*   Updated: 2020/09/20 11:50:54 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		set_index(t_obj *obj, char *value)
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

int		set_texture(t_obj *obj, char *value)
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

int		set_texture_scale(t_obj *obj, char *value)
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

int		set_map(t_obj *obj, char *value)
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
