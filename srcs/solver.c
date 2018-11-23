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

int		ft_can_put(char *str, short shape, int str_len)
{
	int x;
	int bit;

	x = 0;
	bit = 0;
	while (bit < 16)
	{
		if (str[x] == '\0')
			return (0);
		if (shape & (1 << bit++) && str[x] != '.')
			return (-1);
		x++;
		if (bit % 4 == 0)
			x += str_len - 3;
	}
	return (1);
}

int		ft_put_shape(char *str, short shape, int str_len, char c)
{
	int x;
	int bit;

	x = 0;
	bit = 0;
	while (bit < 16)
	{
		if (shape & (1 << bit++))
			str[x] = c;
		x++;
		if (bit % 4 == 0)
			x += str_len - 3;
	}
}

int		ft_solve(char *str, short *shapes, int shapes_len, int i)
{
	int     put;
	int 	str_len;
    char    *tmp;

	tmp = str;
	str_len = ft_strclen(tmp, '\n');
	if (i >= shapes_len)
		return (1);
	while ((put = ft_can_put(tmp, shapes[i], str_len)))
	{
		if (put == 1)
		{
			ft_put_shape(tmp, shapes[i], str_len, 'A' + i);
			if (ft_solve(tmp, shapes, shapes_len, i + 1) == 1)
				return (1);
			ft_put_shape(tmp, shapes[i], str_len, '.');
		}
		tmp++;
	}
	return (0);
}

char 	*ft_create_str(int size)
{
	char *str;
	int ind;

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















