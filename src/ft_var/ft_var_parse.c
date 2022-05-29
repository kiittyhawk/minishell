/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:27:28 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 12:32:26 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_var_exportstr(char *name, char *value)
{
	char	*str;

	str = (char *) NULL;
	if (value == NULL)
		str = ft_strdup(name);
	else
	{
		ft_strset((void **)&str, ft_strjoin(name, "="));
		ft_strset((void **)&str, ft_strjoin(str, value));
	}
	return (str);
}

char	*ft_var_add_value(char *name, char *value)
{
	char	*str;
	char	*var_value;

	var_value = ft_var_get(g_params.vars, name);
	if (var_value == NULL)
		str = ft_strdup(value);
	else
	{
		str = ft_strjoin(var_value, value);
		ft_memdel(var_value);
	}
	return (str);
}

void	ft_var_parse(char *str, char **name, char **value)
{
	char	*tmp;

	tmp = ft_strchr(str, '=');
	if (tmp == NULL)
	{
		*name = ft_strdup(str);
		*value = (char *) NULL;
	}
	else if ((tmp - str) && *(tmp - 1) == '+')
	{
		*name = ft_substr(str, 0, (tmp - 1) - str);
		*value = ft_var_add_value(*name, (tmp + 1));
	}
	else
	{
		*name = ft_substr(str, 0, tmp - str);
		*value = ft_strdup(tmp + 1);
	}
}
