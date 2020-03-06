/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:59:15 by mcabrol           #+#    #+#             */
/*   Updated: 2020/02/26 15:46:12 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void 	 	loading_text(int samples, int y, int height)
{
	ft_dprintf(2, "%u samples %5.2f%%\n", samples, 100.0 * y / (height - 1));
	// ft_dprintf(2, "\r%u samples %5.2f%%", samples, 100.0 * y / (height - 1));
}
