/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:54:43 by ple-thie          #+#    #+#             */
/*   Updated: 2018/11/24 10:54:11 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_can_put(char *str, short shape, int str_len)
{
	int x;
	int bit;
	int len;

	x = 0;
	bit = 0;
	len = ft_strlen_nofault(str);
	while (bit < 16)
	{
		if (x >= len)
		{
			while (bit < 16)
				if ((shape & 1 << bit++) != 0)
					return (0);
			break ;
		}
		if ((shape & 1 << bit++) != 0 && str[x] != '.')
			return (-1);
		x++;
		if (bit % 4 == 0)
			x += str_len - 3;
	}
	return (1);
}

void	ft_put_shape(char *str, short shape, int str_len, char c)
{
	int x;
	int bit;

	x = 0;
	bit = 0;
	while (bit < 16)
	{
		if ((shape & 1 << bit++) != 0)
			str[x] = c;
		x++;
		if (bit % 4 == 0)
			x += str_len - 3;
	}
}

int		ft_solve(char *str, short *shapes, int shapes_len, int i)
{
	int		put;
	int		str_len;
	char	*tmp;

	if (!str)
		return (0);
	tmp = str;
	str_len = ft_strclen(tmp, '\n');
	if (i >= shapes_len)
		return (1);
	while ((put = ft_can_put(tmp, shapes[i], str_len)) != 0)
	{
		if (put == 1)
		{
			ft_put_shape(tmp, shapes[i], str_len, 'A' + i);
			if (ft_solve(str, shapes, shapes_len, i + 1))
				return (1);
			ft_put_shape(tmp, shapes[i], str_len, '.');
		}
		tmp++;
	}
	return (0);
}

char	*ft_create_str(int size, char *grid)
{
	char	*str;
	int		ind;

	if (grid)
		free(grid);
	if (!(str = (char*)malloc(size * size + size + 1)))
		return (NULL);
	ind = 0;
	while (ind < size * size + size)
	{
		if (ind != 0 && (ind + 1) % (size + 1) == 0)
			str[ind] = '\n';
		else
			str[ind] = '.';
		ind++;
	}
	str[ind] = '\0';
	return (str);
}
