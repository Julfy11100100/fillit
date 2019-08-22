/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:12:32 by mmark             #+#    #+#             */
/*   Updated: 2019/06/15 16:32:00 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_map(t_map *map, t_tet *tet, int y, int x)
{
	int		i;
	int		j;

	if ((tet->len * tet->wid) > (map->size * map->size))
		return (0);
	if ((y + tet->len) > map->size || (x + tet->wid) > map->size)
		return (0);
	i = 0;
	while (i < tet->len)
	{
		j = 0;
		while (j < tet->wid)
		{
			if (tet->tet[i][j] != '.' && map->map[i + y][j + x] != '.')
				return (0);
			j++;
		}
		i++;
	}
	insert_map(map, tet, y, x);
	return (1);
}

int		insert_map(t_map *map, t_tet *tet, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < tet->len)
	{
		j = 0;
		while (j < tet->wid)
		{
			if (tet->tet[i][j] == tet->letter && map->map[i + y][j + x] == '.')
				map->map[i + y][j + x] = tet->letter;
			j++;
		}
		i++;
	}
	return (0);
}

void	prev_map(t_map *map, t_tet *tet, int y, int x)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tet->len)
	{
		j = -1;
		while (++j < tet->wid)
		{
			if ((tet->tet)[i][j] != '.')
				(map->map)[i + y][j + x] = '.';
		}
	}
}
