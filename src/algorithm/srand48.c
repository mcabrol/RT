/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srand48.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcabrol <mcabrol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 09:31:16 by mcabrol           #+#    #+#             */
/*   Updated: 2020/01/20 14:37:09 by mcabrol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_seed(t_algo *rt)
{
	rt->xseed[0] = 0;
	rt->xseed[1] = 0;
	rt->xseed[2] = (unsigned short)(rt->y * rt->y * rt->y);
}

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
