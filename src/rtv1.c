/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:43:37 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/13 20:09:35 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int ac, char **av)
{
	t_win			win;

	win.ac = ac;
	win.av = av;
	window(&win);
	return (0);
}

void 		rtv1(t_win *win)
{
	t_vec			eye;
	t_vec			gaze;
	t_vec 			*ls;
	double			fov;
	int 			y;
	int 			x;
	int 			s;
	unsigned int 	sx;
	unsigned int 	sy;
	unsigned int 	i;
	unsigned short	xseed[3];
	double			u1;
	double			u2;
	t_vec			cx;
	t_vec			cy;
	double			dx;
	double			dy;
	t_vec			a;
	t_vec			b;
	t_vec			ab;
	t_vec			d;
	t_vec			d_t;
	t_vec			l;
	t_vec			m;
	t_vec			l_t;
	t_ray			ry;
	t_scene 		scene;

	scene = init_scene();
	scene.samples = (win->ac == 2) ? atoi(win->av[1]) / 4 : 1;
	eye = vec(50, 52, 295.6);
	gaze = vec(0, -0.042612, -1);
	norm(&gaze);
	fov = 0.5135;
	cx = vec(WIDTH * fov / HEIGHT, 0.0, 0.0);
	cy = cross(&cx, &gaze);
	norm(&cy);
	cy = nmulti(&cy, fov);
	ls = (t_vec *)malloc(WIDTH * HEIGHT * sizeof(t_vec));
	y = 0u;
	while ((unsigned int)y < HEIGHT)
	{
		ft_dprintf(2, "\rRendering (%u spp) %5.2f%%", scene.samples * 4, 100.0 * y / (HEIGHT - 1));
		xseed[0] = 0;
		xseed[1] = 0;
		xseed[2] = (unsigned short)(y * y * y);
		x = 0u;
		while ((unsigned int)x < WIDTH)
		{
			sy = 0u;
			i = (HEIGHT - 1u - y) * WIDTH + x;
			while (sy < 2u)
			{
				sx = 0u;
				while (sx < 2u)
				{
					m = vec(0.0, 0.0, 0.0);
					s = 0u;
					while (s < scene.samples)
					{
						u1 = 2.0 * erand48(xseed);
						u2 = 2.0 * erand48(xseed);
						dx = (u1 < 1.0f) ? sqrt(u1) - 1.0 : 1.0 - sqrt(2.0 - u1);
						dy = (u2 < 1.0f) ? sqrt(u2) - 1.0 : 1.0 - sqrt(2.0 - u2);
						a = nmulti(&cx, (((sx + 0.5 + dx) / 2.0 + x) / WIDTH - 0.5));
						b = nmulti(&cy, (((sy + 0.5 + dy) / 2.0 + y) / HEIGHT - 0.5));
						ab = sum(&a, &b);
						d = sum(&ab, &gaze);
						d_t = nmulti(&d, 130.0);
						ry = ray(sum(&eye, &d_t), *norm(&d), EPSILON_SPHERE, INFINITY, 0);
						l_t = radiance(&scene, &ry, xseed);
						l = ndivide(&l_t, (double)scene.samples);
						m = sum(&m, &l);
						s++;
					}
					l_t = clamp3(&m, 0.0, 1.0);
					l = nmulti(&l_t, 0.25);
					ls[i] = sum(&ls[i], &l);
					// ft_printf("ls[%d] = ", i);
					// printv(&ls[i]);
					put_pixel(win, (WIDTH - x), (HEIGHT - y), &ls[i]);
					sx++;
				}
				sy++;
			}
			x++;
		}
		y++;
	}
	// for (size_t i = 0; i < WIDTH * HEIGHT; ++i) {
	// 	ft_printf("%d %d %d ", to_byte(ls[i].x, GAMMA),
	// 		                   to_byte(ls[i].y, GAMMA),
	// 		                   to_byte(ls[i].z, GAMMA));
	// 					   }
	free(ls);
}
