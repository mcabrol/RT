/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/03/01 11:56:37 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ft_atod(const char *s)
{
	double	rez;
	double	fact;
	int		d;
	int		point_seen;

	rez = 0.0;
	fact = (*s == '-') ? -1.0 : 1.0;
	s += (fact < 0) ? 1 : 0;
	point_seen = 0;
	while (*s)
	{
		if (*s == '.')
			point_seen = 1;
		else
		{
			d = *s - '0';
			if (d >= 0 && d <= 9)
			{
				fact /= (point_seen) ? 10.0f : 1;
				rez = rez * 10.0f + (double)d;
			}
		}
		s++;
	}
	return (rez * fact);
}

int hexadecimalToDecimal(char *hexVal)
{
    int len = strlen(hexVal);

    // Initializing base value to 1, i.e 16^0
    int base = 1;

    int dec_val = 0;

    // Extracting characters as digits from last character
    for (int i=len-1; i>=0; i--)
    {
        // if character lies in '0'-'9', converting
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;

            // incrementing base by power
            base = base * 16;
        }

        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;

            // incrementing base by power
            base = base*16;
        }
    }
    return (dec_val);
}


int	in_type_array(char *s, char **t)
{
	int		i;

	i = 0;
	while (t[i])
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

	if (ft_strcmp(opt, "\tTYPE") == 0)
	{
		obj->type = in_type_array(data, scene->obj_type);
		if (obj->type == -1)
			ft_printf("ERROR: bad object type\n");
	}
	else if (ft_strcmp(opt, "\tRADIUS") == 0)
		obj->height = ft_atoi(data);
	else if ((setter = in_type_array(opt, scene->obj_options)) != -1)
		scene->obj_setter[setter](obj, data);
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
	i = 0;
	while (i < scene->n)
	{
		ft_printf("obj[%d] :\n", i);
		print_obj(&scene->obj[i]);
		ft_printf("\n\n");
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
