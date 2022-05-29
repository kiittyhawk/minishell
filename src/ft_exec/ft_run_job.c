/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 04:14:06 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 22:06:40 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_run_job(t_list **exec_cmds)
{
	t_exec_cmd	*exec_cmd;
	int			ret;

	if (ft_exists_cmds(*exec_cmds) == 0)
		return (EXIT_SUCCESS);
	if (ft_lstsize(*exec_cmds) == 1)
	{
		exec_cmd = (t_exec_cmd *)exec_cmds[0]->content;
		if (ft_exists_cmd(exec_cmd) && ft_is_builtin(exec_cmd->cmd[0]) == 1)
			ret = ft_execute_builtin(exec_cmd);
		else
			ret = ft_execute_job(exec_cmd);
	}
	else
		ret = ft_execute_jobs(exec_cmds);
	return (ret);
}
