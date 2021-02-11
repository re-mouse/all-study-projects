/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:08:52 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:08:53 by hleilani         ###   ########.fr       */
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

int		ft_str_is_printable(char *str);

int		ft_str_is_printable(char *str)
{
	int		length;
	char	c;

	length = ft_strlen(str);
	while (length > 0)
	{
		c = *str;
		if (!(c >= 32 && c <= 126))
		{
			return (0);
		}
		str++;
		length--;
	}
	return (1);
}
