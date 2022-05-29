/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdlist_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:45:33 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 14:42:59 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdlist	*ft_cmdlist_new(int type, t_list *commands)
{
	t_cmdlist	*cmdlist;

	cmdlist = malloc(sizeof(t_cmdlist));
	if (cmdlist == NULL)
		return (NULL);
	cmdlist->type = type;
	cmdlist->commands = commands;
	return (cmdlist);
}

t_cmdlist	*ft_cmdlist_copy(t_cmdlist *cmdlist)
{
	t_cmdlist	*copy;
	t_list		*commands;

	if (cmdlist == NULL)
		return (NULL);
	commands = ft_lstdup(cmdlist->commands, ft_command_dup);
	copy = ft_cmdlist_new(cmdlist->type, commands);
	if (copy == NULL)
	{
		ft_lstclear(&commands, ft_command_free);
		return (NULL);
	}
	return (copy);
}

void	*ft_cmdlist_dup(void *ptr)
{
	t_cmdlist	*cmdlist;
	t_cmdlist	*copy;

	cmdlist = (t_cmdlist *)ptr;
	copy = ft_cmdlist_copy(cmdlist);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_cmdlist_free(void *ptr)
{
	t_cmdlist	*cmdlist;

	cmdlist = (t_cmdlist *)ptr;
	if (cmdlist == NULL)
		return ;
	ft_lstclear(&cmdlist->commands, ft_command_free);
	ft_memdel(cmdlist->commands);
	ft_memdel(cmdlist);
}

void	ft_cmdlist_add(t_list **cmdlist, t_list *commands, int type)
{
	t_cmdlist	*cmdlist_new;
	t_list		*commands_copy;

	commands_copy = ft_lstdup(commands, ft_command_dup);
	cmdlist_new = ft_cmdlist_new(type, commands_copy);
	ft_lstadd_back(cmdlist, ft_lstnew(cmdlist_new));
}
