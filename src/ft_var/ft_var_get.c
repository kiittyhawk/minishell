/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:45:28 by llornel           #+#    #+#             */
/*   Updated: 2022/03/16 20:38:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_var_get(t_list *lst, char *name)
{
	t_var	*var;
	char	*value;

	if (lst == NULL || name == NULL)
		return (NULL);
	var = ft_var_find(lst, name);
	if (var == NULL || var->value == NULL)
		return (NULL);
	value = ft_strdup(var->value);
	if (value == NULL)
		return (NULL);
	return (value);
}

char	*ft_var_get_value(t_var *var)
{
	if (var == NULL)
		return (NULL);
	return (var->value);
}
