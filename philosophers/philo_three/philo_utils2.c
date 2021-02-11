/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:55:06 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:14:57 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	checkeatedtimes(void)
{
	int		i;

	i = -1;
	while (++i < g_philoquantity)
	{
		sem_wait(g_eatenphilos);
		sem_wait(g_eatenphilos);
	}
	sem_wait(g_writesemaph);
	sem_post(g_die);
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

void	createphilo(t_philo *philo, int num)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		philo->num = num;
		philo->eating = 0;
		philo->eatentimes = 0;
		philo->lasteattime = getpassedms();
		pthread_create(&philo->eatchecker, NULL, checkdie, (void *)philo);
		pthread_create(&philo->diecatcher, NULL, catchotherdies, (void *)philo);
		philolife(philo);
	}
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

void	*catchotherdies(void *philopointer)
{
	(void)philopointer;
	sem_wait(g_die);
	if (g_eatflag)
	{
		sem_post(g_eatenphilos);
	}
	sem_post(g_die);
	exit(0);
}
