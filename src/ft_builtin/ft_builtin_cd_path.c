/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 18:27:08 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_oldpath(t_list *vars)
{
	int		ret;
	char	*path_to;
	char	*path_from;

	path_from = ft_var_get(vars, "OLDPWD");
	ret = ft_check_var("OLDPWD", path_from);
	if (ret != EXIT_SUCCESS)
		return (ret);
	if (ft_strlen(path_from) == 0)
	{
		ft_memdel(path_from);
		path_from = ft_strdup(g_params.pwd);
	}
	path_to = ft_var_get(vars, "PWD");
	ft_var_set_export(vars, "PWD", path_from);
	ft_var_set_export(vars, "OLDPWD", path_to);
	ft_memdel(g_params.pwd);
	g_params.pwd = ft_strdup(path_from);
	printf("%s\n", path_from);
	ft_memdel(path_to);
	ft_memdel(path_from);
	return (EXIT_SUCCESS);
}

int	ft_cd_path(t_list *vars, char *arg)
{
	int		ret;
	char	*oldpath;
	char	*oldpwd;

	oldpath = ft_var_get(vars, "PWD");
	oldpwd = ft_var_get(vars, "OLDPWD");
	ret = ft_move_path(vars, arg, oldpath, false);
	if (ret != EXIT_SUCCESS)
		ret = ft_check_var(NULL, arg);
	ft_memdel(oldpath);
	ft_memdel(oldpwd);
	return (ret);
}
