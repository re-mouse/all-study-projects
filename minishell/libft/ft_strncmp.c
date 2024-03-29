/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:46:24 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:40:05 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		raznica;

	raznica = 0;
	if (!s1 || !s2)
		return (-1);
	while (n-- > 0 && raznica == 0 && (*s1 || *s2))
		raznica = (unsigned char)*s1++ - (unsigned char)*s2++;
	return (raznica);
}
