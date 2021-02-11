/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:47:55 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/28 04:51:19 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		ft_atoi(const char *str)
{
	int sign;
	int ret;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	while (*str >= '0' && *str <= '9')
		ret = ret * 10 + *str++ - '0';
	return (ret * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	int				sign;
	int				digits;
	char			character;
	unsigned int	temp;
	unsigned int	div;

	digits = 0;
	sign = n < 0 ? 1 : 0;
	temp = n < 0 ? -n : n;
	while (temp > 0 && digits++ >= 0)
		temp /= 10;
	if (sign)
		write(fd, "-", 1);
	temp = n < 0 ? -n : n;
	digits = digits > 0 ? digits : 1;
	while (digits > 0)
	{
		n = digits--;
		div = 1;
		while (--n > 0)
			div *= 10;
		character = temp / div + '0';
		temp = temp % div;
		write(fd, &character, 1);
	}
}

void	outputphilostat(int num, char *str)
{
	num++;
	sem_wait(g_writesemaph);
	if (!g_allalive)
	{
		sem_post(g_writesemaph);
		return ;
	}
	ft_putnbr_fd(getpassedms(), 1);
	write(1, " ", 1);
	ft_putnbr_fd(num, 1);
	write(1, " ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	sem_post(g_writesemaph);
}
