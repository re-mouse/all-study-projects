/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:45:47 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/17 21:45:49 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_numbers(int num);

void	end_cycle_action(int a, int b);

void	ft_print_comb2(void);

void	ft_print_comb2(void)
{
	char	space;
	char	comma;
	int		a;
	int		b;

	a = 0;
	b = 0;
	space = ' ';
	comma = ',';
	while (a != 99 && b != 99)
	{
		while (b < 99)
		{
			++b;
			if (a != b)
			{
				end_cycle_action(a, b);
			}
		}
		++a;
		b = 0;
	}
}

void	end_cycle_action(int a, int b)
{
	write_numbers(a);
	write(1, &space, 1);
	write_numbers(b);
	if (a != 98 || b != 99)
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	write_numbers(int num)
{
	char numb[2];

	sprintf(numb, "%02d", num);
	write(1, &numb[0], 1);
	write(1, &numb[1], 1);
}
