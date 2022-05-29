/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:54:15 by llornel           #+#    #+#             */
/*   Updated: 2022/03/15 20:51:34 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtin_pwd(void)
{
	char	*path;

	path = ft_var_get(g_params.vars, "PWD");
	if (path == NULL || path[0] == '\0')
		path = getcwd(NULL, PATH_MAX);
	if (path == NULL)
		return (EXIT_FAILURE);
	ft_putendl_fd(STDOUT, path);
	ft_memdel((void *)path);
	return (EXIT_SUCCESS);
}
