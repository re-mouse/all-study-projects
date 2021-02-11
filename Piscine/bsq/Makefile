# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 18:10:11 by paustin           #+#    #+#              #
#    Updated: 2020/10/07 18:04:29 by hleilani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ

SRC = ft_main.c ft_map_analyzer.c ft_map_intializer.c ft_map_helper.c ft_user_input.c

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

${OBJ} : ft_map.h

all: ${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
		rm -f ${NAME}

re: fclean all
