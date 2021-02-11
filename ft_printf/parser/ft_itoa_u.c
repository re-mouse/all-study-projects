/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:55:28 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 11:27:14 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_u(unsigned int n)
{
	char			*ret;
	int				d;
	unsigned int	temp;

	d = 0;
	temp = n;
	while (temp > 0 && d++ >= 0)
		temp /= 10;
	d = d > 0 ? d : 1;
	if ((ret = malloc(d + 1)) == NULL)
		return (NULL);
	ret[d--] = 0;
	d = d < 0 ? 0 : d;
	temp = n;
	while (d >= 0)
	{
		ret[d--] = temp % 10 + '0';
		temp /= 10;
	}
	return (ret);
}
