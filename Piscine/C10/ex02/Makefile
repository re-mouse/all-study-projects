all:
	gcc -Wall -Wextra -Werror -c f_tail.c
	gcc -Wall -Wextra -Werror -c ft_main.c
	gcc -Wall -Wextra -Werror f_tail.o ft_main.o -o ft_tail

clean:	f_tail.o ft_main.o
	rm f_tail.o
	rm ft_main.o

fclean: clean
	rm ft_tail