/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:32:55 by llornel           #+#    #+#             */
/*   Updated: 2022/03/17 01:13:16 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_var_unset(t_list *vars, char *name)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (ft_valid_name(name) == 0)
	{
		ft_builtin_error("unset", name, ERR_MSG_IDENTIFIER);
		ret = EXIT_FAILURE;
	}
	else
	{
		ft_var_remove(vars, name);
	}
	return (ret);
}

int	ft_builtin_unset(char **args, t_list *vars)
{
	int		i;
	int		ret;

	if (args == NULL || *args == NULL)
		return (EXIT_SUCCESS);
	if (args[0] && !ft_strnstr(args[0], "unset", ft_strlen("unset")))
		return (EXIT_FAILURE);
	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (ft_var_unset(vars, args[i]) != EXIT_SUCCESS)
			ret = EXIT_FAILURE;
		i++;
	}
	return (ret);
}
