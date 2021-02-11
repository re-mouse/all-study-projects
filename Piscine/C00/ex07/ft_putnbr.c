/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:45:36 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/17 21:45:37 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);

void	print(int num, int is_it_negative, int digits);

void	ft_putnbr(int num)
{
	int digits;
	int index;
	int is_it_negative;

	index = 0;
	is_it_negative = 0;
	digits = log10(abs(num)) + 1;
	if (num < 0)
	{
		is_it_negative = 1;
	}
	print(num, is_it_negative, digits);
}

void	print(int num, int is_it_negative, int digits)
{
	int		index;
	char	number_array[digits + is_it_negative];

	index = 0;
	sprintf(number_array, "%d", abs(num));
	if (is_it_negative == 1)
	{
		write(1, "-", 1);
	}
	while (index <= sizeof(number_array))
	{
		write(1, &number_array[index], 1);
		++index;
	}
}
