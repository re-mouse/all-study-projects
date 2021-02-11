NAME = asmtester

LIBASM = libasm.a

MAINSRC = main.c

SRC = $(shell find . -name "ft_*.s")

MAINOBJ = main.o

SRCOBJ = ${SRC:.s=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

clean:
	rm -f ${SRCOBJ} ${MAINOBJ} ${LIBASM}

fclean: clean
	rm -f ${NAME}

re:	fclean all

${NAME}: ${LIBASM} ${MAINOBJ}
	${CC} ${CFLAGS} ${MAINOBJ} libasm.a -o ${NAME}

${LIBASM}: ${SRCOBJ}
	ar rc libasm.a ${SRCOBJ}

${MAINOBJ}: ${MAINSRC}
	${CC} ${CFLAGS} ${MAINSRC} -c

${SRCOBJ}: ${SRC}
	for asm in $(shell find . -name "ft_*.s"); do nasm -fmacho64 $${asm}; done
