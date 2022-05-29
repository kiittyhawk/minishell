/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:49:06 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 14:23:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_handle_parent_fd(int fdin, int fdout)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (fdin != g_params.backupfd[0] && fdin != -1 && fdin != STDIN)
		ret = ft_close_fd(fdin);
	if (fdout != g_params.backupfd[1] && fdout != -1 && fdout != STDOUT)
		ret = ft_close_fd(fdout);
	return (ret);
}

static int	ft_handle_child_fd(int fdin, int fdout, int closefd[3])
{
	int	ret;
	int	res;

	res = EXIT_SUCCESS;
	ret = ft_restore_std(fdin, fdout);
	if (ret != EXIT_SUCCESS)
		res = ret;
	ret = ft_close_fd(closefd[0]);
	if (ret != EXIT_SUCCESS)
		res = ret;
	ret = ft_close_fd(closefd[1]);
	if (ret != EXIT_SUCCESS)
		res = ret;
	ret = ft_close_fd(closefd[2]);
	if (ret != EXIT_SUCCESS)
		res = ret;
	return (res);
}

int	ft_do_pipe(int fdin, int fdout, int closefd[3], t_exec_cmd *exec_cmd)
{
	int	ret;

	ret = EXIT_SUCCESS;
	ft_set_signal(SIG_IGN);
	exec_cmd->pid = fork();
	g_params.pid = exec_cmd->pid;
	if (exec_cmd->pid == -1)
	{
		ft_close_fd(closefd[2]);
		ret = ft_failure_error("fork");
	}
	else if (exec_cmd->pid == 0)
	{
		ft_echoctl_on();
		ft_set_signal(SIG_DFL);
		ret = ft_handle_child_fd(fdin, fdout, closefd);
		if (ret == EXIT_SUCCESS)
			ret = ft_execute_cmd(exec_cmd);
		exit(ret);
	}
	ft_handle_parent_fd(fdin, fdout);
	return (ret);
}
