/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 00:52:10 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:10:51 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				num;
	int				lasteattime;
	pthread_t		philthread;
	int				eatentimes;
	int				eating;
	pthread_t		eatchecker;
}				t_philo;

int				g_eatflag;
sem_t			*g_eattimesem;
sem_t			*g_forks;
sem_t			*g_writesemaph;
sem_t			*g_officiantsem;
int				g_numbertimes;
int				g_takenforks;
int				g_allalive;
int				g_eattime;
int				g_timedie;
int				g_sleeptime;
int				g_philoquantity;
t_philo			*g_philoarray;
struct timeval	g_starttime;

void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);
void			outputphilostat(int num, char *str);
int				ft_atoi(const char *str);
void			unlockallforks(void);
int				philosopherparse(int argc, char **argv);
int				getpassedms();
void			waitsleep(int ms);
void			eatchecker(void);
int				wanttakefork(void);

#endif
