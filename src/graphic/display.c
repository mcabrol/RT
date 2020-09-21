/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:42:08 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/21 14:45:08 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*init_win_name(int id_win, int id_render)
{
	char	*win_name;
	char	*string_id;
	char	*tmp;

	string_id = ft_itoa(id_win);
	win_name = ft_strjoin("render - win #", string_id);
	free(string_id);
	string_id = ft_itoa(id_render);
	tmp = win_name;
	win_name = ft_strjoin(win_name, " - render #");
	free(tmp);
	tmp = win_name;
	win_name = ft_strjoin(win_name, string_id);
	free(tmp);
	free(string_id);
	return (win_name);
}

t_win		*init_win_array(void)
{
	int		i;
	t_win	*image;

	image = (t_win*)ft_memalloc(sizeof(t_win) * MAX_WIN);
	i = 0;
	while (i < MAX_WIN)
	{
		image[i].available = 1;
		image[i].id_window = i;
		i = i + 1;
	}
	return (image);
}

int		display_window(t_rtv1 *rtv1)
{
	int		id;
	char	*win_name;

	id = -1;
	while (++id < MAX_WIN)
		if (rtv1->image[id].available == 1)
			break ;
	if (id != MAX_WIN)
	{
		win_name = init_win_name(id, rtv1->id_render);
		rtv1->image[id] = window(rtv1->mlx_ptr, rtv1->scene.width,
								rtv1->scene.height, win_name);
		mlx_hook(rtv1->image[id].win_ptr, 17, (1L << 17), close_rcross, \
		&rtv1->image[id]);
		rtv1->image[id].id_window = id;
		rtv1->image[id].available = 0;
		rtv1->id_win = id;
		free(win_name);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
