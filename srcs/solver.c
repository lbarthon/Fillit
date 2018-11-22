/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:54:43 by ple-thie          #+#    #+#             */
/*   Updated: 2018/11/22 07:43:23 by ple-thiec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_overlap_shapes(short shape1, short shape2)
{
	return shape1 ^ shape2 == 0;
}

static short ft_extract_shape(char *map, size_t map_size, int loc)
{
	short			extract;
	unsigned int	len;	
	int				n;
	char			c;

	len = (loc + 4 > map_size) ? (map_size - loc) : 4;
	n = 0;
	extract = 0;
	while (n < 4)
	{
		*map = *map << loc;
		c = *map;
		extract = c & 0xF0;
		extract << len;
		n++;
	}
	return extract;
}

void	ft_place_shape(short shape, char **map, char disp_map, int loc)
{
	
}

char	**ft_solve(t_settings *settings)
{
	
}
