/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 20:40:12 by hleilani          #+#    #+#             */
/*   Updated: 2020/10/04 22:00:41 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	error_output(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	check_arg(char *arg)
{
	while (*arg)
	{
		if (*arg < '0' || *arg > '9')
			return (-1);
		arg++;
	}
	return (1);
}

int	is_zero(char *arg)
{
	while (*arg)
	{
		if (*arg != '0')
			return (0);
		arg++;
	}
	return (1);
}

int	checks(char *str, char *namefile)
{
	if (check_arg(str) == -1)
		return (error_output());
	if (get_value(namefile, ":") == -1)
	{
		write(2, "Dict Error", 10);
		return (1);
	}
	if (is_zero(str) == 1)
	{
		get_value(namefile, "0");
		write(1, "\n", 1);
		return (0);
	}
	if (ft_split_by_key(str, namefile) != 1)
		write(2, "Dict Error", 10);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	char *namefile;
	char *str;

	namefile = "numbers.dict";
	str = argv[1];
	if (argc == 3)
	{
		namefile = argv[1];
		str = argv[2];
	}
	if (argc != 2 && argc != 3)
		return (error_output());
	return (checks(str, namefile));
}
