/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:09:53 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/17 14:28:45 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	len;

	if (!s1)
		return (malloc(0));
	len = ft_strlen(s1);
	temp = ft_calloc(len + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s1, len + 1);
	return (temp);
}
