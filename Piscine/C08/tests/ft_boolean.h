/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:52:32 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/26 15:52:33 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>
# define ODD_MSG "I have an odd number of arguments."
# define EVEN_MSG "I have an even number of arguments."
# define SUCCESS 0

typedef int	t_bool;
# define TRUE 1
# define FALSE 0
# define EVEN(x) !(x % 2)
#endif
