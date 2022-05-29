/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 19:05:03 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_getcwd_error(char *builtin, char *name, char *err)
{
	ft_putstr_fd(STDERR, builtin);
	ft_putstr_fd(STDERR, ": error retrieving current directory: ");
	ft_putstr_fd(STDERR, name);
	ft_putstr_fd(STDERR, ": cannot access parent directories");
	ft_putstr_fd(STDERR, err);
	ft_putstr_fd(STDERR, "\n");
}

static int	ft_var_error(char *builtin, char *name)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, builtin);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, name);
	ft_putstr_fd(STDERR, "': not set");
	ft_putstr_fd(STDERR, "\n");
	return (EXIT_FAILURE);
}

int	ft_check_var(char *name, char*path)
{
	if (path == NULL && name != NULL)
		return (ft_var_error("cd", name));
	else if (ft_strlen(path) > 0 && chdir(path) == -1)
	{
		return (ft_builtin_failure("cd", path));
	}
	return (EXIT_SUCCESS);
}

int	ft_move_path(t_list *vars, char *path, char *oldpath, bool print)
{
	char	*cwd;

	if (chdir(path) == -1)
		return (ft_builtin_failure("cd", path));
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		ft_getcwd_error("cd", "getcwd", ERR_MSG_NO_FILE_OR_DIR);
		cwd = ft_path_join(oldpath, path);
	}
	ft_var_set_export(vars, "PWD", cwd);
	ft_var_set_export(vars, "OLDPWD", oldpath);
	ft_strset((void **)&g_params.pwd, ft_strdup(cwd));
	if (print)
		ft_putendl_fd(STDOUT, cwd);
	ft_memdel(cwd);
	return (EXIT_SUCCESS);
}
