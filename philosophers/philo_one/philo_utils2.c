/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:55:06 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:00:16 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	eatchecker(void)
{
	int	i;
	int	flag;

	pthread_mutex_lock(&g_eattimesmutex);
	flag = 0;
	i = -1;
	while (++i < g_philoquantity)
	{
		if (g_philoarray[i].eatentimes < g_numbertimes)
		{
			flag = 1;
			continue ;
		}
	}
	if (flag)
	{
		pthread_mutex_unlock(&g_eattimesmutex);
		return ;
	}
	pthread_mutex_lock(&g_writeavability);
	g_allalive = 0;
	pthread_mutex_unlock(&g_writeavability);
	pthread_mutex_unlock(&g_eattimesmutex);
}

void	waitsleep(int ms)
{
	int start;
	int point;

	start = getpassedms();
	point = start + ms;
	while (point > getpassedms())
	{
		usleep(100);
	}
}

void	unlockallforks(void)
{
	int i;

	i = -1;
	while (++i < g_philoquantity)
		pthread_mutex_unlock(g_philoarray[i].right);
}
