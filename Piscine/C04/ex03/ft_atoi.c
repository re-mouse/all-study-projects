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

int	ft_atoi(char *str);

int		count_digits(char *str);

char	*findstart(char *str, int *minus);

int		power_10(int charge);

int		ft_atoi(char *str)
{
	int		n;
	int		to_return;
	int		minus;

	to_return = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	str = findstart(str, &minus);
	n = count_digits(str);
	while (*str >= '0' && *str <= '9')
	{
		to_return += power_10(n - 1) * (*str - '0');
		str++;
		n--;
	}
	return (to_return * minus);
}

int		count_digits(char *str)
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

int		power_10(int what_power)
{
	int powered_num;

	powered_num = 1;
	while (what_power-- > 0)
	{
		powered_num *= 10;
	}
	return (powered_num);
}

char	*findstart(char *str, int *minus)
{
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*minus = -*minus;
		str++;
	}
	return (str);
}
