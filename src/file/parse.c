/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/07 21:14:12 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		in_type_array(char *s, char **t)
{
	int		i;

	i = -1;
	if (s && t && *t)
		while (t[++i])
			if (ft_strcmp((s + 1), t[i]) == 0)
				return (i);
	return (-1);
}

int 	set_obj(char *opt, char *data, t_obj *obj, t_scene *scene)
{
	int		setter;

	setter = 0;
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

int 	extract_obj_data(char *start, char *end, t_scene *scene, int j)
{
	char	*str;
	char	**data;
	char	**opt;
	int		i;

	i = -1;
	str = ft_strnew((end - start) - 2);
	if (!str)
	{
		throw_error_file(EXTRACT_DATA_FAILED, NULL, scene, -1);
		return (EXIT_FAILURE);
	}
	ft_memmove(str, start + 1, (end - start - 2));
	data = ft_strsplit(str, '\n');
	free(str);
	while (data[++i])
	{
		opt = ft_strsplit(data[i], ':');
		if (set_obj(opt[0], opt[1], &scene->obj[j], scene) == EXIT_FAILURE)
		{
			clean_opt(opt);
			throw_error_file(SET_OBJECT_FAILED, data, scene, i);
			return (-1);
		}
		clean_opt(opt);
		free(data[i]);
	}
	free(data);
	return (0);
}

int 	setup_obj(char *start, char *end, t_scene *scene)
{
	char	*sub;
	int		j;

	j = 0;
	while (start < end)
	{
		sub = ft_strstr(start, "},\n{");
		if (sub == NULL)
		{
			sub = ft_strstr(start, "};");
			if (sub == NULL)
			{
				throw_error_file(OBJECT_BAD_FORMAT, NULL, NULL, -1);
				return (-1);
			}
			else
			{
 				if (extract_obj_data(start, sub, scene, j) == -1)
					return (-1);
			}
		}
		else
			if (extract_obj_data(start, sub, scene, j) == -1)
				return (-1);
		start = sub + 3;
		j = j + 1;
 	}
	return (0);
}

int 	init_obj_tab(char *str, t_scene *scene)
{
	char	*start;
	char	*end;
	int		i;

	if (str == NULL || scene == NULL)
	{
		throw_error_file(INIT_OBJ_BAD_ARGS, NULL, NULL, -1);
		return (EXIT_FAILURE);
	}
	i = 1;
	start = str;
	while ((end = ft_strstr(start, "},\n{")) != NULL)
	{
		i = i + 1;
		start = end + 4;
	}
	scene->obj = (t_obj*)ft_memalloc(sizeof(t_obj) * i);
	if (!scene->obj)
	{
		free(str);
	 	throw_error_file(INIT_SCENE_OBJ_FAILED, NULL, NULL, -1);
		return (EXIT_FAILURE);
	}
	scene->n = i;
	return (EXIT_SUCCESS);
}

int 	parse(char *str, t_scene *scene)
{
	size_t		i;
	char		*start;
	char		*end;

	i = 0;
	if (init_obj_tab(str, scene) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (*(str + i) != ':')
		i = i + 1;
	if (ft_strncmp(str, "OBJECT:", i) == 0)
	{
		if (*(str + i + 2) == '{')
		{
			start = str + i + 2;
			if ((end = ft_strstr(start, "};")) == NULL)
			{
				free(str);
				throw_error_file(OBJECT_SETTINGS_NOT_FOUND_FILE, NULL, NULL, -1);
				return (EXIT_FAILURE);
			}
			else
			{
				end = end + 1;
				if (setup_obj(start, end, scene) == -1)
				{
					free(str);
					throw_error_file(SETUP_OBJ_FAILED, NULL, NULL, -1);
					return (EXIT_FAILURE);
				}
			}
		}
		else
		{
			free(str);
			throw_error_file(OBJECT_SETTINGS_NOT_FOUND_FILE, NULL, NULL, -1);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		free(str);
		throw_error_file(OBJECT_SETTINGS_NOT_FOUND_FILE, NULL, NULL, -1);
		return (EXIT_FAILURE);
	}
	free(str);
	return (EXIT_SUCCESS);
}
