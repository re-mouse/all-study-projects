/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:21:55 by hleilani          #+#    #+#             */
/*   Updated: 2020/11/07 12:00:49 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_variable(t_param param, va_list list)
{
	if (param.type == 'c' || param.type == '%')
		return (ft_print_c(param, list));
	if (param.type == 's')
		return (ft_print_s(param, list));
	if (param.type == 'p')
		return (ft_print_p(param, list));
	if (param.type == 'd' || param.type == 'i')
		return (ft_print_i(param, list));
	if (param.type == 'u')
		return (ft_print_u(param, list));
	if (param.type == 'x')
		return (ft_print_xx(param, list));
	if (param.type == 'X')
		return (ft_print_x(param, list));
	else
		return (ft_print_c(param, list));
}

char	*ft_parse_flag(char *f, t_param *param)
{
	if (*f == '-' || *f == '0')
	{
		while (*f == '-' || *f == '0')
		{
			param->min = *f == '-' || param->min ? 1 : 0;
			param->flags = *f++ == '-' ? '-' : '0';
		}
	}
	return (f);
}

char	*ft_parse_width(char *f, t_param *param, va_list list)
{
	int	temp;

	if (ft_isdigit(*f) || *f == '*')
		while (ft_isdigit(*f) || *f == '*')
		{
			if (*f == '*')
			{
				temp = va_arg(list, int);
				if (temp < 0)
				{
					param->width = -temp;
					param->flags = '-';
				}
				else
					param->width = temp;
				f++;
			}
			else
			{
				param->width = ft_atoi(f);
				while (ft_isdigit(*f))
					f++;
			}
		}
	return (f);
}

char	*ft_parse_prec(char *f, t_param *param, va_list list)
{
	int	temp;

	if (*f == '.')
	{
		f++;
		param->precision = ft_atoi(f);
		while (ft_isdigit(*f) || *f == '*')
		{
			if (*f == '*')
			{
				temp = va_arg(list, int);
				param->precision = temp < 0 ? 2147483647 : temp;
				f++;
			}
			else
			{
				param->precision = ft_atoi(f);
				while (ft_isdigit(*f))
					f++;
			}
		}
	}
	return (f);
}

char	*ft_pars(char *f, va_list list, int *l)
{
	t_param param;

	f++;
	param.flags = 0;
	param.width = 0;
	param.precision = 2147483647;
	param.type = 0;
	param.variable = NULL;
	param.sign = 0;
	param.min = 0;
	f = ft_parse_flag(f, &param);
	f = ft_parse_width(f, &param, list);
	f = ft_parse_prec(f, &param, list);
	param.type = *f;
	*l += ft_parse_variable(param, list);
	return (f + 1);
}
