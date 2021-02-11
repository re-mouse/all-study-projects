NAME = do-op

OBJ = ft_atoi.o ft_main.o ft_operators.o

C = ft_atoi.c ft_main.c ft_operators.c

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(GCC) -c $(C)
	$(GCC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 