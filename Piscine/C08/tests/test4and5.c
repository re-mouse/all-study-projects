#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_show_tab(struct s_stock_str *par);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

int main(int argc, char **argv)
{
    t_stock_str *b;

    b = ft_strs_to_tab(argc, argv);
	ft_show_tab(b);
}