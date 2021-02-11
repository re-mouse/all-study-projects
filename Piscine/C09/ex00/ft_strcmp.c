/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:30:28 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 19:30:29 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);

int	ft_strcmp(char *s1, char *s2)
{
	int				raznica;
	unsigned char	a;
	unsigned char	b;

	raznica = 0;
	a = (unsigned char)*s1;
	b = (unsigned char)*s2;
	while ((b != 0 || a != 0) && raznica == 0)
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		raznica = a - b;
		s1++;
		s2++;
	}
	return (raznica);
}
