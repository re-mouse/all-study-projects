NAME = philo_two

SRC = $(shell find . -name "*.c" -maxdepth 1)

OBJ = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all