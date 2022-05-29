/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:43:29 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 14:41:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec_cmd	*ft_exec_cmd_new(char **cmd, int type, pid_t pid,
					t_list *redirects)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = malloc(sizeof(t_exec_cmd));
	if (exec_cmd == NULL)
		return (NULL);
	exec_cmd->cmd = cmd;
	exec_cmd->type = type;
	exec_cmd->pid = pid;
	exec_cmd->redirects = redirects;
	return (exec_cmd);
}

t_exec_cmd	*ft_exec_cmd_copy(t_exec_cmd *exec_cmd)
{
	t_exec_cmd	*copy;
	char		**cmd;
	t_list		*redirects;

	if (exec_cmd == NULL)
		return (NULL);
	cmd = ft_tabdup(exec_cmd->cmd);
	redirects = ft_lstdup(exec_cmd->redirects, ft_redirect_dup);
	copy = ft_exec_cmd_new(cmd, exec_cmd->type, exec_cmd->pid, redirects);
	if (copy == NULL)
	{
		ft_tabfree(cmd);
		ft_lstclear(&redirects, ft_redirect_free);
		ft_memdel(redirects);
		return (NULL);
	}
	return (copy);
}

void	*ft_exec_cmd_dup(void *ptr)
{
	t_exec_cmd	*exec_cmd;
	t_exec_cmd	*copy;

	exec_cmd = (t_exec_cmd *)ptr;
	copy = ft_exec_cmd_copy(exec_cmd);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_exec_cmd_free(void *ptr)
{
	t_exec_cmd	*exec_cmd;

	exec_cmd = (t_exec_cmd *)ptr;
	if (exec_cmd == NULL)
		return ;
	ft_tabfree(exec_cmd->cmd);
	ft_lstclear(&exec_cmd->redirects, ft_redirect_free);
	ft_memdel(exec_cmd->redirects);
	ft_memdel(exec_cmd);
}
