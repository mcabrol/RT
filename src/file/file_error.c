/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:47:42 by judrion           #+#    #+#             */
/*   Updated: 2020/03/02 11:41:11 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		throw_error_file(int errorcode, char **data,
	t_obj *obj, int d_allocated)
{
	throw_error(errorcode);
	if (d_allocated != -1)
	{
		while (data[d_allocated])
		{
			free(data[d_allocated]);
			d_allocated = d_allocated + 1;
		}
		free(data);
	}
	if (obj)
		free(obj);
	exit(errorcode);
}

void throw_error(int errorcode)
{
	if (errorcode == CAMERA_SETTINGS_NOT_FOUND_FILE)
		ft_printf("ERROR #%.4d - can't find camera settings.\n", errorcode);
	else if (errorcode == OBJECT_SETTINGS_NOT_FOUND_FILE)
		ft_printf("ERROR #%.4d - can't find object settings.\n", errorcode);
	else if (errorcode == INIT_SCENE_OBJ_FAILED)
		ft_printf("ERROR #%.4d - can't allocate memory for objects.\n", errorcode);
	else if (errorcode == INIT_OBJ_BAD_ARGS)
		ft_printf("ERROR #%.4d - bad arguments.\n", errorcode);
	else if (errorcode == OBJECT_BAD_FORMAT)
		ft_printf("ERROR #%.4d - bad objects format.\n", errorcode);
	else if (errorcode == EXTRACT_DATA_FAILED)
		ft_printf("ERROR #%.4d - can't extract subpart of data.\n", errorcode);
	else if (errorcode == BAD_TYPE_OBJECT)
		ft_printf("ERROR #%.4d - unknown object type.\n", errorcode);
	else if (errorcode == SET_OBJECT_FAILED)
		ft_printf("ERROR #%.4d - can't set objects.\n", errorcode);
	else if (errorcode == BAD_OPTIONS)
		ft_printf("ERROR #%.4d - options not found.\n", errorcode);
	// else if (errorcode == )
	// 	ft_printf("ERROR #%.4d - .\n", errorcode);
}

void clean_opt(char **opt)
{
	int	i;

	i = 0;
	while (opt[i])
	{
		free(opt[i]);
		i = i + 1;
	}
	free(opt);
}
