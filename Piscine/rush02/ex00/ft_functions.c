/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:40:28 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/04 21:02:17 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

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

int		cm(char *s1, char *s2)
{
	int				raznica;
	unsigned char	a;
	unsigned char	b;

	raznica = 0;
	a = (unsigned char)*s1;
	b = (unsigned char)*s2;
	while ((b != 0 || a != 0) && raznica == 0)
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		raznica = a - b;
		s1++;
		s2++;
	}
	return (raznica);
}

void	check_space(char *str)
{
	int checker;

	checker = 0;
	str = get_next_triad(str);
	while (*str)
	{
		if (*str != '0')
			checker = 1;
		str++;
	}
	if (checker == 1)
		write(1, ", ", 2);
}
