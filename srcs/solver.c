/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:54:43 by ple-thie          #+#    #+#             */
/*   Updated: 2018/11/22 16:22:22 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_overlap(char **tab, short shape, int x, int y)
{
	int x_incr;
	int y_incr;

	x_incr = 0;
	y_incr = 0;
	while (tab[x + x_incr] && x_incr < 4)
	{
		while (tab[x + x_incr][y + y_incr] && y_incr < 4)
		{
			if (tab[x + x_incr][y + y_incr] != '.' &&
					(shape & 1 << (x_incr * 4 + y_incr)) == 1)
				return (1);
			y_incr++;
		}
		x_incr++;
	}
	if (!y_incr == 4 && !x_incr == 4)
	{
		y_incr += x_incr * 4;
		while (y_incr < 16)
			if (shape & 1 << (y_incr) == 1)
				return (1);
	}
	return (0);
}

int		ft_can_put(char **tab, short shape)
{
	int x;
	int y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (ft_overlap(tab, shape, x, y))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_put_shape(char **tab, short shape, char c)
{
	int x;
	int y;
	int bit;

	x = 0;
	bit = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (shape & 1 << bit++)
				tab[x][y] = c;
			y++;
		}
		x++;
	}
}

int		ft_next_put(char **tab, short *shapes, int i)
{
	int j;

	j = i + 1;
	while (!ft_can_put(tab, shapes[j]) && j != i)
		j = (j + 1) % 26;
	if (j == i)
		return (-1);
	return (j);
}

int		ft_solve(char **tab, char *used, short *shapes, int i)
{
	int shapes_len;
	int j;

	shapes_len = ft_shapes_len(shapes);
	if (ft_strlen_nofault(used) == shapes_len)
		return (1);
	if (used[shapes_len] != 0 || !ft_can_put(tab, shapes[i]))
	{
		if ((j = ft_next_put(tab, shapes, i)) != -1)
			return (ft_solve(tab, used, shapes, j));
		else
			return (0);
	}
	ft_put_shape(tab, shapes[i], 'A' + i);
	return (ft_solve(tab, used, shapes, (i + 1) % 26));
}
