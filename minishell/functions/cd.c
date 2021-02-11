/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:40:01 by welease           #+#    #+#             */
/*   Updated: 2020/12/19 22:23:41 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtin_funcs.h"
#include "../inc/minishell.h"

void	put_error(t_list *order)
{
	char	*tmp;
	int		i;

	g_status = errno;
	tmp = ft_strdup("?=1");
	i = check_el_in_env(&tmp, 1);
	change_el_in_env(tmp, i);
	free(tmp);
	ft_putendl_fd(strerror(errno), order->fd[2]);
}

void	change_old_pwd(char *old_pwd)
{
	int		i;
	char	*tmp;
	char	*buf;

	buf = ft_strdup("OLDPWD=");
	tmp = ft_strjoin("OLDPWD=", old_pwd);
	if ((i = check_el_in_env(&buf, 0)) == -1)
		g_env = add_new_el(find_count_of_strs(g_env) + 1, tmp);
	else
		change_el_in_env(tmp, i);
	free(tmp);
	free(buf);
}

void	change_pwd(char *pwd)
{
	int		i;
	char	*tmp;
	char	*buf;

	buf = ft_strdup("PWD=");
	tmp = ft_strjoin("PWD=", pwd);
	i = check_el_in_env(&buf, 0);
	change_el_in_env(tmp, i);
	free(tmp);
	free(buf);
}

void	go_home(void)
{
	int		i;
	char	*buf;
	char	*tmp;
	char	old_pwd[MAXSTRLEN];
	t_list	*order;

	order = ft_lstnew(NULL);
	order->fd[2] = 1;
	buf = ft_strdup("HOME=");
	getcwd(old_pwd, MAXSTRLEN);
	i = check_el_in_env(&buf, 0);
	if (i == -1)
	{
		change_err("?=1");
		ft_putendl_fd(strerror(errno), order->fd[2]);
		free_two_par(&buf, &order);
		return ;
	}
	put_path(&tmp, i);
	change_old_pwd(old_pwd);
	chdir(tmp) ? put_error(order) : change_err("?=0");
	getcwd(old_pwd, MAXSTRLEN);
	change_pwd(old_pwd);
	free_two_par(&buf, &order);
}

int		ft_cd(t_command *cmd, t_list *order)
{
	char	*buf;
	char	old_pwd[MAXSTRLEN];

	buf = ft_strdup("HOME=");
	getcwd(old_pwd, MAXSTRLEN);
	if (!cmd || (cmd->command[0] == '~' && cmd->command[1] == '\0'))
	{
		go_home();
		free(buf);
		return (0);
	}
	change_old_pwd(old_pwd);
	if (chdir(cmd->command))
		put_error(order);
	else
		change_err("?=0");
	getcwd(old_pwd, MAXSTRLEN);
	change_pwd(old_pwd);
	free(buf);
	return (0);
}
