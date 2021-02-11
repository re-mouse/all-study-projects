/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:21:16 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 17:19:27 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_typenum(char t)
{
	if (t == 'd' || t == 'i' || t == 'u' || t == 'p' || t == 'x' || t == 'X')
		return (1);
	return (0);
}

int	ft_widthempty_flag(t_param par, char *str, int len, size_t *fin_str)
{
	int		len_diff;
	char	t;

	t = par.type;
	len_diff = par.width - len;
	while (len_diff-- > 0 && ++(*fin_str) >= 0)
		write(1, " ", 1);
	if ((t == 'i' || t == 'd') && par.sign)
		write(1, "-", 1);
	write(1, str, len - par.sign);
	return (*fin_str);
}

int	ft_widthzero_flag(t_param par, char *str, int len, size_t *fin_str)
{
	int		len_dif;

	len_dif = par.width - len;
	if (par.flags != '0')
		return (0);
	if (ft_is_typenum(par.type) && par.precision < 2147483647)
	{
		while (len_dif-- && ++(*fin_str) >= 0)
			write(1, " ", 1);
		if ((par.type == 'i' || par.type == 'd') && par.sign)
			write(1, "-", 1);
		write(1, str, len - par.sign);
	}
	else
	{
		if ((par.type == 'i' || par.type == 'd') && par.sign)
			write(1, "-", 1);
		while (len_dif-- && ++(*fin_str) && (*str != '%' || !par.min))
			write(1, "0", 1);
		write(1, str, len - par.sign);
	}
	return (1);
}

int	ft_widthminus_flag(t_param par, char *str, int len, size_t *fin_str)
{
	int		len_diff;
	char	t;

	t = par.type;
	len_diff = par.width - len;
	if (par.flags == '-' || (*str == '%' && par.min) || par.min)
	{
		if ((t == 'i' || t == 'd') && par.sign)
			write(1, "-", 1);
		write(1, str, len - par.sign);
		while (len_diff-- > 0 && ++(*fin_str) >= 0)
			write(1, " ", 1);
		return (1);
	}
	return (0);
}

int	ft_print_final_str(t_param par, char *str)
{
	size_t	fin_str;
	size_t	len;
	char	t;

	t = par.type;
	len = ft_strlen(str) == 0 && t == 'c' ? 1 : ft_strlen(str) + par.sign;
	fin_str = len;
	if (par.width > len)
	{
		if (ft_widthminus_flag(par, str, len, &fin_str))
			return (fin_str);
		else if (ft_widthzero_flag(par, str, len, &fin_str))
			return (fin_str);
		else
			return (ft_widthempty_flag(par, str, len, &fin_str));
	}
	else
	{
		if ((t == 'i' || t == 'd') && par.sign)
			write(1, "-", 1);
		write(1, str, len - par.sign);
	}
	return (fin_str);
}
