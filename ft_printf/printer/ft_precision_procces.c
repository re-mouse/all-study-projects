/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_procces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:20:51 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 17:17:23 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_prec_str(char *str, size_t prec, size_t str_len)
{
	char *temp;

	temp = str;
	if (str_len > prec)
	{
		str = ft_substr(str, 0, prec);
		free(temp);
	}
	return (str);
}

char	*ft_prec_numbers(char *str, size_t prec, size_t str_len)
{
	int		diff_len;
	char	*temp;

	if (prec < 2147483647 && prec > str_len)
	{
		diff_len = prec - str_len;
		while (diff_len--)
		{
			temp = str;
			str = ft_strjoin("0", str);
			free(temp);
		}
	}
	return (str);
}

char	*ft_prec_pointer(char *str, size_t prec, size_t str_len, t_param *param)
{
	int		diff_len;
	char	*temp;

	if (param->flags == '0' && prec == 2147483647)
	{
		param->precision = param->width - 2;
		prec = param->precision;
		param->width = 0;
	}
	if (prec < 2147483647 && prec > str_len)
	{
		diff_len = prec - str_len;
		while (diff_len--)
		{
			temp = str;
			str = ft_strjoin("0", str);
			free(temp);
		}
	}
	temp = str;
	str = ft_strjoin("0x", str);
	free(temp);
	return (str);
}

int		ft_precision_pr(t_param param, char *str)
{
	size_t	prec;
	char	f;
	size_t	str_len;
	int		ret;

	f = param.type;
	prec = param.precision;
	str_len = ft_strlen(str);
	if (f == 'd' || f == 'i' || f == 'u' || f == 'x' || f == 'X')
		str = ft_prec_numbers(str, prec, str_len);
	if (f == 's')
		str = ft_prec_str(str, prec, str_len);
	if (f == 'p')
		str = ft_prec_pointer(str, prec, str_len, &param);
	ret = ft_print_final_str(param, str);
	free(str);
	return (ret);
}
