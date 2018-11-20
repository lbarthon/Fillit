/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:48:05 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/19 11:27:57 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <time.h>

static char	**tab_init(void)
{
	char	**tab;
	int		i;
	int		j;

	if (!(tab = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		if (!(tab[i++] = (char*)malloc(sizeof(char) * 5)))
			return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			tab[i][j++] = '.';
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static int	avalible(char **tab, int pos[2])
{
	if (tab[pos[0]][pos[1]] == '#')
		return (0);
	if (pos[0] < 3 && tab[pos[0] + 1][pos[1]] == '#')
		return (1);
	if (pos[0] > 0 && tab[pos[0] - 1][pos[1]] == '#')
		return (1);
	if (pos[1] < 3 && tab[pos[0]][pos[1] + 1] == '#')
		return (1);
	if (pos[1] > 0 && tab[pos[0]][pos[1] - 1] == '#')
		return (1);
	return (0);
}

static void	print_tab(char **tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			ft_putchar(tab[i][j++]);
		ft_putchar('\n');
		i++;
	}
	if (size != 0)
		ft_putchar('\n');
}

static void	generate(int size)
{
	char	**tab;
	int		pos[2];
	int		i;

	srand(time(NULL));
	while (size-- > 0)
	{
		tab = tab_init();
		tab[rand() % 4][rand() % 4] = '#';
		i = 3;
		while (i > 0)
		{
			pos[0] = rand() % 4;
			pos[1] = rand() % 4;
			if (avalible(tab, pos))
			{
				tab[pos[0]][pos[1]] = '#';
				i--;
			}
		}
		print_tab(tab, size);
	}
}

int			main(int ac, char **av)
{
	int size;

	if (ac == 2)
	{
		size = atoi(av[1]);
		if (size != 0)
			generate(size);
		else
			ft_putendl("Size invalid.");
	}
	else
		ft_putendl("Please use ./generator <size>");
}
