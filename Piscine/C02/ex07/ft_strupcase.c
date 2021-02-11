/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:09:00 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:09:01 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

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

char	*ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	int		length;
	int		i;
	char	c;
	char	*a;

	a = str;
	i = 0;
	length = ft_strlen(a);
	while (i < length)
	{
		c = *str;
		if (c >= 'a' && c <= 'z')
		{
			*str -= 32;
		}
		str++;
		i++;
	}
	return (a);
}
