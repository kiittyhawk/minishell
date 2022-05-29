/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_job.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 04:14:06 by llornel           #+#    #+#             */
/*   Updated: 2022/03/19 00:46:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_build_job(t_list **exec_cmds, t_list *lst)
{
	t_command	*command;
	t_list		*tmplst;
	int			ret;

	ret = EXIT_SUCCESS;
	tmplst = lst;
	while (tmplst)
	{
		command = (t_command *)tmplst->content;
		ret = ft_build_cmd(exec_cmds, command);
		tmplst = tmplst->next;
	}
	return (ret);
}
