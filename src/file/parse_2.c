/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 12:00:42 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				set_obj(char *opt, char *data, t_obj *obj, t_scene *scene)
{
	int		setter;

	if (ft_strcmp(opt, "\tTYPE") == 0)
	{
		obj->type = in_type_array(data, scene->obj_type);
		obj->texture.scale = 1.0;
		if (obj->type == CONE || obj->type == CYLINDER || obj->type == PLANE)
			set_direction(obj, " 0 -1 0");
		if (obj->type == -1)
		{
			throw_error(BAD_TYPE_OBJECT);
			return (EXIT_FAILURE);
		}
	}
	else if ((setter = in_type_array(opt, scene->obj_options)) != -1)
	{
		if (scene->obj_setter[setter](obj, data) == -1)
			return (EXIT_FAILURE);
	}
	else
	{
		throw_error(BAD_OPTIONS);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static char		**setup_str(char *start, char *end, t_scene *scene)
{
	char	*str;
	char	**data;

	if (!(str = ft_strnew((end - start) - 2)))
	{
		throw_error_file(EXTRACT_DATA_FAILED, NULL, scene, -1);
		return (NULL);
	}
	ft_memmove(str, start + 1, (end - start - 2));
	data = ft_strsplit(str, '\n');
	free(str);
	return (data);
}

int				extract_obj_data(char *start, char *end, t_scene *scene, int j)
{
	char	**data;
	char	**opt;
	int		i;

	i = -1;
	if ((data = setup_str(start, end, scene)) == NULL)
		return (EXIT_FAILURE);
	while (data[++i])
	{
		opt = ft_strsplit(data[i], ':');
		if (set_obj(opt[0], opt[1], &scene->obj[j], scene) == EXIT_FAILURE)
		{
			ft_tabdel(opt);
			throw_error_file(SET_OBJECT_FAILED, data, scene, i);
			return (-1);
		}
		ft_tabdel(opt);
		free(data[i]);
	}
	free(data);
	return (0);
}

static int		inner_setup_obj(char **start, t_scene *scene, int *j)
{
	char	*sub;

	sub = NULL;
	if ((sub = ft_strstr(*start, "},\n{")) == NULL)
	{
		if ((sub = ft_strstr(*start, "};")) == NULL)
		{
			throw_error_file(OBJECT_BAD_FORMAT, NULL, NULL, -1);
			return (-1);
		}
		else
		{
			if (extract_obj_data(*start, sub, scene, *j) == -1)
				return (-1);
		}
	}
	else
	{
		if (extract_obj_data(*start, sub, scene, *j) == -1)
			return (-1);
	}
	*start = sub + 3;
	*j = *j + 1;
	return (0);
}

int				setup_obj(char *start, char *end, t_scene *scene)
{
	int		j;

	j = 0;
	while (start < end)
	{
		if (inner_setup_obj(&start, scene, &j) == -1)
			return (-1);
	}
	return (0);
}
