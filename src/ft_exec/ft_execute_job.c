/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_job.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 04:14:06 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 14:36:19 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_execute_pipe(t_exec_cmd	*exec_cmd, int pipefd[2], int fd[2],
								int is_first)
{
	int	ret;
	int	closefd[3];

	closefd[0] = g_params.backupfd[0];
	closefd[1] = g_params.backupfd[1];
	closefd[2] = pipefd[0];
	fd[1] = pipefd[1];
	if (is_first && exec_cmd->type == TOKEN_PIPE)
		fd[0] = STDIN;
	else if (exec_cmd->type != TOKEN_PIPE)
	{
		fd[1] = g_params.backupfd[1];
		ft_close_pipe(pipefd[0], pipefd[1]);
		closefd[1] = -1;
		closefd[2] = -1;
	}
	ret = ft_do_pipe(fd[0], fd[1], closefd, exec_cmd);
	fd[0] = pipefd[0];
	return (ret);
}

static int	ft_execute_loop(t_list **exec_cmds)
{
	t_list	*tmplst;
	int		pipefd[2];
	int		tmpfd[2];
	int		is_first;
	int		ret;

	tmplst = *exec_cmds;
	is_first = 1;
	while (tmplst)
	{
		if (pipe(pipefd) == -1)
			return (ft_failure_error("pipe"));
		ret = ft_execute_pipe((t_exec_cmd *)tmplst->content,
				pipefd, tmpfd, is_first);
		if (ret != EXIT_SUCCESS)
			return (ret);
		tmplst = tmplst->next;
		is_first = 0;
	}
	return (EXIT_SUCCESS);
}

int	ft_execute_job(t_exec_cmd *exec_cmd)
{
	int		ret;
	int		status;
	int		closefd[3];

	g_params.backupfd[0] = dup(STDIN);
	g_params.backupfd[1] = dup(STDOUT);
	closefd[0] = g_params.backupfd[0];
	closefd[1] = g_params.backupfd[1];
	closefd[2] = -1;
	ret = ft_do_pipe(STDIN, STDOUT, closefd, exec_cmd);
	if (ret != EXIT_SUCCESS)
		return (ret);
	ret = ft_restore_std(g_params.backupfd[0], g_params.backupfd[1]);
	if (ret != EXIT_SUCCESS)
		return (ret);
	g_params.backupfd[0] = -1;
	g_params.backupfd[1] = -1;
	waitpid(exec_cmd->pid, &status, 0);
	ret = ft_process_exit_status(status);
	ft_set_signal_newprompt();
	ft_echoctl_off();
	return (ret);
}

int	ft_execute_jobs(t_list **exec_cmds)
{
	int			ret;
	int			ret_exec;

	g_params.backupfd[0] = dup(STDIN);
	g_params.backupfd[1] = dup(STDOUT);
	ret_exec = ft_execute_loop(exec_cmds);
	ret = ft_restore_std(g_params.backupfd[0], g_params.backupfd[1]);
	g_params.backupfd[0] = -1;
	g_params.backupfd[1] = -1;
	ret = ft_wait_process();
	ft_set_signal_newprompt();
	ft_echoctl_off();
	if (ret_exec != EXIT_SUCCESS)
		return (ret_exec);
	if (ret != EXIT_SUCCESS)
		return (ret);
	return (ret);
}

int	ft_execute_builtin(t_exec_cmd *exec_cmd)
{
	int	ret;

	g_params.backupfd[0] = dup(STDIN);
	g_params.backupfd[1] = dup(STDOUT);
	ret = ft_do_redirects(exec_cmd);
	if (ret == EXIT_SUCCESS)
		ret = ft_do_builtin(exec_cmd->cmd, 0);
	if (ft_restore_std(g_params.backupfd[0], g_params.backupfd[1]) == 1)
		return (EXIT_FAILURE);
	g_params.backupfd[0] = -1;
	g_params.backupfd[1] = -1;
	return (ret);
}
