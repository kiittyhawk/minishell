/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:23:08 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 19:08:01 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include "const.h"
# include "common.h"
# include "data.h"
# include "var.h"
# include "path.h"
# include "parser.h"
# include "builtin.h"
# include "exec.h"

# define LOG_FILE "msh_log_file"

typedef struct s_params
{
	t_list	*vars;
	int		backupfd[2];
	int		sigint;
	int		sigquit;
	int		exit_immediately;
	int		exit_status;
	int		heredoc_status;
	int		shlvl;
	int		echoctl_flag;
	char	*pwd;
	char	*oldpwd;
	pid_t	pid;
}				t_params;

extern t_params	g_params;

void		ft_exit_fatal(char *str);
int			ft_get_exit_status(void);
void		ft_set_exit_status(int ret);
int			ft_exit_error(void *ptr, int ret);
int			ft_exit_ctrld(void *ptr, int ret);
void		ft_signal_newprompt(int sig);
void		ft_signal_heredoc(int sig);
void		ft_signal_child_process(int sig);
void		ft_set_signal(void (*sig)(int));
void		ft_set_signal_handler(int sig, void (*cmd)(int));
void		ft_set_signal_newprompt(void);
void		ft_set_signal_heredoc(void);
void		ft_set_signal_child_process(void);
int			ft_check_echoctl(int fd);
void		ft_echoctl_off(void);
void		ft_echoctl_on(void);
void		ft_free(void);
int			ft_params_init(char **envp);
int			ft_minishell_cmd(char *str);
int			ft_minishell(char *name);

#endif
