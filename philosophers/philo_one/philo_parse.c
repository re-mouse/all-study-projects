/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:47:58 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/28 16:40:36 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	getpassedms(void)
{
	struct timeval	time;
	int				milisecs;

	gettimeofday(&time, NULL);
	milisecs = (time.tv_sec - g_starttime.tv_sec) * 1000;
	milisecs += (time.tv_usec - g_starttime.tv_usec) / 1000;
	return (milisecs);
}

int	isalldigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	philosopherparse(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Wrong args\n", 2);
		return (-1);
	}
	while (++i < argc)
		if (!isalldigit(argv[i]))
		{
			ft_putstr_fd("Wrong args\n", 2);
			return (-1);
		}
	g_allalive = 1;
	g_philoquantity = ft_atoi(argv[1]);
	g_timedie = ft_atoi(argv[2]);
	g_eattime = ft_atoi(argv[3]);
	g_sleeptime = ft_atoi(argv[4]);
	if (argc == 6)
	{
		g_eatflag = 1;
		g_numbertimes = ft_atoi(argv[5]);
	}
	return (0);
}
