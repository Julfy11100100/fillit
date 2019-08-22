/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:20:20 by mmark             #+#    #+#             */
/*   Updated: 2019/06/25 15:06:54 by jemogene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct	s_map
{
	char		**map;
	int			size;
}				t_map;

typedef struct	s_tet
{
	char		**tet;
	char		letter;
	int			left;
	int			top;
	int			len;
	int			wid;
}				t_tet;

void			map_set(t_map *map, char **buf, int size);
t_map			*map_new(int size);
void			map_print(t_map *map);
void			map_del(t_map *map);
t_tet			*tet_new(char **src, char let);
void			tet_get_position(char **src, t_tet *tet);
void			tet_get_figure(char **src, t_tet *tet);
char			**get_cube(char *str);
int				file_read(int fd, t_list **list);
int				check_map(t_map *map, t_tet *tet, int y, int x);
int				insert_map(t_map *map, t_tet *tet, int y, int x);
void			prev_map(t_map *map, t_tet *tet, int y, int x);
void			get_list(t_list **list, char *str, char let);
int				solve(t_map *map, t_list *list);
t_map			*solve_map(t_list *list);
int				check_form(char *str);
int				ft_checkcolrow(char *str);
int				valid_char(char *str);
int				check_all(char *str);
void			delmass(char **mass, int size);
void			tet_del(t_tet *tet);
void			del_lst_tet(t_list **list);
t_list			*lst_new_tet(t_tet *tet);

#endif
