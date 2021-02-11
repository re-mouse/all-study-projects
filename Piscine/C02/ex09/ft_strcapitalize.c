/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:09:14 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:09:15 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

char	*ft_strcapitalize(char *str);

void	ft_strupcase(char *c);

void	ft_strlowcase(char *c);

int		check_char(char *c, int l_count);

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*str != 0)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strcapitalize(char *str)
{
	int		length;
	int		i;
	char	l_count;
	char	*a;

	a = str;
	i = 0;
	l_count = 0;
	while (i < ft_strlen(a))
	{
		l_count = check_char(str, l_count);
		str++;
		i++;
	}
	return (a);
}

void	ft_strupcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}

void	ft_strlowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
	{
		*c += 32;
	}
}

int		check_char(char *c, int l_count)
{
	if ((*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z'))
	{
		if (l_count != -1)
		{
			l_count++;
			if (l_count == 1)
				ft_strupcase(c);
			else
				ft_strlowcase(c);
		}
	}
	else
	{
		if (*c >= '0' && *c <= '9')
			l_count = -1;
		else
			l_count = 0;
	}
	return (l_count);
}
