/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_short_bytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:52:30 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/21 08:19:11 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void		ft_print_short_bytes(short *list)
{
	int i;
	int bit;
	int len;

	len = ft_short_list_len(list);
	i = 0;
	while (i < len)
	{
		bit = 0;
		while (bit < 16)
		{
			ft_putchar('0' + ((list[i] & 1 << bit) != 0));
			if (((bit + 1) % 4) == 0)
				ft_putchar('\n');
			bit++;
		}
		ft_putchar('\n');
		i++;
	}
}
