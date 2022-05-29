/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execlist_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 03:58:48 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 14:43:31 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_execlist	*ft_execlist_new(int type, t_list *exec_cmds)
{
	t_execlist	*execlist;

	execlist = malloc(sizeof(t_execlist));
	if (execlist == NULL)
		return (NULL);
	execlist->type = type;
	execlist->exec_cmds = exec_cmds;
	return (execlist);
}

t_execlist	*ft_execlist_copy(t_execlist *execlist)
{
	t_execlist	*copy;
	t_list		*exec_cmds;

	if (execlist == NULL)
		return (NULL);
	exec_cmds = ft_lstdup(execlist->exec_cmds, ft_exec_cmd_dup);
	copy = ft_execlist_new(execlist->type, exec_cmds);
	if (copy == NULL)
	{
		ft_lstclear(&exec_cmds, ft_exec_cmd_free);
		return (NULL);
	}
	return (copy);
}

void	*ft_execlist_dup(void *ptr)
{
	t_execlist	*execlist;
	t_execlist	*copy;

	execlist = (t_execlist *)ptr;
	copy = ft_execlist_copy(execlist);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_execlist_free(void *ptr)
{
	t_execlist	*execlist;

	execlist = (t_execlist *)ptr;
	if (execlist == NULL)
		return ;
	ft_lstclear(&execlist->exec_cmds, ft_exec_cmd_free);
	ft_memdel(execlist->exec_cmds);
	ft_memdel(execlist);
}

void	ft_execlist_add(t_list **execlist, t_list *exec_cmds, int type)
{
	t_execlist	*execlist_new;
	t_list		*exec_cmds_copy;

	exec_cmds_copy = ft_lstdup(exec_cmds, ft_exec_cmd_dup);
	execlist_new = ft_execlist_new(type, exec_cmds_copy);
	ft_lstadd_back(execlist, ft_lstnew(execlist_new));
}
