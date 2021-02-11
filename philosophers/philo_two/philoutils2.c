/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:09:54 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:10:36 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	eatchecker(void)
{
	int	i;
	int	flag;

	sem_wait(g_eattimesem);
	flag = 0;
	i = -1;
	while (++i < g_philoquantity)
	{
		if (g_philoarray[i].eatentimes < g_numbertimes)
		{
			flag = i;
			continue ;
		}
	}
	if (flag)
	{
		sem_post(g_eattimesem);
		return ;
	}
	sem_wait(g_writesemaph);
	g_allalive = 0;
	sem_post(g_writesemaph);
	sem_post(g_eattimesem);
}

int		wanttakefork(void)
{
	int retcode;

	sem_wait(g_officiantsem);
	retcode = 0;
	if (g_takenforks < g_philoquantity - 1)
	{
		g_takenforks++;
		retcode = 1;
	}
	sem_post(g_officiantsem);
	return (retcode);
}
