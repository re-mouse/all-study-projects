/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:37:54 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/30 20:37:54 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

void	ft_p(long long a, long long b, long long (*oper)(long long, long long))
{
	long long	res;

	res = oper(a, b);
	ft_putnbr(res);
}

int		main(int argc, char **argv)
{
	long long	(*oper[5])(long long, long long);
	int			oper_n;
	long long	snd_num;

	if (argc != 4 || (oper_n = ft_g_oper(argv[2])) < 0)
	{
		ft_putnbr(0);
		return (0);
	}
	oper_n = ft_g_oper(argv[2]);
	oper[0] = &ft_sum;
	oper[1] = &ft_substraction;
	oper[2] = &ft_multiply;
	oper[3] = &ft_div;
	oper[4] = &ft_mod;
	snd_num = ft_atoi(argv[3]);
	if (oper_n == 3 && snd_num == 0)
		return (output_error("Stop : division by zero"));
	if (oper_n == 4 && snd_num == 0)
		return (output_error("Stop : modulo by zero"));
	ft_p(ft_atoi(argv[1]), snd_num, oper[oper_n]);
}

int		ft_g_oper(char *operator)
{
	if (operator[0] == '+' && operator[1] == 0)
		return (0);
	if (operator[0] == '-' && operator[1] == 0)
		return (1);
	if (operator[0] == '*' && operator[1] == 0)
		return (2);
	if (operator[0] == '/' && operator[1] == 0)
		return (3);
	if (operator[0] == '%' && operator[1] == 0)
		return (4);
	return (-1);
}

void	ft_putnbr(long long nb)
{
	int			index;
	char		num[100];

	index = 0;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	if (nb == 0)
		write(1, "0", 1);
	while (nb != 0)
	{
		num[index] = '0' + nb % 10;
		nb /= 10;
		index++;
	}
	while (index-- > 0)
		write(1, &num[index], 1);
	write(1, "\n", 1);
}

int		output_error(char *error)
{
	while (*error)
	{
		write(1, error, 1);
		error++;
	}
	write(1, "\n", 1);
	return (0);
}
