/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:09:34 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 18:33:40 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_handle_next_cmd(int type, int ret)
{
	if (ret != EXIT_SUCCESS && type == TOKEN_AND_AND)
		return (1);
	else if (ret == EXIT_SUCCESS && type == TOKEN_OR_OR)
		return (1);
	return (0);
}

int	ft_executor(t_list **lst)
{
	t_cmdlist	*cmdlist;
	t_list		*exec_cmds;
	t_list		*tmplst;
	int			ret;

	ret = EXIT_SUCCESS;
	exec_cmds = (t_list *) NULL;
	tmplst = *lst;
	while (tmplst)
	{
		cmdlist = (t_cmdlist *)tmplst->content;
		ret = ft_build_job(&exec_cmds, cmdlist->commands);
		ret = ft_run_job(&exec_cmds);
		ft_set_exit_status(ret);
		ft_lstclear(&exec_cmds, ft_exec_cmd_free);
		ft_memdel(exec_cmds);
		if (ft_handle_next_cmd(cmdlist->type, ret) == 1)
			tmplst = tmplst->next;
		tmplst = tmplst->next;
	}
	return (ret);
}
