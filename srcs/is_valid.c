/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:19:59 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/20 16:10:55 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_count(short nbr)
{
	char i;
	char bit;

	i = 0;
	bit = 0;
	while (bit < 16)
		if ((nbr & 1 << bit++) != 0)
			i++;
	return (i == 4);
}

static int	ft_bounded(short nbr)
{
	char bit;
	char i;

	bit = 0;
	while (bit < 16)
	{
		i = 0;
		if ((nbr & 1 << bit++) != 0)
		{
			if (bit > 3 && (nbr & 1 << (bit - 4)) != 0)
				i++;
			if (bit < 12 && (nbr & 1 << (bit + 4)) != 0)
				i++;
			if ((bit % 4) != 0 && (nbr & 1 << (bit - 1)) != 0)
				i++;
			if (((bit + 1) % 4) != 0 && (nbr & 1 << (bit + 1)) != 0)
				i++;
			if (i == 0)
				return (0);
		}
		bit++;
	}
	return (1);
}

static int	ft_check(short nbr)
{
	if (!ft_count(nbr))
		return (0);
	if (!ft_bounded(nbr))
		return (0);
	return (1);
}

int			ft_is_valid(short *list)
{
	int len;
	int i;

	len = ft_short_list_len(list);
	if (len == 0)
		return (0);
	i = 0;
	while (i < len)
		if (!ft_check(list[i++]))
			return (0);
	return (1);
}
