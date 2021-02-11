/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:16:33 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 16:16:34 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	print_hexadecimal(char a);

int		ft_strlen(char *str);

int		ft_str_is_printable(char str);

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str != 0)
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_putstr_non_printable(char *str)
{
	int		n;
	int		i;
	char	a;

	i = 0;
	n = ft_strlen(str);
	while (i < n)
	{
		a = *str;
		ft_str_is_printable(a);
		str++;
		i++;
	}
}

void	print_hexadecimal(char a)
{
	int		num;
	int		mod;
	int		i;
	char	hexa[2];
	char	slash;

	num = a;
	hexa[0] = '0';
	hexa[1] = '0';
	i = 1;
	slash = 92;
	while (num != 0)
	{
		mod = num % 16;
		num /= 16;
		if (mod <= 9)
			hexa[i] = '0' + mod;
		else
			hexa[i] = 'a' + mod - 10;
		i--;
	}
	write(1, &slash, 1);
	write(1, &hexa[0], 1);
	write(1, &hexa[1], 1);
}

int		ft_str_is_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		print_hexadecimal(c);
	else
		write(1, &c, 1);
}
