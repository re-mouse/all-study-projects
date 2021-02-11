# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 13:03:11 by hleilani          #+#    #+#              #
#    Updated: 2020/11/07 17:29:31 by hleilani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = $(shell find ./parser ./type_proc ./printer -name "*.c")

LIBSRC = $(shell find ./libft -name "*.c")

LIB = ./libft/libft.a

LIBOBJ = ${LIBSRC:.c=.o}

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinc

${NAME}: ${OBJ} ${LIBOBJ}
	ar rc ${NAME} ${OBJ} ${LIBOBJ}

all: ${NAME}

${LIBOBJ}:
	make -C libft

bonus: all

clean:
	rm -f ${OBJ} ${LIBOBJ} ${LIB}

fclean:	clean
		rm -f ${NAME}

re: fclean all
