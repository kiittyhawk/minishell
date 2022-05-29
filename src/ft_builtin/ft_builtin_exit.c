/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:13:22 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 16:54:44 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_args_error(char *builtin, char *name, char *err)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, builtin);
	ft_putstr_fd(STDERR, ": ");
	if (name != NULL)
	{
		ft_putstr_fd(STDERR, name);
		ft_putstr_fd(STDERR, ": ");
	}
	ft_putstr_fd(STDERR, err);
	ft_putstr_fd(STDERR, "\n");
}

static int	ft_builtin_exit_child(char **args)
{
	long	ret;

	if (args[1] == NULL)
		return (g_params.exit_status);
	if (!ft_strisnumber(args[1]) || ft_atol_num(args[1], &ret) == 0)
	{
		ft_args_error("exit", args[1], ERR_MSG_NUMERIC);
		return (EXIT_RANGE);
	}
	if (ft_tabsize(args) > 2)
	{
		ft_args_error("exit", NULL, ERR_MSG_TOO_MANY_ARGS);
		return (EXIT_FAILURE);
	}
	return (ft_atol(args[1]));
}

static int	ft_builtin_exit_main(char **args)
{
	long	ret;

	ft_putstr_fd(STDERR, "exit\n");
	if (args[1] == NULL)
		exit(g_params.exit_status);
	if (!ft_strisnumber(args[1]) || ft_atol_num(args[1], &ret) == 0)
	{
		ft_args_error("exit", args[1], ERR_MSG_NUMERIC);
		exit(EXIT_RANGE);
	}
	if (ft_tabsize(args) > 2)
	{
		ft_args_error("exit", NULL, ERR_MSG_TOO_MANY_ARGS);
		ft_set_exit_status(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	exit(ft_atol(args[1]));
}

int	ft_builtin_exit(char **args, int child)
{
	int	ret;

	if (args == NULL)
		return (EXIT_FAILURE);
	if (args[0] && !ft_strnstr(args[0], "exit", ft_strlen("exit")))
		return (EXIT_FAILURE);
	if (child == 1)
		ret = ft_builtin_exit_child(args);
	else
		ret = ft_builtin_exit_main(args);
	return (ret);
}
