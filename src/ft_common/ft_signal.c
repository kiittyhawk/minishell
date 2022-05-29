/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:00:32 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 16:54:44 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	rl_event_hook_heredoc(void)
{
	if (g_params.heredoc_status != 0)
		rl_done = 1;
	return (0);
}

void	ft_set_signal(void (*sig)(int))
{
	rl_event_hook = NULL;
	ft_set_signal_handler(SIGINT, sig);
	ft_set_signal_handler(SIGQUIT, sig);
	ft_set_signal_handler(SIGTERM, sig);
	ft_set_signal_handler(SIGTSTP, sig);
}

void	ft_set_signal_newprompt(void)
{
	rl_event_hook = NULL;
	ft_set_signal_handler(SIGINT, ft_signal_newprompt);
	ft_set_signal_handler(SIGQUIT, SIG_IGN);
	ft_set_signal_handler(SIGTERM, SIG_IGN);
	ft_set_signal_handler(SIGTSTP, SIG_IGN);
}

void	ft_set_signal_heredoc(void)
{
	rl_event_hook = rl_event_hook_heredoc;
	ft_set_signal_handler(SIGINT, ft_signal_heredoc);
	ft_set_signal_handler(SIGQUIT, SIG_IGN);
	ft_set_signal_handler(SIGTERM, SIG_IGN);
	ft_set_signal_handler(SIGTSTP, SIG_IGN);
}

void	ft_set_signal_child_process(void)
{
	rl_event_hook = NULL;
	ft_set_signal_handler(SIGINT, ft_signal_child_process);
	ft_set_signal_handler(SIGQUIT, ft_signal_child_process);
	ft_set_signal_handler(SIGTERM, SIG_IGN);
	ft_set_signal_handler(SIGTSTP, SIG_IGN);
}
