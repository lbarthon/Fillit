/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:25:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/24 14:08:58 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static short	*ft_shape_init(void)
{
	short	*new;

	if (!(new = (short*)malloc(sizeof(short) * 2)))
		return (NULL);
	new[0] = 0;
	new[1] = 0;
	return (new);
}

static short	*ft_shape_realloc(short *shapes, int i)
{
	short	*new;
	int		n;

	if (i == 0)
		return (ft_shape_init());
	if (!(new = (short*)malloc(sizeof(short) * (i + 2))))
		return (NULL);
	n = 0;
	while (n < i)
	{
		new[n] = shapes[n];
		n++;
	}
	new[i] = 0;
	new[i + 1] = 0;
	free(shapes);
	return (new);
}

static int		ft_read_next_shape(int fd, int i, short **shapes)
{
	char	buff[21];
	int		bit;
	int		n;

	if (i != 0 && read(fd, buff, 1) > 0)
		bit = -1;
	if ((n = 0) == 0 && read(fd, buff, 20) != 20)
		return ((bit == -1) ? bit : 0);
	buff[20] = '\0';
	if (!(*shapes = ft_shape_realloc(*shapes, i)))
		return (-1);
	bit = 0;
	while (n < 20)
	{
		if (buff[n] == '#')
			(*shapes)[i] |= 1 << bit++;
		else if (buff[n] == '.')
			bit++;
		else if ((buff[n] == '\n' && (n + 1) % 5 != 0) || buff[n] != '\n')
			return (-1);
		n++;
	}
	return (1);
}

short			*ft_load_shapes(char *str)
{
	short	*shapes;
	char	buff[5];
	int		fd;
	int		i;
	int		r;

	shapes = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (i < 26 && (r = ft_read_next_shape(fd, i, &shapes)) > 0)
		i++;
	if ((i == 26 && read(fd, buff, 5) > 0) || r == -1)
	{
		close(fd);
		free(shapes);
		return (NULL);
	}
	close(fd);
	return (shapes);
}
