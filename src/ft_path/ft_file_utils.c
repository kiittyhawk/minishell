/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 02:59:37 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 15:14:18 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_file_exists(const char *file)
{
	struct stat	buf;

	return (stat (file, &buf) == 0);
}

int	ft_file_isdir(const char *file)
{
	struct stat	buf;

	return ((stat (file, &buf) == 0) && S_ISDIR (buf.st_mode));
}
