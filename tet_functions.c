/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmark <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:18:50 by mmark             #+#    #+#             */
/*   Updated: 2019/06/15 16:55:03 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet			*tet_new(char **src, char let)
{
	t_tet	*new_tet;

	new_tet = (t_tet*)malloc(sizeof(t_tet));
	if (src == NULL)
		return (NULL);
	new_tet->wid = 0;
	new_tet->len = 0;
	new_tet->left = 4;
	new_tet->top = 4;
	new_tet->letter = let;
	tet_get_position(src, new_tet);
	tet_get_figure(src, new_tet);
	if (!new_tet)
		return (NULL);
	delmass(src, 4);
	return (new_tet);
}

void			tet_get_figure(char **src, t_tet *tet)
{
	int		i;
	int		j;
	char	**buf;

	buf = (char**)malloc(sizeof(char*) * tet->len);
	i = -1;
	while (++i < tet->len)
		buf[i] = (char*)malloc(sizeof(char) * (tet->wid + 1));
	i = 0;
	while (i < tet->len)
	{
		j = 0;
		while (j < tet->wid)
		{
			if (src[i + tet->top][j + tet->left] == '#')
				buf[i][j] = tet->letter;
			else
				buf[i][j] = '.';
			j++;
		}
		buf[i][j] = '\0';
		i++;
	}
	tet->tet = buf;
}

static void		tet_res(char **src, t_tet *tet, int i, int b)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		if (src[i][j] == '#')
		{
			if (j > tet->left)
			{
				b++;
			}
			if (j < tet->left)
			{
				tet->left = j;
				if (b == 2 && tet->wid == 2)
					b++;
			}
			j = 5;
		}
	}
	if (b != 0)
		tet->len++;
	if (b > tet->wid)
		tet->wid = b;
}

void			tet_get_position(char **src, t_tet *tet)
{
	int		i;
	int		j;
	int		b;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		b = 0;
		while (++j < 4)
		{
			if (src[i][j] == '#')
			{
				b++;
				if (i < tet->top)
					tet->top = i;
			}
		}
		tet_res(src, tet, i, b);
	}
}
