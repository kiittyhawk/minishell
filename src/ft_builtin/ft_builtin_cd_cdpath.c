/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd_cdpath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 14:15:09 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_move_cdpath(t_list *vars, char **paths, char *arg, char *oldpath)
{
	char	*path;
	int		i;
	int		ret;

	i = 0;
	while (paths[i])
	{
		path = ft_strdup(paths[i]);
		ft_strset((void **)&path, ft_strjoin(path, "/"));
		ft_strset((void **)&path, ft_strjoin(path, arg));
		ret = ft_move_path(vars, path, oldpath, true);
		if (ret == EXIT_SUCCESS)
			break ;
		i++;
	}
	if (ret != EXIT_SUCCESS)
		ret = ft_check_var(NULL, path);
	ft_memdel(path);
	return (ret);
}

int	ft_cd_cdpath(t_list *vars, char *arg, char *cdpath)
{
	char	**paths;
	char	*oldpath;
	int		i;
	int		ret;

	oldpath = ft_var_get(vars, "PWD");
	ret = ft_move_path(vars, arg, oldpath, false);
	if (ret != EXIT_SUCCESS)
	{
		paths = ft_split(cdpath, ':');
		if (paths == NULL)
			return (EXIT_FAILURE);
		ft_tabprint(paths);
		i = 0;
		ret = ft_move_cdpath(vars, paths, arg, oldpath);
		ft_tabfree(paths);
	}
	ft_memdel(oldpath);
	return (ret);
}
