/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/22 11:54:16 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				in_type_array(char *s, char **t)
{
	int		i;

	i = -1;
	if (s && t && *t)
		while (t[++i])
			if (ft_strcmp((s + 1), t[i]) == 0)
				return (i);
	return (-1);
}

int				init_obj_tab(char *str, t_scene *scene)
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

static int		inner_parse(char *str, int i, t_scene *scene)
{
	char		*start;
	char		*end;

	if (*(str + i + 2) != '{')
		return (EXIT_FAILURE);
	start = str + i + 2;
	if ((end = ft_strstr(start, "};")) == NULL)
	{
		throw_error_file(OBJECT_STNGS_NOT_FOUND_FILE, NULL, NULL, -1);
		return (EXIT_FAILURE);
	}
	else
	{
		end = end + 1;
		if (setup_obj(start, end, scene) == -1)
		{
			throw_error_file(SETUP_OBJ_FAILED, NULL, NULL, -1);
			return (EXIT_FAILURE);
		}
	}
	return (0);
}

int				parse(char *str, t_scene *scene)
{
	size_t		i;

	i = 0;
	if (init_obj_tab(str, scene) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (*(str + i) != ':')
		i = i + 1;
	if (ft_strncmp(str, "OBJECT:", i) == 0)
	{
		if (inner_parse(str, i, scene) == EXIT_FAILURE)
		{
			free(str);
			throw_error_file(OBJECT_STNGS_NOT_FOUND_FILE, NULL, NULL, -1);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		free(str);
		throw_error_file(OBJECT_STNGS_NOT_FOUND_FILE, NULL, NULL, -1);
		return (EXIT_FAILURE);
	}
	free(str);
	return (EXIT_SUCCESS);
}
