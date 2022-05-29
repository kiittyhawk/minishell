/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:47:48 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:48:16 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_var_set(t_list *lst, char *name, char *value, int attributes)
{
	t_var	*var;

	if (lst == NULL || name == NULL)
		return (0);
	var = ft_var_find(lst, name);
	if (var)
	{
		if (var->value == NULL)
			var->value = ft_strdup(value);
		else
			ft_strset((void **)&var->value, ft_strdup(value));
		if (attributes == VAR_EXPORT)
			ft_strset((void **)&var->exportstr,
				ft_var_exportstr(name, var->value));
	}
	else
	{
		ft_var_add(&lst, name, value, attributes);
	}
	return (EXIT_SUCCESS);
}

int	ft_var_set_export(t_list *lst, char *name, char *value)
{
	return (ft_var_set(lst, name, value, VAR_EXPORT));
}
