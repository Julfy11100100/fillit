# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemogene <jemogene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 16:06:31 by mmark             #+#    #+#              #
#    Updated: 2019/06/25 15:13:20 by jemogene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = ./libft/

SRC_C = check_valid_figure.c fillit.c check_valid.c map_functions.c\
	read_functions.c search_function.c solve_function.c tet_functions.c\
	del_functions.c lst_functions.c

all: $(NAME)

$(NAME):
	make -C $(LIB) re
	gcc -Wall -Werror -Wextra -L./libft -lft $(SRC_C) -o $(NAME)

clean:
	make -C $(LIB) fclean

fclean: clean
	rm -rf $(NAME)

re: fclean all
