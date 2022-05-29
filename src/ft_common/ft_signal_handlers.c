/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:00:32 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 12:53:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_signal_handler(int sig, void (*cmd)(int))
{
	if (signal(sig, cmd) == SIG_ERR)
		ft_exit_fatal("signal error: ");
}

void	ft_signal_newprompt(int sig)
{
	if (sig == SIGINT)
		g_params.exit_status = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signal_heredoc(int sig)
{
	(void)sig;
	g_params.heredoc_status = sig + 128;
}

void	ft_signal_child_process(int sig)
{
	(void)sig;
	if (sig == SIGINT)
		printf("\n");
	if (sig == SIGQUIT)
		printf("Quit: 3\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}
