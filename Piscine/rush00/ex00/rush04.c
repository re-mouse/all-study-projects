/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:22:35 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 17:22:36 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		check_cond_one(int a, int b, int x, int y);

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
			if (check_cond_one(a, b, x, y) == 1)
				ft_putchar('C');
			else if ((a == 0 && b == 0) || (a == x && b == y))
				ft_putchar('A');
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

int		check_cond_one(int a, int b, int x, int y)
{
	if (((a == x && b == 0) || (a == 0 && b == y)) && (b != 0 || a != 0))
		return (1);
	else
		return (0);
}
