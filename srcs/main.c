/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/20 11:52:13 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!(ft_load_maps(av[1])))
			ft_putendl("PAS VALIDE");
	}
	else
		ft_putendl("error");
}
