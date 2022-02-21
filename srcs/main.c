/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:29:50 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/21 17:35:09 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		printf("\b\b");
		printf("  ");
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **env)
{
	t_all	*data;
	char	*buf;
	(void)av;

	init_struct(&data);
	data->envp = create_array_envp(env);
	buf = NULL;
	if (ac != 1)
		exit(0);
	parse_env(env, data);
	shlvl_increment(*data->env);
	while (1)
	{
		signal(SIGINT, &sig_handler);
		signal(SIGQUIT, &sig_handler);
		rl_on_new_line();
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		buf = readline("minishell>  ");
		if (buf)
			add_history(buf);
		if (parser(buf, data) == 0)
		{
			executor(data);
			// while (data->cmd->redirect)
			// {
			// 	printf("%s\n", data->cmd->redirect->filename);
			// 	data->cmd->redirect = data->cmd->redirect->next;
			// }
		}
	}
}
