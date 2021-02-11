/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 00:52:10 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 14:15:04 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				num;
	int				lasteattime;
	pthread_t		philthread;
	int				eating;
	int				eatentimes;
	pthread_t		eatchecker;
	pthread_t		diecatcher;
}				t_philo;

sem_t			*g_eatenphilos;
int				g_dieprinted;
sem_t			*g_dieprint;
sem_t			*g_die;
sem_t			*g_forks;
sem_t			*g_writesemaph;
sem_t			*g_officiantsem;
int				g_eatflag;
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
void			createphilo(t_philo *philo, int num);
void			*checkdie(void *philopointer);
void			philolife(t_philo *philo);
int				wanttakefork(void);
void			*catchotherdies(void *philopointer);
int				philosopherparse(int argc, char **argv);
int				getpassedms();
void			waitsleep(int ms);
void			checkeatedtimes(void);

#endif
