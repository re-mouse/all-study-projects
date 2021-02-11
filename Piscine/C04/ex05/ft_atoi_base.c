/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:59:29 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/22 19:59:30 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

int	ft_strncmp(char *s1, char *s2, unsigned int n, int mode);

int	g_int(char num);

int	get_int_base(int base_int, char *str, int size, int minus);

int	ft_power(int nb, int power);

int	ft_atoi_base(char *str, char *base)
{
	int minus;
	int n;

	n = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (ft_strncmp(str + n, base, 0, 2) == 1)
		n++;
	if (!ft_strncmp(base, "0123456789ABCDEF", 16, 1))
		return (get_int_base(16, str, n - 1, minus));
	if (!ft_strncmp(base, "poneyvif", 8, 1))
		return (get_int_base(8, str, n - 1, minus));
	if (!ft_strncmp(base, "01", 2, 1))
		return (get_int_base(2, str, n - 1, minus));
	if (!ft_strncmp(base, "0123456789", 10, 1))
		return (get_int_base(10, str, n - 1, minus));
	else
		return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n, int mode)
{
	int	raznica;

	raznica = 0;
	if (mode == 1)
		while (n > 0 && raznica == 0)
		{
			raznica = *s1 - *s2;
			s1++;
			s2++;
			n--;
		}
	if (mode == 2)
	{
		if (!ft_strncmp(s2, "poneyvif", 17, 1))
			return (ft_strncmp(s1, "01234567", 0, 2));
		while (*s2 != 0)
		{
			if (*s1 == *s2)
				return (1);
			s2++;
		}
	}
	return (raznica);
}

int	get_int_base(int base_int, char *str, int size, int minus)
{
	int to_return;
	int i;

	to_return = 0;
	i = 0;
	while (i <= size)
	{
		to_return += ft_power(base_int, i) * g_int(*(str + (size - i)));
		i++;
	}
	return (to_return * minus);
}

int	g_int(char num)
{
	int to_return;

	to_return = 0;
	if (ft_strncmp(&num, "0123456789", 0, 2))
	{
		to_return = num - '0';
	}
	if (ft_strncmp(&num, "ABCDEF", 0, 2))
	{
		to_return = num - 'A' + 10;
	}
	return (to_return);
}

int	ft_power(int nb, int power)
{
	int to_return;

	to_return = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
		to_return *= nb;
	return (to_return);
}
