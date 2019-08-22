/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:35:22 by mmark             #+#    #+#             */
/*   Updated: 2019/06/15 16:16:21 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		map_set(t_map *map, char **buf, int size)
{
	map->map = buf;
	map->size = size;
}

t_map		*map_new(int size)
{
	t_map	*new_map;
	char	**buf;
	int		i;
	int		j;

	if (size <= 0)
		return (NULL);
	new_map = (t_map*)malloc(sizeof(t_map));
	buf = (char**)malloc(sizeof(char*) * size);
	i = -1;
	while (++i < size)
		buf[i] = (char*)malloc(sizeof(char) * size + 1);
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			buf[i][j] = '.';
			j++;
		}
		buf[i][j] = '\0';
	}
	map_set(new_map, buf, size);
	return (new_map);
}

void		map_print(t_map *map)
{
	int		i;

	if (map)
	{
		i = 0;
		while (i < map->size)
		{
			ft_putstr(map->map[i]);
			i++;
			if (i != map->size)
				ft_putchar('\n');
		}
	}
}

void		map_del(t_map *map)
{
	if (map)
	{
		delmass(map->map, map->size);
		map->size = 0;
		free(map);
		map = NULL;
	}
}
