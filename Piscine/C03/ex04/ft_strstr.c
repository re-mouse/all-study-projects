/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:56:30 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 20:56:31 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find);

char	*check(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	char	*temp;

	while (*str != 0)
	{
		if (*str == *to_find)
		{
			temp = check(str, to_find);
			if (temp != 0)
				return (temp);
		}
		str++;
	}
	return (0);
}

char	*check(char *str, char *to_find)
{
	char	*str_temp;
	char	*temp;
	int		a;

	a = 0;
	str_temp = str;
	temp = to_find;
	a = 1;
	while (*temp != 0)
	{
		if (*str != *temp)
		{
			a = 0;
			break ;
		}
		str++;
		temp++;
	}
	if (a != 0)
		return (str_temp);
	else
		return (0);
}
