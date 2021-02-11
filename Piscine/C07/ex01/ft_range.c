/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:47:15 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/25 18:47:16 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int n;
	int i;
	int *to_return;

	i = 0;
	n = 0;
	if (min >= max)
		return (NULL);
	while (min + n < max)
		n++;
	to_return = malloc(n * sizeof(int) + 1);
	while (i < n)
	{
		to_return[i] = min + i;
		i++;
	}
	return (to_return);
}
