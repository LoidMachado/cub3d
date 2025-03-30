# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmachado <lmachado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 12:04:12 by lmachado          #+#    #+#              #
#    Updated: 2025/03/28 13:28:06 by lmachado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
FLAGS = -g -Wall -Wextra -Werror
SRC = src/main.c\
	src/config_map.c\
	src/validations.c\
	src/init_main.c\
	src/validate_all.c\
	src/get_map/aux_func1.c\
	src/get_map/ft_split.c\
	src/get_map/ft_split_aux.c\
	src/get_map/get_map.c\
	src/get_map/get_nextline.c\
	src/get_map/ft_strjoin.c\
	src/ft_split_1.c\
	src/ft_memcpy.c\
	src/ft_strtrim.c\

		
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
