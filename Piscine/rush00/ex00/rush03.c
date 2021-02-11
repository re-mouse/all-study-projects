/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:13:32 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 19:13:34 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

void	rush(int x, int y)
{
	int a;
	int b;

	b = 0;
	y--;
	x--;
	while (b <= y)
	{
		a = 0;
		while (a <= x)
		{
			if ((a == 0 && (b == y || b == 0)))
				ft_putchar('A');
			else if (a == x  && (b != 0 || a != 0) && (b == 0 || b == y))
				ft_putchar('C');
			else if (a == 0 || b == 0 || b == y || a == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
