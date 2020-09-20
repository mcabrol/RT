/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/09/20 15:52:42 by judrion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		face_in(double *min, t_vec *rev_ov, double *t)
{
	int		facein;

	if (min[0] > min[1])
	{
		t[0] = min[0];
		facein = (rev_ov->x >= 0.0) ? 0 : 3;
	}
	else
	{
		t[0] = min[1];
		facein = (rev_ov->y >= 0.0) ? 1 : 4;
	}
	if (min[2] > t[0])
	{
		t[0] = min[2];
		facein = (rev_ov->z >= 0.0) ? 2 : 5;
	}
	return (facein);
}

int		face_out(double *max, t_vec *rev_ov, double *t)
{
	int		faceout;

	if (max[0] < max[1])
	{
		t[1] = max[0];
		faceout = (rev_ov->x >= 0.0) ? 3 : 0;
	}
	else
	{
		t[1] = max[1];
		faceout = (rev_ov->y >= 0.0) ? 4 : 1;
	}
	if (max[2] < t[1])
	{
		t[1] = max[2];
		faceout = (rev_ov->z >= 0.0) ? 5 : 2;
	}
	return (faceout);
}
