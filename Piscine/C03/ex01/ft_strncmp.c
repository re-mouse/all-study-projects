/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:30:33 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/20 19:30:34 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	a;
	unsigned char	b;
	int				raznica;

	raznica = 0;
	a = (unsigned char)*s1;
	b = (unsigned char)*s2;
	while (n > 0 && raznica == 0)
	{
		a = (unsigned char)*s1;
		b = (unsigned char)*s2;
		raznica = a - b;
		s1++;
		s2++;
		n--;
	}
	return (raznica);
}
