/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:58 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/22 07:21:17 by ple-thiec        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_free_settings(t_settings *settings)
{
	if (settings != NULL)
	{
		free(settings->shapes);
		free(settings);
	}
}

int			main(int ac, char **av)
{
	t_settings *settings;

	if (ac == 2)
	{
		if (!(settings = malloc(sizeof(t_settings))))
			return (1);

		settings->shapes = ft_load_shapes(av[1]);
		if (settings->shapes && ft_is_valid(settings->shapes))
		{
			ft_put_up(&settings->shapes);
			ft_print_short_bytes(settings->shapes);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("error");
	ft_free_settings(settings);
}
