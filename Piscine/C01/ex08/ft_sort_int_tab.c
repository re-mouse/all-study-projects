/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 05:07:15 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/19 05:07:24 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tabs(int *tab, int size);

void	check_element(int *int_point, int a_offs, int b_offs);

void	ft_sort_int_tabs(int *tab, int size)
{
	int i;
	int a;

	i = 0;
	while (i < size)
	{
		a = i + 1;
		while (a < size)
		{
			check_element(tab, a, i);
			a++;
		}
		i++;
	}
}

void	check_element(int *int_point, int a_offs, int b_offs)
{
	int temp;

	if (*(int_point + a_offs) < *(int_point + b_offs))
	{
		temp = *(int_point + a_offs);
		*(int_point + a_offs) = *(int_point + b_offs);
		*(int_point + b_offs) = temp;
	}
}
