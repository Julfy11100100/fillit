/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:22:09 by jemogene          #+#    #+#             */
/*   Updated: 2019/06/15 17:03:27 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_char(char *str)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (++i < 20)
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			count++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int		ft_checkcolrow(char *str)
{
	int		i;

	i = 4;
	while (i < 20)
	{
		if (str[i] != '\n')
			return (0);
		i += 5;
	}
	return (1);
}
