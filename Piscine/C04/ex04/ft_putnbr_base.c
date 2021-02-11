/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:59:07 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/21 18:59:08 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

void	print_octal(unsigned int b);

void	print_binar(unsigned int b);

int		ft_strncmp(char *s1, char *s2, unsigned int n);

void	print_hexadecimal(unsigned int b);

void	ft_putnbr_base(int nbr, char *base)
{
	char			a[100];
	int				i;
	unsigned int	nmbr;

	i = 0;
	if (nbr < 0)
		write(1, "-", 1);
	nmbr = (unsigned)nbr;
	if (!ft_strncmp(base, "0123456789ABCDEF", 17))
		print_hexadecimal(nmbr);
	if (!ft_strncmp(base, "poneyvif", 17))
		print_octal(nmbr);
	if (!ft_strncmp(base, "01", 17))
		print_binar(nmbr);
	if (!ft_strncmp(base, "0123456789", 17))
		while (nmbr > 0 || i == 0)
		{
			a[i] = nmbr % 10 + '0';
			nmbr /= 10;
			i++;
		}
	while (i-- > 0)
		write(1, &a[i], 1);
}

void	print_hexadecimal(unsigned int b)
{
	char	print_c[100];
	int		mod;
	int		i;

	i = 0;
	while (b != 0 || i == 0)
	{
		mod = b % 16;
		b /= 16;
		if (mod < 10)
			print_c[i] = '0' + mod;
		else
			print_c[i] = 'A' + mod - 10;
		i++;
	}
	while (i-- > 0)
		write(1, &print_c[i], 1);
}

void	print_octal(unsigned int b)
{
	char	print_c[100];
	int		mod;
	int		i;

	i = 0;
	while (b != 0 || i == 0)
	{
		mod = b % 8;
		b /= 8;
		print_c[i] = '0' + mod;
		i++;
	}
	while (i-- > 0)
		write(1, &print_c[i], 1);
}

void	print_binar(unsigned int b)
{
	char	print_c[100];
	int		mod;
	int		i;

	i = 0;
	while (b != 0 || i == 0)
	{
		mod = b % 2;
		b /= 2;
		print_c[i] = '0' + mod;
		i++;
	}
	while (i-- > 0)
		write(1, &print_c[i], 1);
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				raznica;

	raznica = 0;
	while (n > 0 && raznica == 0)
	{
		raznica = *s1 - *s2;
		s1++;
		s2++;
		n--;
	}
	return (raznica);
}
