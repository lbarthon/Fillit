/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:30:29 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/21 10:03:52 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_upper_line(short shape)
{
	int bit;

	bit = 0;
	while (bit < 4)
	{
		if ((shape & 1 << bit) != 0)
			return (0);
		bit++;
	}
	return (1);
}

static int		ft_left_line(short shape)
{
	int bit;

	bit = 0;
	while (bit < 13)
	{
		if ((shape & 1 << bit) != 0)
			return (0);
		bit += 4;
	}
	return (1);
}

static short	ft_move_up(short shape)
{
	short	new;
	char	bit;

	new = 0;
	bit = 3;
	while (++bit < 16)
		if ((shape & 1 << bit) != 0)
			new |= 1 << (bit - 4);
	return (new);
}

static short	ft_move_left(short shape)
{
	short	new;
	char	bit;

	new = 0;
	bit = 0;
	while (++bit < 16)
		if ((shape & 1 << bit) != 0)
			new |= 1 << (bit - 1);
	return (new);
}

void			ft_put_up(short **shapes)
{
	int len;
	int i;

	len = ft_short_list_len(*shapes);
	i = 0;
	while (i < len)
	{
		while (ft_upper_line((*shapes)[i]))
			(*shapes)[i] = ft_move_up((*shapes)[i]);
		while (ft_left_line((*shapes)[i]))
			(*shapes)[i] = ft_move_left((*shapes)[i]);
		i++;
	}
}
