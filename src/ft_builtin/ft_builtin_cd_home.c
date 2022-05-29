/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:57:57 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:31:14 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd_home(t_list *vars)
{
	int		ret;
	char	*newpath;
	char	*oldpath;

	newpath = ft_var_get(vars, "HOME");
	ret = ft_check_var("HOME", newpath);
	if (ret != EXIT_SUCCESS)
		return (ret);
	if (ft_strlen(newpath) == 0)
	{
		ft_memdel(newpath);
		newpath = ft_strdup(g_params.pwd);
	}
	if (chdir(newpath) == -1)
		return (EXIT_FAILURE);
	oldpath = ft_var_get(vars, "PWD");
	ret = ft_move_path(vars, newpath, oldpath, false);
	if (ret != EXIT_SUCCESS)
		return (ret);
	ft_memdel(newpath);
	ft_memdel(oldpath);
	return (EXIT_SUCCESS);
}
