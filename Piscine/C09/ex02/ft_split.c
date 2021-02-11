/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:04:08 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/27 22:04:08 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strwithsep(char *str, char *sep, int mode);

int		getwords(char *str, char *charset);

int		issep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int		getlength(char *str, char *sep)
{
	int i;

	i = 0;
	while (issep(*str, sep) == 0 && *str)
	{
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**to_return;
	int		i;

	i = 0;
	to_return = malloc(sizeof(char*) * (getwords(str, charset) + 1));
	if (to_return == NULL)
		return (NULL);
	while (*str)
	{
		while (issep(*str, charset) && *str)
			str++;
		if (issep(*str, charset) == 0 && *str)
		{
			to_return[i] = strwithsep(str, charset, 0);
			if (to_return[i] == NULL)
				return (NULL);
			while (issep(*str, charset) == 0 && *str)
				str++;
		}
		i++;
	}
	to_return[i] = strwithsep(to_return[1], charset, 2);
	if (to_return[i] == NULL)
		return (NULL);
	return (to_return);
}

char	*strwithsep(char *str, char *sep, int mode)
{
	char *to_return;
	char *temp;

	if (mode == 2)
	{
		to_return = malloc(1);
		*to_return = 0;
		return (to_return);
	}
	to_return = malloc(sizeof(char) * getlength(str, sep) + 1);
	if (to_return == NULL)
		return (NULL);
	temp = to_return;
	while (issep(*str, sep) == 0 && *str)
	{
		*to_return = *str;
		to_return++;
		str++;
	}
	*to_return = 0;
	return (temp);
}

int		getwords(char *str, char *charset)
{
	int n;

	n = 0;
	while (*str)
	{
		while (issep(*str, charset) && *str)
			str++;
		if (issep(*str, charset) == 0 && *str)
			n++;
		while (issep(*str, charset) == 0 && *str)
			str++;
	}
	return (n);
}
