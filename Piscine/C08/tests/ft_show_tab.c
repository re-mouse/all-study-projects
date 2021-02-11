/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:32:34 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/26 18:32:35 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	put_str_linebreak(char *str);

void	putnbr(int n);

void	ft_show_tab(struct s_stock_str *par)
{
	char	*crntstr;
	char	*crntcopy;
	int		size;

	if (par == NULL)
		return ;
	size = par->size;
	crntstr = par->str;
	crntcopy = par->copy;
	while (*crntstr != 0)
	{
		put_str_linebreak(crntstr);
		putnbr(size);
		put_str_linebreak(crntcopy);
		par++;
		crntstr = par->str;
		crntcopy = par->copy;
		size = par->size;
	}
}

void	put_str_linebreak(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	putnbr(int n)
{
	char	num[100];
	int		temp;
	int		i;
	int		j;

	temp = n;
	i = 0;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	j = i;
	while (n > 0)
	{
		*(num + i - 1) = n % 10 + '0';
		i--;
		n /= 10;
	}
	while (i < j)
	{
		write(1, num + i, 1);
		i++;
	}
	write(1, "\n", 1);
}
