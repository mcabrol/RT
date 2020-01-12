/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/10 22:49:10 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_scene scene;

	scene = init_scene();
	// loop(&scene);
	// ft_dprintf(2, "ac> %d\n", ac);
	// ft_dprintf(2, "av[1]> %s\n", av[1]);
	return (0);
}

void 	loop(t_scene *scene)
{
	t_vec			c[WIDTH * HEIGHT];
	double			r1;
	double			r2;
	t_vec			d;
	t_vec			r;
	double			dx;
	double 			dy;
	unsigned short	x;
	unsigned short	p[3];
	int				i;
	int				y;
	int				s;
	int				sy;
	int				sx;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		p[0] = 0;
		p[1] = 0;
		p[2] = y * y * y;
		while (x < WIDTH)
		{
			sy = 0;
			i = (HEIGHT - y - 1) * WIDTH + x;
			while (sy < 2)
			{
				sx = 0;
				while (sx < 2)
				{
					s = 0;
					r = vec(ZERO);
					while (s < scene->samples)
					{
						r1 = 2 * erand48(p);
						r2 = 2 * erand48(p);
						dx = r1 < 1 ? sqrt(r1) - 1 : 1 - sqrt(2 - r1);
						dy = r2 < 1 ? sqrt(r2) - 1 : 1 - sqrt(2 - r2);
						// d = cx * (((sx + .5 + dx) / 2 + x) / w - .5) +
						// 	cy * (((sy + .5)))
						// r = r + radiance();
						 d = vec(ZERO);
						 r = vec(ZERO);
						s++;
					}
					c[i] = add(multn(vec(clamp(r.x), clamp(r.y), clamp(r.z)), .25), c[i]);
					sx++;
				}
				sy++;
			}
			x++;
		}
		y++;
	}
}
