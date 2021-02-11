/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:46:50 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/25 18:46:51 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		n;
	char	*to_return;

	n = 0;
	while (*(src + n) != 0)
		n++;
	to_return = (char *)malloc(sizeof(char) * n + 1);
	while (*src != 0)
	{
		*to_return = *src;
		src++;
		to_return++;
	}
	*(to_return + 1) = 0;
	return (to_return - n);
}
