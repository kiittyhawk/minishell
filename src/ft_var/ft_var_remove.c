/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:03:14 by llornel           #+#    #+#             */
/*   Updated: 2022/03/15 22:00:53 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_var_del(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->next;
	ft_var_free((*lst)->content);
	free(*lst);
	*lst = tmp;
}

void	ft_var_remove(t_list *lst, char *name)
{
	t_var	*var;

	if (lst == NULL || name == NULL)
		return ;
	if (lst)
	{
		var = (t_var *)lst->content;
		if (!ft_strcmp(var->name, name))
		{
			ft_var_del(&lst);
			return ;
		}
	}
	while (lst && lst->next)
	{
		var = (t_var *)lst->next->content;
		if (!ft_strcmp(var->name, name))
		{
			ft_var_del(&lst->next);
			return ;
		}
		lst = lst->next;
	}
}
