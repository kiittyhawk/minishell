/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:52:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 16:45:40 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	print_err(int errnum, char *msg)
{
	if (errnum == 2)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
	}
	else if (errnum == 3)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd(": ambiguous redirect\n", STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errnum), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (1);
}

void	malloc_err(int errnum, t_all *data)
{
	data->err = errnum;
	ft_putstr_fd("minishell: malloc: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errnum), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errnum);
}

void	args_err()
{
	ft_putstr_fd("Use ./minishell\n", STDERR_FILENO);
	exit(0);
}
