/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:54:43 by ple-thie          #+#    #+#             */
/*   Updated: 2018/11/21 00:06:02 by ple-thiec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_overlap_shapes(short shape1, short shape2)
{
	return shape1 ^ shape2 == 0;
}

static short ft_extract_shape(void *map, size_t map_size, int loc)
{
	short			extract;
	unsigned int	len;	
	int				i;
	int				n;

	len = loc + 4 > map_size ? map_size - loc : 4;
	n= 0;
	while (n == 4)
	{
		*map = *map << loc;
		while (i < len)
		{
			extract &= (*map & 1) << (4 * n + i);
			i++;
		}
		n++;
	}
	return extract;
}

char	**ft_solve(short *shapes, int map_size, void *map, char **return_map)
{
	
}
