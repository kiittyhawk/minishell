/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:53:12 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/22 12:55:26 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_wrong_redir(t_redir *redir, t_env *env)
{
	if (redir && (redir->filename[0] == '.' || ft_strchr(redir->filename, '/')))
		return (1);
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
	return (1);
}

int	checker(t_cmds *cmd, t_all *data)
{
	t_env	*env;
	int		fd;

	env = *data->env;
	if (cmd->redirect && is_wrong_redir(cmd->redirect, env))
		return (1);
	if (cmd->redirect->type == 1 && cmd->redirect->out)
	{
		fd = open(cmd->redirect->filename, O_WRONLY|O_CREAT|O_TRUNC, 0664);
		if (fd == -1)
			return (1);
	}
	else if (cmd->redirect->type == 2 && cmd->redirect->out)
	{
		fd = open(cmd->redirect->filename, O_WRONLY|O_CREAT|O_APPEND, 0664);
		if (fd == -1)
			return (1);
	}
	else
	{
		fd = open(cmd->redirect->filename, O_RDONLY);
		if (fd == -1)
			return (1);
	}
	close(fd);
	return (0);
}

int	check_fd(t_all *data)
{
	t_cmds	*cmd;

	cmd = data->cmd;
	while (cmd)
	{
		if (cmd->redirect->out || !(cmd->redirect->type == 2))
		{
			if (checker(cmd, data))
				return (1);
		}
		cmd = cmd->next;
	}
	return (0);
}
