/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welease <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 23:17:15 by welease           #+#    #+#             */
/*   Updated: 2020/12/20 00:00:18 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/builtin_funcs.h"
#include "inc/minishell.h"

char			**argv_mass(t_command *el)
{
	char		**paths_mass;
	char		**ret;
	char		*copy;
	int			i;
	t_command	*tmp;

	i = 0;
	paths_mass = pm_getting(el, &tmp, &copy, &i);
	if (!(ret = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (el)
	{
		if ((ret[i++] = ft_strdup(el->command)) == NULL)
			return (free_mass1(&ret));
		el = el->next;
		ret[i] = NULL;
	}
	free(ret[0]);
	if ((ret[0] = get_path_to_exec(copy, paths_mass)) == NULL)
		return (free_all_in_argv_mass(&paths_mass, &copy, &ret));
	free(copy);
	ret[i] = NULL;
	free_path_math(paths_mass);
	return (ret);
}

void			sigkill(int sig)
{
	int			temp;

	(void)sig;
	g_status = 1;
	temp = kill(1, 0);
	g_flag ? ft_putendl_fd("", 1) : 0;
	!g_flag ? ft_putstr_fd("\ntrashell0.1$ ", 1) : 0;
}

void			sigkillbackslash(int sig)
{
	(void)sig;
	kill(1, 0);
	g_flag ? ft_putendl_fd("Quit: 3", 1) : 0;
}

void			init_params(t_cmd *cmd)
{
	cmd->env = g_env;
	g_argv = NULL;
	signal(SIGINT, sigkill);
	signal(SIGQUIT, sigkillbackslash);
	signal(SIGTSTP, sigkill);
	ft_putstr_fd("trashell0.1$ ", 1);
}

int				main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;

	(void)argv;
	(void)argc;
	g_env = copy_of_env(env, 1);
	g_status = 0;
	cmd = ft_calloc(sizeof(t_cmd), 1);
	init_params(cmd);
	while (get_next_line(0, &cmd->line) > 0)
	{
		g_flag = 0;
		cmd->cmdorder = ft_lstnew(ft_calloc(sizeof(t_command), 1));
		cmd->cmdorder->fd[0] = 0;
		cmd->cmdorder->fd[1] = 1;
		cmd->cmdorder->fd[2] = 1;
		cmd->cmdorder->pipe = 0;
		cmd->cmd = cmd->cmdorder->content;
		cmd->cmd->command = ft_calloc(1, 1);
		parsecommand(cmd);
		!g_flag ? ft_putstr_fd("trashell0.1$ ", 1) : 0;
		g_status = 0;
	}
	ft_putendl_fd("", 1);
	ft_putstr_fd("exit", 1);
}
