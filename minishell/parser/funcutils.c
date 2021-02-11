/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:34:51 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:42:43 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_charjoin(char c, char *str)
{
	char *newstr;

	newstr = ft_calloc(ft_strlen(str) + 2, 1);
	ft_memcpy(newstr, str, ft_strlen(str));
	newstr[ft_strlen(str)] = c;
	free(str);
	return (newstr);
}

int		find_char_in_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int		find_count_of_dis(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		is_str_num(char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if ((int)ft_strlen(str) == i)
		return (1);
	return (0);
}
