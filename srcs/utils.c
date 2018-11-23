/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:16:06 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/22 16:21:23 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_short_list_len(short *list)
{
	int i;

	i = 0;
	if (list)
		while (list[i] != 0)
			i++;
	return (i);
}

int		ft_shapes_len(short *shapes)
{
	int i;

	i = 0;
	if (shapes)
		while (shapes[i])
			i++;
	return (i);
}

void	ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_putendl(tab[i++]);
}
