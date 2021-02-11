/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:59:03 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/21 18:59:03 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int			ft_count_digits(char *str);

char		*ft_findstart(char *str, int *minus);

long long	ft_power_10(int what_power);

long long	ft_atoi(char *str)
{
	long long	to_return;
	int			minus;

	to_return = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	str = ft_findstart(str, &minus);
	while (*str >= '0' && *str <= '9')
	{
		to_return = to_return * 10 + *str - '0';
		str++;
	}
	return (to_return * minus);
}

int			ft_count_digits(char *str)
{
	int	digits;

	digits = 0;
	while (*str >= '0' && *str <= '9')
	{
		digits++;
		str++;
	}
	return (digits);
}

long long	ft_power_10(int what_power)
{
	long long	powered_num;

	powered_num = 1;
	while (what_power-- > 0)
	{
		powered_num *= 10;
	}
	return (powered_num);
}

char		*ft_findstart(char *str, int *minus)
{
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus = -*minus;
		str++;
	}
	return (str);
}
