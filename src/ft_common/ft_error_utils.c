/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:58:07 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 13:20:39 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_report_error(const char *name, const char *err)
{
	ft_putstr_fd(STDERR, ERR_PROMPT);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, (char *)name);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, (char *)err);
	ft_putstr_fd(STDERR, "\n");
	if (g_params.exit_immediately)
	{
		if (g_params.exit_status == 0)
			g_params.exit_status = 1;
		exit(g_params.exit_status);
	}
}

void	ft_perror(const char *str)
{
	ft_report_error(str, strerror(errno));
}

void	ft_internal_error(const char *str, const char *err)
{
	g_params.exit_immediately = 0;
	ft_report_error(str, err);
}

void	ft_fatal_error(const char *str, const char *err)
{
	g_params.exit_immediately = 1;
	ft_set_exit_status(2);
	ft_report_error(str, err);
}

int	ft_failure_error(const char *str)
{
	ft_report_error(str, strerror(errno));
	return (EXIT_FAILURE);
}
