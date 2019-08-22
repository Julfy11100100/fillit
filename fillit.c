/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:36:42 by mmark             #+#    #+#             */
/*   Updated: 2019/06/25 15:10:50 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	t_map	*map;

	list = NULL;
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (file_read(fd, &list))
		{
			map = solve_map(list);
			map_print(map);
			del_lst_tet(&list);
			map_del(map);
			ft_putchar('\n');
		}
		else
			write(1, "error\n", 6);
	}
	return (0);
}
