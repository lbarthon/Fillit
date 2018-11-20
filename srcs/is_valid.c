/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:19:59 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/20 11:29:14 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_valid(char *buff)
{
	int len;

	len = ft_strlen_nofault(buff);
	if (len != 20)
		return (0);
	return (1);
}