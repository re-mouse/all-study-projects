/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:02:55 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:00:07 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*checkdie(void *philopointer)
{
	t_philo *philo;

	philo = philopointer;
	while (g_allalive)
	{
		if (g_allalive && (getpassedms() - philo->lasteattime) > g_timedie)
		{
			pthread_mutex_lock(&g_writeavability);
			if (!g_allalive)
			{
				pthread_mutex_unlock(&g_writeavability);
				break ;
			}
			g_allalive = 0;
			ft_putnbr_fd(getpassedms(), 1);
			write(1, " ", 1);
			ft_putnbr_fd(philo->num + 1, 1);
			write(1, " ", 1);
			ft_putstr_fd("died\n", 1);
			pthread_mutex_unlock(&g_writeavability);
		}
	}
	pthread_detach(philo->eatchecker);
	unlockallforks();
	return (NULL);
}

void	philohaveforks(t_philo *philo)
{
	philo->eating = 1;
	outputphilostat(philo->num, "is eating");
	philo->eatentimes++;
	if (g_eatflag)
		eatchecker();
	philo->lasteattime = getpassedms();
	waitsleep(g_eattime);
	pthread_mutex_unlock(philo->left);
	g_takenforks--;
	pthread_mutex_unlock(philo->right);
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
		if (philo->num % 2)
		{
			pthread_mutex_lock(philo->left);
			outputphilostat(philo->num, "has taken a fork");
			pthread_mutex_lock(philo->right);
			outputphilostat(philo->num, "has taken a fork");
		}
		else
		{
			pthread_mutex_lock(philo->right);
			outputphilostat(philo->num, "has taken a fork");
			pthread_mutex_lock(philo->left);
			outputphilostat(philo->num, "has taken a fork");
		}
		g_takenforks++;
		philohaveforks(philo);
	}
	return (NULL);
}

void	createphilo(t_philo *philo, int num)
{
	if (num == 0)
	{
		philo->left = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->left, NULL);
	}
	else
		philo->left = g_philoarray[num - 1].right;
	if (num != g_philoquantity - 1)
	{
		philo->right = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->right, NULL);
	}
	else
		philo->right = g_philoarray[0].left;
	philo->num = num;
	philo->lasteattime = getpassedms();
	pthread_create(&philo->eatchecker, NULL, checkdie, (void *)philo);
	pthread_create(&philo->philthread, NULL, philolife, (void *)philo);
}

int		main(int argc, char **argv)
{
	int i;

	g_eatflag = 0;
	if (philosopherparse(argc, argv))
		return (1);
	g_takenforks = 0;
	pthread_mutex_init(&g_oficant, NULL);
	pthread_mutex_init(&g_eattimesmutex, NULL);
	g_philoarray = malloc(sizeof(t_philo) * g_philoquantity);
	i = -1;
	pthread_mutex_init(&g_writeavability, NULL);
	gettimeofday(&g_starttime, NULL);
	while (++i < g_philoquantity)
		createphilo(&g_philoarray[i], i);
	i = -1;
	while (++i < g_philoquantity)
		pthread_join(g_philoarray[i].philthread, NULL);
}
