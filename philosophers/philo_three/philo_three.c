/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 00:51:57 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 15:46:15 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*checkdie(void *philopointer)
{
	t_philo *philo;

	philo = philopointer;
	while (g_allalive)
	{
		if ((getpassedms() - philo->lasteattime) > g_timedie)
		{
			sem_wait(g_dieprint);
			sem_wait(g_writesemaph);
			g_allalive = 0;
			ft_putnbr_fd(getpassedms(), 1);
			write(1, " ", 1);
			ft_putnbr_fd(philo->num + 1, 1);
			write(1, " ", 1);
			ft_putstr_fd("died\n", 1);
			sem_post(g_eatenphilos);
			sem_post(g_writesemaph);
			sem_post(g_die);
			break ;
		}
	}
	return (NULL);
}

void	philohaveforks(t_philo *philo)
{
	philo->eating = 1;
	outputphilostat(philo->num, "is eating");
	philo->lasteattime = getpassedms();
	philo->eatentimes++;
	if (g_eatflag && philo->eatentimes == g_numbertimes)
		sem_post(g_eatenphilos);
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

void	philolife(t_philo *philo)
{
	while (1)
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
	exit(0);
}

void	createsemaph(void)
{
	if (g_eatflag)
	{
		sem_unlink("eatcheck");
		g_eatenphilos = sem_open("eatcheck", O_CREAT, 0777, g_philoquantity);
	}
	sem_unlink("forks");
	g_forks = sem_open("forks", O_CREAT, 0777, g_philoquantity);
	sem_unlink("diecheck");
	g_die = sem_open("diecheck", O_CREAT, 0777, 1);
	sem_unlink("dieprint");
	g_dieprint = sem_open("dieprint", O_CREAT, 0777, 1);
	sem_wait(g_die);
	g_philoarray = malloc(sizeof(t_philo) * g_philoquantity);
	sem_unlink("write");
	g_writesemaph = sem_open("write", O_CREAT, 0777, 1);
	sem_unlink("officiant");
	g_officiantsem = sem_open("officiant", O_CREAT, 0777, 1);
}

int		main(int argc, char **argv)
{
	int				i;

	g_eatflag = 0;
	if (philosopherparse(argc, argv))
		return (1);
	g_dieprinted = 0;
	g_takenforks = 0;
	gettimeofday(&g_starttime, NULL);
	createsemaph();
	i = -1;
	while (++i < g_philoquantity)
		createphilo(&g_philoarray[i], i);
	if (g_eatflag)
		checkeatedtimes();
	waitpid(0, NULL, 0);
}
