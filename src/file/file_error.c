/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judrion <judrion@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:47:42 by judrion           #+#    #+#             */
/*   Updated: 2020/03/02 11:16:57 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		throw_error_file(int errorcode, char **data,
	t_obj *obj, int d_allocated)
{
	int		i;

	throw_error(errorcode);
	if (d_allocated != -1)
	{
		i = 0;
		while (i < d_allocated)
		{
			free(data[i]);
			i = i + 1;
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
	// else if (errorcode == )
	// 	ft_printf("ERROR #%.4d - .\n", errorcode);
	// else if (errorcode == )
	// 	ft_printf("ERROR #%.4d - .\n", errorcode);
}
