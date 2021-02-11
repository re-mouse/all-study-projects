/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:43:40 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/24 14:43:43 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	argc--;
	while (argc > 0)
	{
		while (*argv[argc] != 0)
		{
			write(1, argv[argc], 1);
			argv[argc]++;
		}
		write(1, "\n", 1);
		argc--;
	}
}
