/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_funcs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:29:36 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 23:45:58 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_FUNCS_H
# define BUILTIN_FUNCS_H

# include "../libft/libft.h"
# include "minishell.h"
# include <unistd.h>
# include <errno.h>
# include <string.h>

int					ft_pwd(t_list *order);
int					check_str_for_export(char *str);
char				**add_new_el(int newsize, char *new_el);
int					find_count_of_strs(char **env);
int					export(t_command *new, t_list *order);
void				ft_sort(char **mass, int size);
int					check_el_in_env(char **new_el, int exp_or_env);
int					unset(t_command *del, t_list *order);
int					ft_cd(t_command *cmd, t_list *order);
int					ft_exit(t_command *tmp, t_list *order);
int					change_el_in_env(char *change_el, int ind);
int					print_env(int env_size, int sort_or_not, int output);
int					ft_env(t_command *n, t_list *order);
char				**free_mass1(char ***tab);
char				**copy_of_env(char **env, int flag);
void				free_two_par(char **buf, t_list **order);
void				put_path(char **tmp, int i);
int					ft_echo(t_command *list, t_list *order);
void				print_env1(int i, int output);
void				print_env2(int *i, int *j, int *flag, int output);
int					change_env_inprint(char ***copy);
void				print_exp1(int *i, int *j, int *flag, int output);
int					print_env(int env_size, int sort_or_not, int output);
int					check_el_in_env(char **new_el, int exp_or_env);
void				change_new_el(char **new_el, int exp_or_env, int *j);
void				ft_sort(char **ar, int size);
char				**add_new_el(int newsize, char *new_el);
char				**free_mass1(char ***tab);
int					find_count_of_strs(char **env);
char				**copy_of_env(char **env, int flag);
int					is_abs_path(char *str);
void				free_path_math(char **paths_mass);
void				free_in_get_path_mass(char ***mass,
							char **tmp, char ***ret);
#endif
