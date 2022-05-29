/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:00:12 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 16:03:04 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_var	*ft_var_new(char *name, char *value, int attributes)
{
	t_var	*var;
	char	*exportstr;

	exportstr = (char *) NULL;
	var = malloc(sizeof(t_var));
	if (var == NULL)
		return (NULL);
	var->name = name;
	var->value = value;
	var->attributes = attributes;
	if (attributes == VAR_EXPORT)
		var->exportstr = ft_var_exportstr(name, value);
	return (var);
}

t_var	*ft_var_copy(t_var *var)
{
	t_var	*copy;
	char	*name;
	char	*value;

	if (var == NULL)
		return (NULL);
	name = ft_strdup(var->name);
	value = ft_strdup(var->value);
	copy = ft_var_new(name, value, var->attributes);
	if (copy == NULL)
	{
		ft_memdel(name);
		ft_memdel(value);
		return (NULL);
	}
	return (copy);
}

void	*ft_var_dup(void *ptr)
{
	t_var	*var;
	t_var	*copy;

	var = (t_var *)ptr;
	copy = ft_var_copy(var);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_var_free(void *ptr)
{
	t_var	*var;

	var = (t_var *)ptr;
	if (var == NULL)
		return ;
	ft_memdel(var->name);
	ft_memdel(var->value);
	ft_memdel(var->exportstr);
	ft_memdel(var);
}

void	ft_var_add(t_list **vars, char *name, char *value, int attributes)
{
	t_var	*var_new;
	char	*name_copy;
	char	*value_copy;

	name_copy = ft_strdup(name);
	value_copy = ft_strdup(value);
	var_new = ft_var_new(name_copy, value_copy, attributes);
	ft_lstadd_back(vars, ft_lstnew(var_new));
}
