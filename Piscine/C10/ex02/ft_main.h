/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:30:34 by hleilani          #+#    #+#             */
/*   Updated: 2020/09/28 20:30:34 by hleilani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# define BUFFSIZE 1000000
# define ABS(x) (((x < 0) * -x) + ((x >= 0) * x))

int		readfile(long offset, char *filename, int ar, int i);

int		ft_strlen(char *str);

int		checkinputarg(long *offset, char **argv, int *error);

int		ft_strlen(char *str);

void	outputerror(char *programname, char *task, char *error, int mode);

void	checkinput(long offset);

long	getnum(char *str, int *errorlog);

int		returnerror(char **argv);

void	checkar(int ar, char *namefile, int i);

#endif
