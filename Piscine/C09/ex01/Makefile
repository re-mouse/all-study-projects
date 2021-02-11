all: libft.a
	
libft.a: ./srs/ft_putchar.c ./srs/ft_swap.c ./srs/ft_putstr.c ./srs/ft_strlen.c ./srs/ft_strcmp
	gcc -Wall -Iincludes -Wextra -Werror -c ./srs/ft_putchar.c -o ./srs/ft_putchar.o
	gcc -Wall -Iincludes -Wextra -Werror -c ./srs/ft_swap.c -o ./srs/ft_swap.o
	gcc -Wall -Iincludes -Wextra -Werror -c ./srs/ft_putstr.c -o ./srs/ft_putstr.o
	gcc -Wall -Iincludes -Wextra -Werror -c ./srs/ft_strlen.c -o ./srs/ft_strlen.o
	gcc -Wall -Iincludes -Wextra -Werror -c ./srs/ft_strcmp.c -o ./srs/ft_strcmp.o
	ar rc libft.a ./srs/ft_putchar.o ./srs/ft_putstr.o ./srs/ft_strcmp.o ./srs/ft_strlen.o ./srs/ft_swap.o

clean:
	rm ./srs/ft_putchar.o ./srs/ft_swap.o ./srs/ft_putstr.o ./srs/ft_strlen.o ./srs/ft_strcmp.o

re:
	make fclean
	make

fclean:
	make clean
	rm libft.a