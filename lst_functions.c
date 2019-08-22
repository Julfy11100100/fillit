/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:00:49 by mmark             #+#    #+#             */
/*   Updated: 2019/06/25 15:10:02 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*lst_new_tet(t_tet *tet)
{
	t_list		*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->content = tet;
		new->content_size = 0;
		return (new);
	}
	return (NULL);
}
