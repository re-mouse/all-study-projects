/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:49:18 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/25 18:49:19 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*saveupd(char *crntstr, char *save, char *sep, int i);

int		count_symbols(char **strs, char *sep, int size);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*crntstr;
	char	*temp;
	char	*save;
	int		i;
	int		mode;

	i = 0;
	save = malloc(sizeof(char) * count_symbols(strs, sep, size) + 1);
	temp = save;
	while (i < size)
	{
		crntstr = strs[i];
		mode = 0;
		if (i != size - 1)
			mode = 1;
		save = saveupd(crntstr, save, sep, mode);
		i++;
	}
	return (temp);
}

char	*saveupd(char *crntstr, char *save, char *sep, int i)
{
	int j;

	j = 0;
	while (*crntstr != 0)
	{
		*save = *crntstr;
		crntstr++;
		save++;
	}
	j = 0;
	while (*(sep + j) != 0 && i != 0)
	{
		*save = *(sep + j);
		save++;
		j++;
	}
	return (save);
}

int		count_symbols(char **strs, char *sep, int size)
{
	char	*currentsymb;
	int		n;
	int		i;
	int		sepn;

	sepn = 0;
	i = 0;
	n = 0;
	while (i < size)
	{
		currentsymb = strs[i];
		while (*currentsymb != 0)
		{
			currentsymb++;
			n++;
		}
		i++;
	}
	while (*(sep + sepn) != 0)
		sepn++;
	n += sepn * (size - 1);
	return (n);
}
