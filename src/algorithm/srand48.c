/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srand48.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:31:16 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/31 13:32:32 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		rand_ri(unsigned int *seed)
{
	unsigned int next = *seed;
	unsigned int result;

	next *= 1103515245;
	next += 12345;
	result = (unsigned int) (next / 65536) % 2048;

	next *= 1103515245;
	next += 12345;
	result <<= 10;
	result ^= (unsigned int) (next / 65536) % 1024;

	next *= 1103515245;
	next += 12345;
	result <<= 10;
	result ^= (unsigned int) (next / 65536) % 1024;

	*seed = next;
	result = result % 420000000;
	return((double)result / 420000000);
}

unsigned int generate(unsigned int x)
{
    unsigned int value;

	value = x;
    value = (value ^ 61) ^ (value>>16);
    value *= 9;
    value ^= value << 4;
    value *= 0x27d4eb2d;
    value ^= value >> 15;
    return (value);
}

unsigned int generate3(unsigned int x, unsigned int y, unsigned int z)
{
    unsigned int value;

	value = generate(x);
    value = generate(y ^ value);
    value = generate(z ^ value);
    return (value);
}

void 	init_seed(t_render *render)
{
	render->xseed[0] = 0;
	render->xseed[1] = 0;
	render->xseed[2] = (unsigned short)(render->y * render->y * render->y);
}
