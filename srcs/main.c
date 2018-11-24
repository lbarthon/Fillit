/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/24 11:08:43 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_get_min_size(int shapes)
{
	int len;
	int i;

	len = shapes * 4;
	i = 2;
	while (i * i < len)
		i++;
	return (i);
}

static void	ft_putgrid(char *grid)
{
	if (grid)
	{
		ft_putstr(grid);
		free(grid);
	}
}

int			main(int ac, char **av)
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
			grid = ft_create_str(i++, NULL);
			while (!ft_solve(grid, shapes, ft_shapes_len(shapes), 0))
				grid = ft_create_str(i++, grid);
			ft_putgrid(grid);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit file");
	if (shapes)
		free(shapes);
	return (0);
}
