/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:47:36 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 20:47:37 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int i;

	i = 0;
	while (*(dest + i) != 0)
	{
		i++;
	}
	while (nb > 0)
	{
		*(dest + i) = *src;
		src++;
		i++;
		nb--;
	}
	*(dest + i) = 0;
	return (dest);
}
