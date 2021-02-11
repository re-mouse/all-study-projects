/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:47:53 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/29 13:58:45 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				num;
	int				lasteattime;
	pthread_t		philthread;
	int				eating;
	int				eatentimes;
	pthread_t		eatchecker;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}				t_philo;

pthread_mutex_t	g_eattimesmutex;
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
pthread_mutex_t	g_writeavability;
pthread_mutex_t	g_oficant;

void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
size_t			ft_strlen(const char *s);
void			outputphilostat(int num, char *str);
int				ft_atoi(const char *str);
void			unlockallforks(void);
int				philosopherparse(int argc, char **argv);
int				getpassedms(void);
void			eatchecker(void);
void			waitsleep(int ms);

#endif
