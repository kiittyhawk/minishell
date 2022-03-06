/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:47:13 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/04 19:15:36 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	swap_fd(int fd, t_all *data)
{
	int	new_fd;
	data->out = 1;

	new_fd = dup(STDOUT_FILENO);
	if (new_fd == -1)
	{
		close(fd);
		data->err = errno;
		ft_exit(data->err, "dup");
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(new_fd);
		close(fd);
		data->err = errno;
		ft_exit(data->err, "dup2");
	}
	return (new_fd);
}

int	swap_fd_in(int fd, t_all *data)
{
	int	new_fd;
	(void)data;

	new_fd = dup(STDIN_FILENO);
	if (new_fd == -1)
	{
		close(fd);
		data->err = errno;
		ft_exit(data->err, "dup");
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(new_fd);
		close(fd);
		data->err = errno;
		ft_exit(data->err, "dup2");
	}
	return (new_fd);
}

int	dup_fd(t_cmds *cmd, t_all *data)
{
	int	fd;
	int	new_fd;
	t_cmds	*tmp;

	fd = 0;
	new_fd = 0;
	tmp = cmd;
	if (!cmd->redirect)
		return (-1);
	while (cmd->redirect)
	{
		if (cmd->redirect->out && cmd->redirect->type == 1)
			fd = open(cmd->redirect->filename, O_WRONLY|O_CREAT|O_TRUNC, 0644);
		if (cmd->redirect->out && cmd->redirect->type == 2)
			fd = open(cmd->redirect->filename, O_WRONLY|O_CREAT|O_APPEND, 0644);
		if (fd == -1)
		{
			close(fd);
			data->err = errno;
			ft_exit(data->err, "fd");
		}
		if (cmd->redirect->last && cmd->redirect->out)
			new_fd = swap_fd(fd, data);
		if (cmd->redirect->last && !cmd->redirect->out)
			new_fd = swap_fd_in(fd, data);
		close(fd);
		cmd->redirect = cmd->redirect->next;
	}
	cmd = tmp;
	return (new_fd);
}

void	redup(int fd, t_all *data)
{
	if (data->out && dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		data->err = errno;
		ft_exit(data->err, "dup2");
	}
	close(fd);
}
