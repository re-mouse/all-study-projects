/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 18:32:30 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/26 18:32:31 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					write_str(char *text, char *str, char *copy);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*to_return;
	t_stock_str	*temp;
	int			n;

	n = 0;
	to_return = malloc(sizeof(t_stock_str) * (ac + 1));
	if (to_return == NULL || ac < 0)
		return (NULL);
	temp = to_return;
	while (ac > 0)
	{
		while (*(*av + n))
			n++;
		to_return->str = malloc(n * sizeof(char));
		to_return->copy = malloc(n * sizeof(char));
		if (to_return->str == NULL || to_return->copy == NULL)
			return (NULL);
		to_return->size = n;
		n = write_str(*av, to_return->str, to_return->copy);
		av++;
		ac--;
		to_return++;
	}
	to_return->str = malloc(sizeof(char) * 1);
	to_return->str[0] = 0;
	return (temp);
}

int					write_str(char *text, char *str, char *copy)
{
	while (*text)
	{
		*str = *text;
		*copy = *text;
		str++;
		copy++;
		text++;
	}
	*str = 0;
	*copy = 0;
	return (0);
}
