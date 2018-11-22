/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:18:31 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/22 07:12:52 by ple-thiec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_settings
{
	int		map_size;
	short	*shapes;
}				t_settings;

short	*ft_load_shapes(char *str);
void	ft_print_short_bytes(short *list);
int		ft_short_list_len(short *list);
int		ft_is_valid(short *list);
void	ft_put_up(short **shapes);

#endif
