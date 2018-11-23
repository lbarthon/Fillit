/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/22 16:20:49 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	short	*shapes;
	char	*grid;
	int		i;

	if (ac == 2)
	{
		shapes = ft_load_shapes(av[1]);
		if (ft_is_valid(shapes))
		{
			i = 2;
			ft_put_up(&shapes);
			ft_print_short_bytes(shapes);
			grid = ft_create_str(i++);
			while (!ft_solve(grid, shapes, ft_shapes_len(shapes), 0))
				grid = ft_create_str(i++);
			ft_putstr(grid);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	if (shapes)
		free(shapes);
}
