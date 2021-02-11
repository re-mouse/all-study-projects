/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:17:00 by mlorette          #+#    #+#             */
/*   Updated: 2020/10/04 20:37:18 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*get_next_triad(char *str)
{
	int i;

	i = ft_mod(str);
	while (i-- > 0)
		str++;
	return (str);
}

/*
**Если остаток от 3 = 0, то возвращает 3
*/

int		ft_mod(char *str)
{
	int i;
	int needed_digits;

	i = 0;
	while (*(str++))
		i++;
	needed_digits = 0;
	if (i % 3 != 0)
		needed_digits = i % 3;
	else
		needed_digits = 3;
	return (needed_digits);
}

int		ft_mod_int(int i)
{
	int needed_digits;

	needed_digits = 0;
	if (i % 3 != 0)
		needed_digits = i % 3;
	else
		needed_digits = 3;
	return (needed_digits);
}

int		ft_get_triad_count(char *str)
{
	int	triads_count;
	int	i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	triads_count = i / 3;
	if ((i % 3) != 0)
		triads_count = triads_count + 1;
	return (triads_count);
}

char	*get_triad_by_num(char *numb, int triad)
{
	int		triads_count;
	int		i;
	int		needed_digits;
	char	*nb;

	triads_count = 0;
	i = 0;
	needed_digits = 3;
	nb = malloc(4);
	while (numb[i] != 0)
		i++;
	while (triad-- > 0)
	{
		needed_digits = ft_mod_int(i);
		nb[needed_digits] = 0;
		i = 0;
		while (needed_digits-- > 0)
		{
			nb[i] = *numb;
			i++;
			numb++;
		}
		i = 0;
	}
	return (nb);
}
