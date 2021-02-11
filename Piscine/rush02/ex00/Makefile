NAME = rush-02

GCCC = gcc -Wall -Wextra -Werror

O = ft_triad.o ft_triad_checker.o ft_functions.o ft_check_key.o ft_dictionary_scan.o main.o

C = ft_triad.c ft_triad_checker.c ft_functions.c ft_check_key.c ft_dictionary_scan.c main.c

all: $(NAME)

$(NAME):
	$(GCCC) -c $(C)
	$(GCCC) $(O) -o $(NAME)
clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all