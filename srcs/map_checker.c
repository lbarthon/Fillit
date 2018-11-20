/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:25:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/20 11:38:56 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	*ft_map_realloc(short *map, int i)
{
	short	*new;
	int		n;

	if (!(new = (short*)malloc(sizeof(short) * (i + 1))))
		return (NULL);
	n = 0;
	while (n < i)
	{
		new[n] = map[n];
		n++;
	}
	new[i] = 0;
	return (new);
}

static short	*ft_map_init(void)
{
	short	*new;

	if (!(new = (short*)malloc(sizeof(short) * 1)))
		return (NULL);
	*new = 0;
	return (new);
}

static short	*ft_read_next_map(int fd, int i, short *maps)
{
	char	buff[21];
	int		n;
	int		bit;

	if (i != 0)
		read(fd, buff, 1);
	if ((n = 0) == 0 && read(fd, buff, 20) != 20)
		return (NULL);
	buff[20] = '\0';
	if (i == 0 && !(maps = ft_map_init()))
		return (NULL);
	else if (!(maps = ft_map_realloc(maps, i)))
		return (NULL);
	bit = 0;
	while (n < 20)
	{
		if (buff[n] == '#')
			maps[i] |= 1 << bit++;
		else
			maps[i] |= 0 << bit++;
		if ((n + 1) % 5 == 0)
			n++;
		n++;
	}
	return (maps);
}

short			*ft_load_maps(char *str)
{
	short	*maps;
	int		fd;
	int		i;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (i < 26)
	{
		maps = ft_read_next_map(fd, i++, maps);
		if (maps == NULL)
			return (NULL);
	}
	if (i == 26 && read(fd, NULL, 5) > 0)
		return (NULL);
	return (maps);
}
