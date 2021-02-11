/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:40:23 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/04 21:38:29 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

/*
**Достать из словаря значение по такому-то ключу
*/
int		get_value(char *namefile, char *key);

/*
**Получить разряд числа 2 разряд 456781 == 781, 1 разряд в 12345 = 12
*/
char	*get_triad_by_num(char *numb, int triad);

/*
**Здесь будем разбирать число полностью
*/
int		ft_split_by_key(char *st, char *fl);

/*
**Количество триад в числе
*/
int		ft_get_triad_count(char *str);

/*
**Сколько в текущей триаде чисел, в 78231 это 2, 1045 это 1, 784355 это 3
*/
int		ft_mod(char *str);

/*
**Переходит на следующую триаду
*/
char	*get_next_triad(char *str);

/*
**длина строки
*/
int		ft_strlen(char *str);

int		triad_checker(char *str, char *filename);

int		cm(char *s1, char *s2);

char	*get_triad_prefix(int triad);

void	check_space(char *str);

#endif
