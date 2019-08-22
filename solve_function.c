/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 01:38:11 by mmark             #+#    #+#             */
/*   Updated: 2019/06/25 15:02:13 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				solve(t_map *map, t_list *list)
{
	int		i;
	int		j;
	t_tet	*tet;

	if (list == NULL)
		return (1);
	tet = list->content;
	i = -1;
	while (++i < map->size)
	{
		j = -1;
		while (++j < map->size)
		{
			if (check_map(map, tet, i, j))
			{
				if ((solve(map, list->next)))
					return (1);
				else
					prev_map(map, tet, i, j);
			}
		}
	}
	return (0);
}

static int		sqrt(int nb)
{
	int i;
	int n;

	i = 0;
	n = 1;
	while (n <= nb / 2)
	{
		i = n * n;
		if (i >= nb)
		{
			return (n);
		}
		n = n + 1;
	}
	return (0);
}

t_map			*solve_map(t_list *list)
{
	int		size;
	int		size_list;
	t_map	*map;

	size_list = ft_lst_size(list);
	size = sqrt(size_list * 4);
	map = map_new(size);
	while ((solve(map, list)) == 0)
	{
		size++;
		map_del(map);
		map = map_new(size);
	}
	return (map);
}
