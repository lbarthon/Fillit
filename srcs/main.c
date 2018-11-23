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

void	ft_free_tab(char **tab, int i)
{
	if (tab)
		free(tab);
	while (--i + 1)
		free(*(tab + i));
}

char	**ft_init_tab(int len)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		if (!(*(tab + i++) = (char*)malloc(len + 1)))
		{
			ft_free_tab(tab, i);
			return (NULL);
		}
	return (tab);
}

int		main(int ac, char **av)
{
	short	*shapes;
	char	*used;
	char	**tab;
	int		i;

	if (ac == 2)
	{
		shapes = ft_load_shapes(av[1]);
		if (!ft_is_valid(shapes) && (used = ft_strnew(ft_shapes_len(shapes) + 1)))
		{
			i = 2;
			ft_put_up(&shapes);
			tab = ft_init_tab(i++);
			while (!ft_solve(tab, used, shapes, 0))
				tab = ft_init_tab(i++);
			ft_print_tab(tab);
			free(used);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	if (shapes)
		free(shapes);
}
