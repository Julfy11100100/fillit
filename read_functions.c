/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 01:59:19 by mmark             #+#    #+#             */
/*   Updated: 2019/06/25 15:00:55 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**get_cube(char *str)
{
	char	**buf;
	int		i;
	int		j;

	buf = (char**)malloc(sizeof(char*) * 4);
	i = -1;
	while (++i < 4)
		buf[i] = (char*)malloc(sizeof(char) * 5);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			buf[i][j] = *str;
			str++;
			j++;
		}
		buf[i][j] = '\0';
		i++;
		str++;
	}
	return (buf);
}

void			get_list(t_list **list, char *str, char let)
{
	t_list	*new_list;
	t_tet	*new_tet;
	char	**cube;

	cube = get_cube(str);
	new_tet = tet_new(cube, let);
	new_list = lst_new_tet(new_tet);
	ft_lst_push_back(list, new_list);
}

static int		break_del(t_list **list)
{
	del_lst_tet(list);
	return (0);
}

static int		file_read_func(int fd, t_list **list, int ret, int i)
{
	int		check;
	char	buf[BUFF_SIZE + 1];

	check = 0;
	while (++i < 26 && ret > 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) >= 20)
		{
			check = ret;
			if ((ret == 21 && buf[20] != '\n') || !(check_all(buf)))
				return (break_del(list));
			else
				get_list(list, buf, 65 + i);
		}
		else if (ret != 0)
			return (break_del(list));
		else if (ret == 0 && i == 0)
			return (break_del(list));
	}
	if (check != 20 || (ret = read(fd, buf, BUFF_SIZE)) != 0)
		return (break_del(list));
	return (1);
}

int				file_read(int fd, t_list **list)
{
	int		ret;
	int		i;

	ret = 1;
	i = -1;
	return (file_read_func(fd, list, ret, i));
}
