/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 21:54:00 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 21:54:01 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int				ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int i_a;
	unsigned int to_return;

	i = 0;
	i_a = 0;
	while (*(dest + i) != 0)
		i++;
	i_a = (unsigned)ft_strlen(src);
	to_return = i + i_a;
	while (i < size - 1 && *src != 0)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = 0;
	return (to_return);
}

int				ft_strlen(char *str)
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
