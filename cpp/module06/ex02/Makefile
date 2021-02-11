NAME = identifer

SRC = C.cpp main.cpp A.cpp B.cpp Base.cpp

OBJ = ${SRC:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${OBJ}: ${SRC}
	clang++ ${CFLAGS} ${SRC} -c

${NAME}: ${OBJ}
	clang++ ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all