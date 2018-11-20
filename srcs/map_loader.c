/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:25:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/20 15:56:41 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static short	*ft_map_init(void)
{
	short	*new;

	if (!(new = (short*)malloc(sizeof(short) * 2)))
		return (NULL);
	new[0] = 0;
	new[1] = 0;
	return (new);
}

static short	*ft_map_realloc(short *map, int i)
{
	short	*new;
	int		n;

	if (i == 0)
		return (ft_map_init());
	if (!(new = (short*)malloc(sizeof(short) * (i + 2))))
		return (NULL);
	n = 0;
	while (n < i)
	{
		new[n] = map[n];
		n++;
	}
	new[i] = 0;
	new[i + 1] = 0;
	free(map);
	return (new);
}

static int		ft_read_next_map(int fd, int i, short **maps)
{
	char	buff[21];
	int		n;
	int		bit;

	if (i != 0)
		read(fd, buff, 1);
	if ((n = 0) == 0 && read(fd, buff, 20) != 20)
		return (0);
	buff[20] = '\0';
	if (!(*maps = ft_map_realloc(*maps, i)))
		return (-1);
	bit = 0;
	while (n < 20)
	{
		if (buff[n] == '#')
			(*maps)[i] |= 1 << bit++;
		else if (buff[n] == '.')
			(*maps)[i] &= ~(0 << bit++);
		else if ((n + 1) % 5 == 0 && buff[n] == '\n')
			n++;
		else
			return (-1);
		n++;
	}
	return (1);
}

short			*ft_load_maps(char *str)
{
	short	*maps;
	char	buff[5];
	int		fd;
	int		i;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (i < 26 && ft_read_next_map(fd, i, &maps) > 0)
		i++;
	if (i == 26 && read(fd, buff, 5) > 0)
		return (NULL);
	return (maps);
}
