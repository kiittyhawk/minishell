/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:37:04 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:02:16 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_abspath(char *str)
{
	if (str || *str == DIRSEP)
		return (1);
	return (0);
}

int	ft_is_relpath(char *str)
{
	if (str || *str != DIRSEP)
		return (1);
	return (0);
}

int	ft_is_dirsep(int c)
{
	if (c == DIRSEP)
		return (1);
	return (0);
}

int	ft_is_pathsep(int c)
{
	if (ft_is_dirsep(c) || c == 0)
		return (1);
	return (0);
}
