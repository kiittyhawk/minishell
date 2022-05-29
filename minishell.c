/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:10:24 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 14:36:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_params	g_params = {};

static int	ft_handle_args(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr_fd(STDERR, ERR_PROMPT);
		ft_putstr_fd(STDERR, ": ");
		ft_putstr_fd(STDERR, argv[1]);
		ft_putstr_fd(STDERR, ": invalid option\n");
		ft_putstr_fd(STDERR, "Usage: minishell [option] ...\n");
		ft_putstr_fd(STDERR, "minishell options: -c command\n");
		return (EXIT_FATAL);
	}
	else if (argc == 2)
	{
		ft_putstr_fd(STDERR, ERR_PROMPT);
		ft_putstr_fd(STDERR, ": ");
		ft_putstr_fd(STDERR, argv[1]);
		ft_putstr_fd(STDERR, ": option requires an argument\n");
		return (EXIT_FATAL);
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int			ret;
	int			flag;

	flag = 0;
	ret = EXIT_SUCCESS;
	if (argc != 1)
	{
		ret = ft_handle_args(argc, argv);
		if (ret != EXIT_SUCCESS)
			return (ret);
		flag = 1;
	}
	ret = ft_params_init(envp);
	if (ret != EXIT_SUCCESS)
		return (ret);
	ft_set_signal_newprompt();
	ft_echoctl_off();
	if (flag == 0)
		ret = ft_minishell(PROMPT);
	else
		ret = ft_minishell_cmd(argv[2]);
	return (ret);
}
