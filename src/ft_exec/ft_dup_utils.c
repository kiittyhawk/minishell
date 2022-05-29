/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:30:37 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 10:30:50 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_dup_error(int fdold, int fdnew)
{
	ft_putstr_fd(STDERR, PROMPT);
	ft_putstr_fd(STDERR, ": cannot duplicate fd ");
	ft_putnbr_fd(STDERR, fdold);
	ft_putstr_fd(STDERR, " to fd ");
	ft_putnbr_fd(STDERR, fdnew);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, strerror(errno));
	ft_putstr_fd(STDERR, "\n");
	return (EXIT_FAILURE);
}

int	ft_close_error(int fd)
{
	ft_putstr_fd(STDERR, PROMPT);
	ft_putstr_fd(STDERR, ": cannot close fd ");
	ft_putnbr_fd(STDERR, fd);
	ft_putstr_fd(STDERR, ": ");
	ft_putstr_fd(STDERR, strerror(errno));
	ft_putstr_fd(STDERR, "\n");
	return (EXIT_FAILURE);
}
