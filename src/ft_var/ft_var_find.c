/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:41:58 by llornel           #+#    #+#             */
/*   Updated: 2022/03/15 20:50:36 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*ft_var_find(t_list *lst, char *name)
{
	t_var	*var;

	while (lst)
	{
		var = (t_var *)lst->content;
		if (ft_strcmp(var->name, name) == 0)
			return (var);
		lst = lst->next;
	}
	return (NULL);
}
