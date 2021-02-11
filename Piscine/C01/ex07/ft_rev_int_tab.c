/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:06:59 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:07:00 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

int		reverse_number(int old_num);

int		power_10(int what_power);

int		cound_digits(int num);

void	ft_rev_int_tab(int *tab, int size)
{
	int index_in_array;

	index_in_array = 0;
	while (index_in_array < size)
	{
		*tab = reverse_number(*tab);
		tab++;
		++index_in_array;
	}
}

int		reverse_number(int old_num)
{
	int new_num;
	int digit_index;
	int number_digits;
	int last_int;

	new_num = 0;
	number_digits = cound_digits(old_num);
	digit_index = number_digits - 1;
	while (digit_index >= 0)
	{
		last_int = old_num % 10;
		old_num = old_num / 10;
		new_num += last_int * power_10(digit_index);
		digit_index--;
	}
	return (new_num);
}

int		power_10(int what_power)
{
	int powered_num;

	powered_num = 1;
	while (what_power > 0)
	{
		powered_num *= 10;
		what_power--;
	}
	return (powered_num);
}

int		cound_digits(int num)
{
	int count;

	count = 0;
	while (num != 0 || num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
