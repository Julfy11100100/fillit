/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:15:02 by jemogene          #+#    #+#             */
/*   Updated: 2019/06/25 15:17:53 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delmass(char **mass, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_strdel(&mass[i]);
	free(mass);
	mass = NULL;
}

void	tet_del(t_tet *tet)
{
	delmass(tet->tet, tet->len);
	tet->left = 0;
	tet->len = 0;
	tet->letter = 0;
	tet->top = 0;
	tet->wid = 0;
	free(tet);
	tet = NULL;
}

void	del_lst_tet(t_list **list)
{
	t_list	*prev;

	while (*list)
	{
		tet_del((*list)->content);
		(*list)->content_size = 0;
		prev = *list;
		*list = (*list)->next;
		free(prev);
	}
}
