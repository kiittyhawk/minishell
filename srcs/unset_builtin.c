/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:32:55 by llornel           #+#    #+#             */
/*   Updated: 2022/03/06 14:26:36 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	ft_env_ischar(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

bool	ft_env_key_isvalid(const char *str)
{
	int		i;

	if (str == NULL)
		return (false);
	if (ft_isdigit(str[0]))
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_env_ischar(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_env_unset(t_env *env, char *key)
{
	int		ret;

	ret = 0;
	if (!ft_env_key_isvalid(key))
		ret = EXIT_BUILTIN;
	if (!ft_env_remove(env, key))
		ret = EXIT_FAILURE;
	return (ret);
}

void ft_builtin_unset(char **args, t_env *env, t_all *data)
{
	int	i;

	if (!args[1])
	{
		data->err = 0;
		return ;
	}
	i = 1;
	while (args[i])
	{
		if (ft_env_unset(env, args[i]) == 1)
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putstr_fd("`: not a valid identifier\n", STDERR_FILENO);
			data->err = 1;
		}
		i++;
	}
}
