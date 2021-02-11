/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:45:17 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/17 21:45:19 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	make_combinations(int int_arr[], int n, int i_in_arr, int num);

void	ft_print_combn(int n);

void	print_int(int int_arr[], int n);

void	ft_print_combn(int n)
{
	int data[n];

	make_combinations(data, n, 0, 0);
}

void	make_combinations(int int_arr[], int n, int i_in_arr, int num)
{
	char	char_to_write;

	if (i_in_arr >= n)
	{
		print_int(int_arr, n);
		return ;
	}
	if (num >= 9)
		return ;
	int_arr[i_in_arr] = num;
	make_combinations(int_arr, n, i_in_arr + 1, num + 1);
	make_combinations(int_arr, n, i_in_arr, num + 1);
}

void	print_int(int int_arr[], int n)
{
	int		i;
	int		i_comma;
	int		make_comma;
	char	char_to_write;

	i = 0;
	i_comma = n;
	make_comma = 0;
	while (i < n)
	{
		char_to_write = int_arr[i] + '0';
		write(1, &char_to_write, 1);
		++i;
	}
	while (i_comma > 0)
	{
		if (int_arr[n - i_comma] != 9 - i_comma)
			make_comma = 1;
		i_comma--;
	}
	if (make_comma == 1)
		write(1, ", ", 2);
}
