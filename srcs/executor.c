/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:35:54 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/21 18:19:39 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_flag(t_cmds *cmd)
{
	while (cmd)
	{
		if (cmd->cmd[0])
		{
			if (!ft_strcmp(cmd->cmd, "echo"))
				cmd->flag = 1;
			if (!ft_strcmp(cmd->cmd, "cd"))
				cmd->flag = 2;
			if (!ft_strcmp(cmd->cmd, "pwd"))
				cmd->flag = 3;
			if (!ft_strcmp(cmd->cmd, "export"))
				cmd->flag = 4;
			if (!ft_strcmp(cmd->cmd, "unset"))
				cmd->flag = 5;
			if (!ft_strcmp(cmd->cmd, "env"))
				cmd->flag = 6;
			if (!ft_strcmp(cmd->cmd, "exit"))
				cmd->flag = 7;
		}
		cmd = cmd->next;
	}
}

int	is_buildin(t_cmds *cmd)
{
	if (cmd->flag > 0)
		return (1);
	if (cmd->flag == 0)
		return (0);
	return (-1);
}

void	determinant_flag(t_all *data, t_cmds *cmd)
{
	if (cmd->flag == 1)
		echo_buildin(cmd->args);
	if (cmd->flag == 2)
		cd_buildin(cmd->args);
	if (cmd->flag == 3)
		pwd_buildin();
	if (cmd->flag == 4)
		export_buildin(data, cmd->args);
	if (cmd->flag == 5)
		unset(data, cmd->args);
	if (cmd->flag == 6)
		env_buildin(data->env);
	if (cmd->flag == 7)
		return ;
}

void	do_redirect(t_redir *redir)
{
	if (redir->type == 1 && redir->out)
	{
		int fd = open(redir->filename, O_WRONLY|O_CREAT|O_TRUNC, 0664);
		dup2(fd, 1);
	}
	if (redir->type == 2 && redir->out)
	{
		int fd = open(redir->filename, O_WRONLY|O_CREAT|O_APPEND, 0664);
		dup2(fd, 1);
	}
}

void	executor(t_all *data)
{
	t_cmds	*cmd;
	pid_t	 pid;

	cmd = data->cmd;
	set_flag(cmd);
	if (cmd)
	{
		pid = fork();
		if (pid == 0 && is_buildin(cmd))
		{
			// do_redirect(cmd->redirect);
			determinant_flag(data, cmd);
		}
		else if (pid == 0 && !is_buildin(cmd))
		{
			// do_redirect(data->cmd->redirect);
			if (execve(cmd->cmd, cmd->args, data->envp) == -1)
				perror("minishell");
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("minishell");
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
}
