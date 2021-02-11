/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:08:52 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/30 23:08:53 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		a;
	int		size;
	char	*temp;
	int		i;

	i = -1;
	size = 0;
	while (tab[size + 1] != 0)
		size++;
	while (i++ <= size)
	{
		a = i + 1;
		while (a <= size)
		{
			if (cmp(tab[i], tab[a]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[a];
				tab[a] = temp;
			}
			a++;
		}
	}
}
