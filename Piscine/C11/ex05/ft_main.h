/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:38:03 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/30 20:38:04 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <unistd.h>

long long	ft_div(long long a, long long b);
long long	ft_substraction(long long a, long long b);
long long	ft_mod(long long a, long long b);
long long	ft_multiply(long long a, long long b);
long long	ft_sum(long long a, long long b);
long long	ft_atoi(char *str);
void		ft_putnbr(long long nb);
int			ft_g_oper(char *operator);
int			output_error(char *error);
# define ABS(x) (((x < 0) * -x) + ((x >= 0) * x))

#endif
