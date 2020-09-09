/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/09 17:30:14 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
// #include "minilibx-linux/mlx_int.h"

int		key(int keycode, t_rtv1 *rtv1)
{
	printf("key #%d\n", keycode);
	if (keycode == 53)
		clean_exit(rtv1);
	return (EXIT_SUCCESS);
}
