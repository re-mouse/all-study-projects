/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:10:17 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/17 16:10:17 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_comb(void);

void	cycle_action(char a, char b, char c);

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				cycle_action(a, b, c);
				++c;
			}
			++b;
		}
		++a;
	}
}

void	cycle_action(char a, char b, char c)
{
	char comma;
	char space;

	comma = ',';
	space = ' ';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != '7')
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}
