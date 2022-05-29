/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:10:11 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 18:21:58 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_get_var_paths(int *flag)
{
	char	**paths;
	char	*path;

	*flag = 0;
	path = ft_var_get(g_params.vars, "PATH");
	if (path == NULL || *path == '\0')
	{
		*flag = 1;
		return (NULL);
	}	
	paths = ft_split(path, ':');
	ft_memdel(path);
	return (paths);
}

char	*ft_get_absolute_path(char **paths, const char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strdup(paths[i]);
		if (path[ft_strlen(path) - 1] != '/')
			ft_strset((void **)&path, ft_strjoin(path, "/"));
		ft_strset((void **)&path, ft_strjoin(path, cmd));
		if (access(path, X_OK) != -1)
			break ;
		ft_memdel(path);
		path = NULL;
		i++;
	}
	return (path);
}

int	ft_execve_path(char *command, char **args, char **envp)
{
	char	**paths;
	char	*path;
	int		flag;

	paths = ft_get_var_paths(&flag);
	if (paths == NULL || *paths == NULL)
	{
		errno = ENOENT;
		return (flag);
	}
	path = ft_get_absolute_path(paths, command);
	ft_tabfree(paths);
	if (path == NULL)
		errno = ENOENT;
	else
	{
		execve(path, args, envp);
		ft_memdel(path);
	}
	return (0);
}

int	ft_execve(char *command, char **args, char **envp)
{
	int		ret;
	int		status;

	status = 0;
	if (ft_strlen(command) == 0
		|| ft_strcmp(command, ".") == 0 || ft_strcmp(command, "..") == 0)
		errno = ENOENT;
	else if (ft_absolute_program(command))
		execve(command, args, envp);
	else
		status = ft_execve_path(command, args, envp);
	ret = ft_exec_error(command, status);
	return (ret);
}
