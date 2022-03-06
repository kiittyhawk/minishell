/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:29:50 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 20:29:56 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_empty(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str && str[i] != ' ')
			return (0);
	}
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		free(array[i]);
	free(array);
}

void	minishell(char *buf, t_all *data)
{
	char	**cmds;
	int		i;

	cmds = NULL;
	i = -1;
	while (1)
	{
		signal(SIGINT, &ft_handler_sigint);
		// signal(SIGQUIT, &sig_handler);
		rl_on_new_line();
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		buf = readline("minishell>  ");
		if (!buf)
			ft_exit(1, NULL);
		if (buf)
			add_history(buf);
		if (is_empty(buf))
			continue ;
		else if (parser(buf, data) == 0)
		{
			if (ft_strchr(buf, ';'))
				cmds = ft_split(buf, ';');
			if (cmds)
				while (cmds[++i] && parser(cmds[i], data) == 0)
					executor(data);
			else
				executor(data);
		}
		free_array(cmds);
	}
}

int	main(int ac, char **av, char **env)
{
	t_all	*data;
	char	*buf;
	(void)av;

	init_struct(&data);
	buf = NULL;
	if (ac != 1)
		args_err();
	data->envp = create_array_envp(env, data);
	parse_env(env, data);
	shlvl_increment(*data->env);
	minishell(buf, data);
}
