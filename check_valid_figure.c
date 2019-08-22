/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_figure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 18:51:34 by mmark             #+#    #+#             */
/*   Updated: 2019/06/15 15:57:29 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_below_15(char *str, int i)
{
	int		count;

	count = 0;
	if (str[i + 5] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (i > 4)
	{
		if (str[i - 5] == '#')
			count++;
	}
	if (i != 0)
	{
		if (str[i - 1] == '#')
			count++;
	}
	return (count);
}

static int		check_above_15(char *str, int i)
{
	int		count;

	count = 0;
	if (str[i - 5] == '#')
		count++;
	if (str[i - 1] == '#')
		count++;
	if (i != 18)
	{
		if (str[i + 1] == '#')
			count++;
	}
	return (count);
}

int				check_form(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = -1;
	while (++i < 19)
	{
		if (str[i] == '#')
		{
			if (i < 15)
				count += check_below_15(str, i);
			else
				count += check_above_15(str, i);
		}
	}
	return (count == 6 || count == 8);
}

int				check_all(char *str)
{
	int		check;

	check = check_form(str) * valid_char(str) * ft_checkcolrow(str);
	return (check);
}
