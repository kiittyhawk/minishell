/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:28:53 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_cd_other(t_list *vars, char *arg)
{
	int		ret;
	char	*cdpath;

	cdpath = ft_var_get(vars, "CDPATH");
	if (cdpath != NULL && (ft_strncmp(arg, "/", 1) != 0))
		ret = ft_cd_cdpath(vars, arg, cdpath);
	else
		ret = ft_cd_path(vars, arg);
	ft_memdel(cdpath);
	return (ret);
}

int	ft_builtin_cd(char **args, t_list *vars)
{
	int		ret;
	char	*arg;

	if (args == NULL || *args == NULL)
		return (EXIT_SUCCESS);
	if (args[0] && !ft_strnstr(args[0], "cd", ft_strlen("cd")))
		return (EXIT_FAILURE);
	arg = ft_strdup(args[1]);
	if (arg == NULL)
		ret = ft_cd_home(vars);
	else if (ft_strcmp(arg, "-") == 0)
		ret = ft_cd_oldpath(vars);
	else if (ft_strncmp(arg, "~", 1) == 0)
		ret = ft_cd_tilde(vars, arg);
	else
		ret = ft_cd_other(vars, arg);
	ft_memdel(arg);
	return (ret);
}
