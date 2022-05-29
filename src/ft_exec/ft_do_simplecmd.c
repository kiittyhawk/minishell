/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_simplecmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:48:21 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 16:03:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_do_simplecmd(t_exec_cmd *exec_cmd)
{
	char	*cmd;
	char	**args;
	char	**envp;
	int		ret;

	errno = 0;
	if (exec_cmd == NULL || exec_cmd->cmd == NULL || exec_cmd->cmd[0] == NULL)
		return (EXIT_SUCCESS);
	cmd = exec_cmd->cmd[0];
	args = exec_cmd->cmd;
	if (ft_is_builtin(cmd) == 1)
		ret = ft_do_builtin(exec_cmd->cmd, 1);
	else
	{
		envp = ft_list_to_tab(g_params.vars, ft_copy_exportstr_from_var);
		ret = ft_execve(exec_cmd->cmd[0], args, envp);
		ft_tabfree(envp);
	}
	return (ret);
}
