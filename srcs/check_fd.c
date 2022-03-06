/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:53:12 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 16:02:15 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_wrong_redir(t_redir *redir, t_env *env)
{
	if (redir && (redir->filename[0] == '.' || ft_strchr(redir->filename, '/')))
		return (print_err(2, redir->filename));
	if (redir && redir->filename[0] != '$')
		return (0);
	while (env)
	{
		while (!ft_strcmp(env->key, ft_substr(redir->filename, 1, ft_strlen(redir->filename))))
		{
			free(redir->filename);
			redir->filename = ft_strdup(env->key);
			return (0);
		}
		env = env->next;
	}
	return (print_err(3, redir->filename));
}

int	checker(t_cmds *cmd, t_all *data)
{
	t_env	*env;
	int		fd;

	env = *data->env;
	if (cmd->redirect && is_wrong_redir(cmd->redirect, env))
	{
		data->err = 1;
		return (1);
	}
	if (cmd->redirect->type == 1 && cmd->redirect->out)
		fd = open(cmd->redirect->filename, O_WRONLY|O_CREAT|O_TRUNC, 0664);
	else if (cmd->redirect->type == 2 && cmd->redirect->out)
		fd = open(cmd->redirect->filename, O_WRONLY|O_CREAT|O_APPEND, 0664);
	else
		fd = open(cmd->redirect->filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		data->err = errno;
		return (print_err(data->err, cmd->redirect->filename));
	}
	close(fd);
	return (0);
}

int	check_fd(t_all *data)
{
	t_cmds	*cmd;

	cmd = data->cmd;
	while (cmd && cmd->redirect)
	{
		if (cmd->redirect && (cmd->redirect->out || !(cmd->redirect->type == 2)))
		{
			if (checker(cmd, data))
				return (1);
		}
		else
			heredoc(cmd->redirect->limiter, data);
		cmd = cmd->next;
	}
	return (0);
}
