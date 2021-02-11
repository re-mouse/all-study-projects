/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:31:46 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 23:32:52 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atol(char *str)
{
	unsigned long long	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + *str++ - '0';
	return (ret);
}