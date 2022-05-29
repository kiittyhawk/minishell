/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:45:46 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 10:35:21 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_close_fd(int fd)
{
	if (fd != -1)
	{
		if (close(fd) == ERROR)
			return (ft_close_error(fd));
	}
	return (EXIT_SUCCESS);
}

int	ft_close_pipe(int fdin, int fdout)
{
	if (fdin != -1 && fdin != STDIN)
	{
		if (close(fdin) == ERROR)
			return (ft_close_error(fdin));
	}
	if (fdout != -1 && fdout != STDOUT)
	{
		if (close(fdout) == ERROR)
			return (ft_close_error(fdout));
	}
	return (EXIT_SUCCESS);
}

int	ft_restore_fd(int fd, int fdup)
{
	if (fd != -1)
	{
		if (dup2(fd, fdup) == ERROR)
			return (ft_dup_error(fd, fdup));
		if (close(fd) == ERROR)
			return (ft_close_error(fd));
	}
	return (EXIT_SUCCESS);
}

int	ft_restore_std(int fdin, int fdout)
{
	int	ret;

	if (fdin != -1 && fdin != STDIN)
	{
		ret = ft_restore_fd(fdin, STDIN);
		if (ret != EXIT_SUCCESS)
			return (ret);
	}
	if (fdout != -1 && fdout != STDOUT)
	{
		ret = ft_restore_fd(fdout, STDOUT);
		if (ret != EXIT_SUCCESS)
			return (ret);
	}
	return (EXIT_SUCCESS);
}
