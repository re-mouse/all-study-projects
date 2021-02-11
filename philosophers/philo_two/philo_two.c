/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 00:51:57 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:11:32 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	*checkdie(void *philopointer)
{
	t_philo *philo;

	philo = philopointer;
	while (g_allalive)
	{
		if ((getpassedms() - philo->lasteattime) > g_timedie)
		{
			sem_wait(g_writesemaph);
			if (!g_allalive)
			{
				sem_post(g_writesemaph);
				break ;
			}
			g_allalive = 0;
			ft_putnbr_fd(getpassedms(), 1);
			write(1, " ", 1);
			ft_putnbr_fd(philo->num + 1, 1);
			write(1, " ", 1);
			ft_putstr_fd("died\n", 1);
			sem_post(g_writesemaph);
		}
	}
	pthread_detach(philo->eatchecker);
	return (NULL);
}

void	philohaveforks(t_philo *philo)
{
	philo->eating = 1;
	outputphilostat(philo->num, "is eating");
	philo->eatentimes++;
	philo->lasteattime = getpassedms();
	if (g_eatflag)
		eatchecker();
	waitsleep(g_eattime);
	sem_post(g_forks);
	g_takenforks--;
	sem_post(g_forks);
	g_takenforks--;
	philo->eating = 0;
	outputphilostat(philo->num, "is sleeping");
	waitsleep(g_sleeptime);
	outputphilostat(philo->num, "is thinking");
}

void	*philolife(void *philopointer)
{
	t_philo *philo;

	philo = philopointer;
	while (g_allalive)
	{
		if (wanttakefork())
			sem_wait(g_forks);
		else
			continue ;
		outputphilostat(philo->num, "has taken a fork");
		sem_wait(g_forks);
		g_takenforks++;
		outputphilostat(philo->num, "has taken a fork");
		philohaveforks(philo);
	}
	return (NULL);
}

void	createphilo(t_philo *philo, int num)
{
	philo->num = num;
	philo->lasteattime = getpassedms();
	philo->eating = 0;
	philo->eatentimes = 0;
	pthread_create(&philo->eatchecker, NULL, checkdie, (void *)philo);
	pthread_create(&philo->philthread, NULL, philolife, (void *)philo);
}

int		main(int argc, char **argv)
{
	int				i;

	g_eatflag = 0;
	if (philosopherparse(argc, argv))
		return (1);
	g_takenforks = 0;
	sem_unlink("eat");
	g_eattimesem = sem_open("eat", O_CREAT, 0777, 1);
	sem_unlink("forks");
	g_forks = sem_open("forks", O_CREAT, 0777, g_philoquantity);
	g_philoarray = malloc(sizeof(t_philo) * g_philoquantity);
	i = -1;
	sem_unlink("write");
	g_writesemaph = sem_open("write", O_CREAT, 0777, 1);
	sem_unlink("officiant");
	g_officiantsem = sem_open("officiant", O_CREAT, 0777, 1);
	gettimeofday(&g_starttime, NULL);
	while (++i < g_philoquantity)
		createphilo(&g_philoarray[i], i);
	i = -1;
	while (++i < g_philoquantity)
		pthread_join(g_philoarray[i].philthread, NULL);
	sem_close(g_forks);
	sem_close(g_writesemaph);
	sem_close(g_officiantsem);
}
