/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:10:11 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 16:52:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_error(char *command, int flag)
{
	if (errno == ENOENT)
	{
		if (flag == 1)
			ft_report_error(command, ERR_MSG_NO_FILE_OR_DIR);
		else if (ft_strchr(command, '/') == NULL)
			ft_report_error(command, ERR_MSG_COMMANDS);
		else
			ft_report_error(command, ERR_MSG_NO_FILE_OR_DIR);
		return (EXIT_NOTFOUND);
	}
	else if (errno == EACCES)
	{
		if (ft_file_isdir(command))
			ft_internal_error(command, strerror(EISDIR));
		else
			ft_report_error(command, strerror(errno));
		return (EXIT_NOTEXECUTABLE);
	}
	else
		return (ft_failure_error(command));
}

int	ft_exists_cmd(t_exec_cmd *exec_cmd)
{
	if (exec_cmd == NULL || exec_cmd->cmd == NULL)
		return (0);
	if (ft_tabsize(exec_cmd->cmd) == 0)
		return (0);
	if (exec_cmd->cmd[0] == NULL)
		return (0);
	return (1);
}

int	ft_exists_redirects(t_list *redirects)
{
	if (redirects == NULL)
		return (0);
	if (ft_lstsize(redirects) == 0)
		return (0);
	if (redirects->content == NULL)
		return (0);
	return (1);
}

int	ft_exists_cmds(t_list *exec_cmds)
{
	if (exec_cmds == NULL)
		return (0);
	if (ft_lstsize(exec_cmds) == 0)
		return (0);
	if (exec_cmds->content == NULL)
		return (0);
	return (1);
}
