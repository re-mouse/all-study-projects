/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleilani <hleilani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 12:04:44 by hleilani          #+#    #+#             */
/*   Updated: 2020/12/19 23:55:31 by welease          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>

# define MAXSTRLEN 2048

int						g_pipetemp0;
int						g_pipetemp1;
int						g_flag;
int						g_status;
char					**g_env;
char					**g_argv;
int						g_parseerr;

typedef	struct			s_command
{
	char				*command;
	struct s_command	*next;
}						t_command;

typedef struct			s_cmd
{
	char				**env;
	char				*line;
	t_command			*cmd;
	t_command			*cmdtemp;
	t_list				*cmdorder;
	char				*func;
	int					**fd;
	char				*dir;
	int					pipetemp;
}						t_cmd;

char					**get_path_mass(char *com);
char					*get_path_to_exec(char *str, char **path_mass);
char					**free_all_in_argv_mass(char ***paths_mass, char **copy,
											char ***ret);
char					**pm_getting(t_command *el, t_command **tmp,
						char **copy, int *i);
void					parsecommand(t_cmd *cmd);
char					*ft_charjoin(char c, char *str);
int						get_next_line(int fd, char **line);
int						is_space(char c);
void					updatefd(t_cmd *cmd, int index, int newfd);
void					predprocess(t_cmd *cmd);
int						find_char_in_str(char *str, char c);
int						find_count_of_dis(char *str);
int						is_str_num(char *str);
char					**argv_mass(t_command *el);
char					*processpipe(char *cmdline, t_cmd *cmd);
char					*processdot(char *cmdline, t_cmd *cmd);
t_command				*newcommandorder(t_cmd *cmd, int pipe);
char					*parsesinglequote(t_command *c, char *cm, t_cmd *cmd);
char					*parsewithoutquote(t_command *c, char *cm,
						t_cmd *cd, int m);
char					*parsedoublequote(t_command *c, char *cm, t_cmd *cmd);
int						isredirect(char *line);
char					*skipspace(char *line);
int						isbannedsymbol(char c);
char					*checkredirect(char *cmdline, t_cmd *cmd);
t_command				*allocatenewcommand(t_command *old);
char					*simpleprocess(char *cmdline, t_cmd *cmd, int m);
char					*findenvvar(t_command *cmd, char **env, char *cmdline);
void					change_err(char *err);
void					findinenv(char *var, t_command *cmd, char **env);
void					freeorders(t_list *ord);
t_list					*getlastorder(t_cmd *cmd);
void					daughterpostprocess(int r, int t, int m, t_cmd *c);
void					parentpostprocess(int ret, int temp);
void					put_er(t_cmd *cmd);
void					startforks(t_cmd *cmd, int temp, int my_tmp);
int						parsebuiltinfunc(t_cmd *cmd);
void					pprocess(t_cmd *cmd, int *fd, int *temp, int *my_tmp);
void					preparetoprocess(t_cmd *cmd);

#endif
