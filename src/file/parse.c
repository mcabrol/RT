/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 10:35:26 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int	in_type_array(char *s, char **t)
{
	int		i;

	i = 0;
	while (i < OBJ_TYPE)
	{
		if (ft_strcmp((s + 1), t[i]) == 0)
			return (i);
		i = i + 1;
	}
	return (-1);
}

void set_obj(char *opt, char *data, t_obj *obj, t_scene *scene)
{
	int		setter;

	// ft_printf("tested opt : -%s-\n", opt);
	if (ft_strcmp(opt, "\tTYPE") == 0)
	{
		obj->type = in_type_array(data, scene->obj_type);
		if (obj->type == -1)
			ft_printf("ERROR: bad object type\n");
	}
	else if (ft_strcmp(opt, "\tRADIUS") == 0)
	{
		obj->height = ft_atoi(data);
	}
	else if ((setter = in_type_array(opt, scene->obj_options)) != -1)
	{
		scene->obj_setter[setter](obj, data);
	}
}

void extract_obj_data(char *start, char *end, t_scene *scene, int j)
{
	char	*str;
	char	**data;
	char	**opt;
	int		i = 0;

	str = (char*)ft_memalloc(sizeof(char) * (end - start));
	if (str)
		ft_memmove(str, start, end - start);
	data = ft_strsplit(str, '\n');
	free(str);
	while (data[i])
	{
		opt = ft_strsplit(data[i], ':');
		set_obj(opt[0], opt[1], &scene->obj[j], scene);
		free(data[i]);
		i = i + 1;
	}
	free(data);
}

void setup_obj(char *start, char *end, t_scene *scene)
{
	char	*sub;
	int		i;
	int		j;

	// ft_printf("%s", start);
	j = 0;
	while (start < end)
	{
		sub = ft_strstr(start, "},\n{");
		if (sub == NULL)
		{
			sub = ft_strstr(start, "};");
			if (sub == NULL)
				ft_printf("ERROR: bad format of object description.");
			else
				extract_obj_data(start, sub, scene, j);
		}
		else
			extract_obj_data(start, sub, scene, j);
		start = sub + 5;
		j = j + 1;
 	}
	ft_printf("scene->n : %d\n", scene->n);
	i = 0;
	while (i < scene->n)
	{
		ft_printf("obj[%d] :\n", i);
		print_obj(&scene->obj[i]);
		ft_printf("\n");
		i = i + 1;
	}
}

void init_obj_tab(char *str, t_scene *scene)
{
	char	*start;
	char	*end;
	int		i;

	i = 1;
	start = str;
	while ((end = ft_strstr(start, "},\n{")) != NULL)
	{
		i = i + 1;
		start = end + 4;
	}
	scene->obj = (t_obj*)ft_memalloc(sizeof(t_obj) * i);
	scene->n = i;
}

int 	parse(char *str, t_scene *scene)
{
	size_t		i;
	char		*start;
	char		*end;

	i = 0;
	init_obj_tab(str, scene);
	scene->obj_type = ft_strsplit("SPHERE PLANE CYLINDER CONE BOX CAMERA", ' ');
	//protect le malloc
	while (*(str + i) != ':')
		i = i + 1;
	if (ft_strncmp(str, "OBJECT:", i) == 0)
	{
		if (*(str + i + 2) == '{')
		{
			start = str + i + 4;
			if ((end = ft_strstr(start, "}\nC")) == NULL
			&& (end = ft_strstr(start, "};")) == NULL)
				ft_printf("ERROR: can't find camera settings.\n");
			else
			{
				end = end + 1;
				setup_obj(start, end, scene);
				// write(1, start, end - start);
			}
		}
		else
			ft_printf("ERROR: can't find OBJECT.\n");
	}
	else if (ft_strncmp(str, "CAMERA", i) == 0)
	{
		if (*(str + i + 2) == '{')
		{
			start = str + i + 2;
			if ((end = ft_strstr(start, "}\nO")) == NULL
			&& (end = ft_strstr(start, "};")) == NULL)
				ft_printf("ERROR: can't find object settings.\n");
			else
			{
				end = end + 1;
				write(1, start, end - start);
			}
				// setup_camera(start, end, scene);
		}
		else
			ft_printf("ERROR: can't find CAMERA.\n");
	}
	else
		ft_printf("sample %d octet\n%s\n", scene->samples, str);
	return (EXIT_SUCCESS);
}
