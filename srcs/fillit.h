/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:18:31 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/22 16:20:18 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

short	*ft_load_shapes(char *str);
void	ft_print_short_bytes(short *list);
int		ft_short_list_len(short *list);
int		ft_is_valid(short *list);
void	ft_put_up(short **shapes);
int		ft_shapes_len(short *shapes);
int		ft_solve(char **tab, char *used, short *shapes, int i);
void	ft_print_tab(char **tab);

#endif
