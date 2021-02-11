/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:08:46 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/30 23:08:47 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2);

void	ft_sort_string_tab(char **tab)
{
	int		a;
	int		size;
	char	*temp;
	int		i;

	i = -1;
	size = 0;
	if (tab == 0 || *tab == 0)
		return ;
	while (tab[size + 1] != 0)
		size++;
	while (i++ <= size)
	{
		a = i + 1;
		while (a <= size)
		{
			if (ft_strcmp(tab[i], tab[a]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[a];
				tab[a] = temp;
			}
			a++;
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
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
