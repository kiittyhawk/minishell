/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:35:54 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/22 13:20:34 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_flag(t_cmds *cmd)
{
	while (cmd)
	{
		if (cmd->cmd)
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
	int	fd;

	if (redir->type == 1 && redir->out)
	{
		fd = open(redir->filename, O_WRONLY|O_CREAT|O_TRUNC, 0664);
		dup2(fd, 1);
	}
	if (redir->type == 2 && redir->out)
	{
		fd = open(redir->filename, O_WRONLY|O_CREAT|O_APPEND, 0664);
		dup2(fd, 1);
	}
}

void	ft_pipe(t_all *data)
{
	int	i;

	i = 0;
	data->fd = malloc((data->cmd_count - 1) * sizeof(int *));
	if (!data->fd)
		return (1);
	while (i < data->cmd_count - 1)
	{
		data->fd[i] = malloc(2 * sizeof(int));
		if (!data->fd)
			return (1);
		if (pipe(data->fd[i]) == -1)
		{
			while (--i)
			{
				close(data->fd[i][0]);
				close(data->fd[i][1]);
			}
			/*обработать errno*/
		}
		i++;
	}
}

void	executor(t_all *data)
{
	t_cmds	*cmd;
	pid_t	 pid;

	cmd = data->cmd;
	set_flag(cmd);
	if (!check_fd(data))
	{
		if (data->cmd_count == 0)
			return ;
		if (data->cmd_count > 1)
			ft_pipe(data);
		/*впихуемое*/
		// while (cmd)
		// {
		// 	pid = fork();
		// 	if (pid == 0 && is_buildin(cmd))
		// 	{
		// 		if (cmd->redirect)
		// 			do_redirect(cmd->redirect);
		// 		determinant_flag(data, cmd);
		// 	}
		// 	else if (pid == 0 && !is_buildin(cmd))
		// 	{
		// 		// do_redirect(data->cmd->redirect);
		// 		if (execve(cmd->cmd, cmd->args, data->envp) == -1)
		// 			perror("minishell");
		// 		exit(EXIT_FAILURE);
		// 	}
		// 	else if (pid < 0)
		// 	{
		// 		perror("minishell");
		// 	}
		// 	else
		// 	{
		// 		waitpid(pid, NULL, 0);
		// 	}
		// 	cmd = cmd->next;
		// }
	}
}
