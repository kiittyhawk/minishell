/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:22:58 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 12:22:39 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin_error(char *builtin, char *name, char *err)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, builtin);
	ft_putstr_fd(STDERR, ": `");
	ft_putstr_fd(STDERR, name);
	ft_putstr_fd(STDERR, "': ");
	ft_putstr_fd(STDERR, err);
	ft_putstr_fd(STDERR, "\n");
}

int	ft_builtin_failure(char *builtin, char *name)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, builtin);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, name);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, strerror(errno));
	ft_putstr_fd(STDERR, "\n");
	return (EXIT_FAILURE);
}

int	ft_is_builtin(char *str)
{
	if (ft_strcmp(str, "echo") == 0)
		return (1);
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	if (ft_strcmp(str, "pwd") == 0)
		return (1);
	if (ft_strcmp(str, "env") == 0)
		return (1);
	if (ft_strcmp(str, "export") == 0)
		return (1);
	if (ft_strcmp(str, "unset") == 0)
		return (1);
	if (ft_strcmp(str, "exit") == 0)
		return (1);
	return (0);
}

int	ft_do_builtin(char **args, int child)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		ret = ft_builtin_echo(args);
	if (ft_strcmp(args[0], "cd") == 0)
		ret = ft_builtin_cd(args, g_params.vars);
	if (ft_strcmp(args[0], "pwd") == 0)
		ret = ft_builtin_pwd();
	if (ft_strcmp(args[0], "export") == 0)
		ret = ft_builtin_export(args, g_params.vars);
	if (ft_strcmp(args[0], "unset") == 0)
		ret = ft_builtin_unset(args, g_params.vars);
	if (ft_strcmp(args[0], "env") == 0)
		ret = ft_builtin_env(g_params.vars);
	if (ft_strcmp(args[0], "exit") == 0)
		ret = ft_builtin_exit(args, child);
	return (ret);
}
