/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:57:42 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 22:23:17 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_process_exit_signal(int status)
{
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else
		return (EXIT_SUCCESS);
}

int	ft_process_exit_status(int status)
{
	if (WIFSIGNALED(status))
	{
		if (status == SIGQUIT)
			printf("Quit: 3\n");
		else
			printf("\n");
		return (EXIT_SIGOFFSET + WTERMSIG(status));
	}
	else if (WIFSTOPPED(status))
		return (WSTOPSIG(status));
	else if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else
		return (EXIT_SUCCESS);
}

int	ft_wait_process(void)
{
	int			ret;
	int			status;
	pid_t		pid;

	ret = EXIT_SUCCESS;
	while (true)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (pid == g_params.pid)
			ret = ft_process_exit_status(status);
	}
	return (ret);
}
