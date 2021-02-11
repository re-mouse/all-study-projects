/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:47:30 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 20:47:30 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src);

char	*ft_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(dest + i) != 0)
	{
		i++;
	}
	while (*src != 0)
	{
		*(dest + i) = *src;
		src++;
		i++;
	}
	*(dest + i) = 0;
	return (dest);
}
