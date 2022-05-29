/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echoctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:00:32 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 14:36:47 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_echoctl(int fd)
{
	struct termios	attr;

	if (isatty(fd))
	{
		tcgetattr(fd, &attr);
		if (attr.c_lflag == (attr.c_lflag | ECHOCTL))
			return (1);
	}
	return (0);
}

void	ft_echoctl_off(void)
{
	struct termios	attr;

	if (isatty(STDIN_FILENO))
	{
		tcgetattr(STDIN_FILENO, &attr);
		attr.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDOUT_FILENO))
	{
		tcgetattr(STDOUT_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDOUT_FILENO, TCSANOW, &attr);
	}
	else if (isatty(STDERR_FILENO))
	{
		tcgetattr(STDERR_FILENO, &attr);
		attr.c_lflag = attr.c_lflag & ~ECHOCTL;
		tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	}
}

void	ft_echoctl_on(void)
{
	struct termios	attr;

	if (isatty(STDIN) && g_params.echoctl_flag == 1)
	{
		tcgetattr(STDIN, &attr);
		attr.c_lflag = attr.c_lflag | ECHOCTL;
		tcsetattr(STDIN, TCSANOW, &attr);
	}
	else if (isatty(STDOUT) && g_params.echoctl_flag == 1)
	{
		tcgetattr(STDOUT, &attr);
		attr.c_lflag = attr.c_lflag | ECHOCTL;
		tcsetattr(STDOUT, TCSANOW, &attr);
	}
	else if (isatty(STDERR) && g_params.echoctl_flag == 1)
	{
		tcgetattr(STDERR, &attr);
		attr.c_lflag = attr.c_lflag | ECHOCTL;
		tcsetattr(STDERR, TCSANOW, &attr);
	}
}
