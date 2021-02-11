# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 13:03:11 by hleilani          #+#    #+#              #
#    Updated: 2020/12/19 22:24:14 by welease          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBC = libft/libft.a

LIB = libft.a

GNLSRC = $(shell find ./get_next_line -name "*.c")

GNLOBJ = ${GNLSRC:.c=.o}

SRC = $(shell find ./parser ./functions  -name "*.c") main.c argv_mass_utils.c

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Iinc

${NAME}: ${OBJ} ${LIB} ${GNLOBJ}
	${CC} ${CFLAGS} ${OBJ} ${GNLOBJ} -L. -lft -o ${NAME}

all: ${NAME}

${LIB}:
	make -C libft
	mv ./libft/libft.a .

clean:
	rm -f ${OBJ} ${LIB} $ ${GNLOBJ}
	make fclean -C libft

fclean:	clean
		rm -f ${NAME}

re: fclean all
