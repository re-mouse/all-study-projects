/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:54:42 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 15:54:43 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

void	print_hexadecimal(char *c, int a);

void	print_o_c(char *c, int j, int size);

void	print_hexadecimal_int(unsigned int b, int i, int gab);

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				i;
	int				j;
	void			*temp;

	i = 0;
	j = 0;
	temp = addr;
	while (i <= (size - 1) / 16 && size != 0)
	{
		print_hexadecimal_int((unsigned)addr + i * 16, 15, 0);
		while (j < (16 + 16 * i))
		{
			if (j % 2 == 0 && j <= size)
				print_hexadecimal(temp, 0);
			temp++;
			j++;
		}
		print_o_c((char*)temp - 16, i, size);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

void	print_hexadecimal(char *c, int a)
{
	char	print_c[2];
	int		mod;
	int		b;
	int		i;

	while (a < 2 && (*c != 0 || a == 1))
	{
		print_c[0] = '0';
		print_c[1] = '0';
		i = 1;
		b = *c;
		while (b != 0)
		{
			mod = b % 16;
			b /= 16;
			if (mod < 10)
				print_c[i--] = '0' + mod;
			else
				print_c[i--] = 'a' + mod - 10;
		}
		c++;
		a++;
		write(1, print_c, 2);
	}
	write(1, " ", 1);
}

void	print_hexadecimal_int(unsigned int b, int i, int temp_to_print)
{
	int		mod;
	char	hexa[16];

	while (temp_to_print < 15)
	{
		hexa[temp_to_print] = '0';
		temp_to_print++;
	}
	while (b != 0)
	{
		mod = b % 16;
		b /= 16;
		if (mod < 10)
			hexa[i--] = '0' + mod;
		else
			hexa[i--] = 'a' + mod - 10;
	}
	write(1, hexa, 16);
	write(1, ": ", 2);
}

void	print_o_c(char *c, int j, int size)
{
	int i;
	int count_spc;

	i = 0;
	if (size - j * 16 < 16)
	{
		count_spc = 16 - (size - j * 16);
	}
	while (count_spc > 0)
	{
		write(1, " ", 1);
		count_spc--;
	}
	while (i < 16 && i < size - j * 16)
	{
		if (!(*c >= 32 && *c <= 126))
			write(1, ".", 1);
		else
			write(1, c, 1);
		++c;
		++i;
	}
}
