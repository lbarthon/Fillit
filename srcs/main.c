/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/21 09:55:01 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	short *shapes;

	if (ac == 2)
	{
		shapes = ft_load_maps(av[1]);
		if (shapes && ft_is_valid(shapes))
		{
			ft_put_up(&shapes);
			ft_print_short_bytes(shapes);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
}
