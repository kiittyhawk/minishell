/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:32:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/15 17:43:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_size_name(const char *name)
{
	int		i;

	if (name == NULL || *name == '\0')
		return (0);
	if (ft_is_name_starter(name[0]) == 0)
		return (0);
	i = 1;
	while (name[i] && ft_is_name_char(name[i]))
		i++;
	return (i);
}

int	ft_valid_name(const char *name)
{
	int		i;

	if (name == NULL || *name == '\0')
		return (0);
	if (ft_is_name_starter(name[0]) == 0)
		return (0);
	i = 0;
	while (name[i])
	{
		if (ft_is_name_char(name[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_number(const char *str, long *result)
{
	long	value;

	if (result)
		*result = 0;
	if (str == NULL)
		return (0);
	value = ft_atol(str);
	if (*str)
	{
		if (result)
			*result = value;
		return (1);
	}
	return (0);
}

int	ft_valid_assignment(const char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
		return (0);
	if (ft_is_name_starter(str[0]) == 0)
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		if (str[i] == '+' && str[i + 1] == '=')
			return (i + 1);
		if (ft_is_name_char(str[i]) == 0)
			return (0);
		i++;
	}
	return (0);
}
