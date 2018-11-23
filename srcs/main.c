/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/23 13:17:29 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_min_size(int shapes)
{
	int len;
	int i;

	len = shapes * 4;
	i = 2;
	while (i * i < len)
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	short	*shapes;
	char	*grid;
	int		i;

	shapes = NULL;
	if (ac == 2)
	{
		shapes = ft_load_shapes(av[1]);
		if (ft_is_valid(shapes))
		{
			i = ft_get_min_size(ft_shapes_len(shapes));
			ft_put_up(&shapes);
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
	while (1) {}
	return (0);
}
