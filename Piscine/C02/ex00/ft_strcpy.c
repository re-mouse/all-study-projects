/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:07:57 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:07:58 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

char	*ft_strcpy(char *dest, char *src);

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

char	*ft_strcpy(char *dest, char *src)
{
	int length;
	int i;

	length = ft_strlen(src) + 1;
	while (i < length)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
