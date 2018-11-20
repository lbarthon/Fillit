/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarthon <lbarthon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:25:09 by lbarthon          #+#    #+#             */
/*   Updated: 2018/11/13 09:11:33 by lbarthon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strclen(char *str, char c)
{
	int i;

	i = 0;
	if (str)
		while (str[i] > 0 && str[i] != c)
			i++;
	return (i);
}
