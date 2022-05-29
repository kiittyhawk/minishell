/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd_tilde.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 11:01:31 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_tilde(t_list *vars, char *arg)
{
	char	*homepath;
	char	*newpath;
	char	*oldpath;

	homepath = ft_var_get(vars, "HOME");
	if (homepath == NULL)
		homepath = ft_strdup(g_params.pwd);
	newpath = ft_expand_tilde(arg);
	ft_memdel(homepath);
	if (newpath == NULL)
		return (EXIT_FAILURE);
	oldpath = ft_var_get(vars, "PWD");
	ft_var_set_export(vars, "PWD", newpath);
	ft_var_set_export(vars, "OLDPWD", oldpath);
	ft_memdel(g_params.pwd);
	g_params.pwd = ft_strdup(newpath);
	ft_memdel(newpath);
	ft_memdel(oldpath);
	return (EXIT_SUCCESS);
}
