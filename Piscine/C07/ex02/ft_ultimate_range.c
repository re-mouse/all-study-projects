/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:47:29 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/25 18:47:29 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int n;
	int i;
	int *array;

	n = 0;
	while (min + n < max)
		n++;
	*range = malloc(sizeof(int) * n);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (range == NULL || *range == NULL)
		return (-1);
	array = *range;
	i = 0;
	while (i < n)
	{
		array[i] = min + i;
		i++;
	}
	return (n);
}
