/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:54:34 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 16:54:44 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit_fatal(char *str)
{
	int			last_exit_status;

	last_exit_status = g_params.exit_status;
	ft_putstr_fd(STDERR, "error: ");
	if (str == NULL)
		ft_putendl_fd(STDERR, strerror(errno));
	else
	{
		if (errno)
		{
			ft_putstr_fd(STDERR, str);
			ft_putendl_fd(STDERR, strerror(errno));
		}
		else
			ft_putendl_fd(STDERR, str);
	}
	ft_free();
	exit(last_exit_status);
}

int	ft_exit_error(void *ptr, int ret)
{
	rl_clear_history();
	ft_memdel(ptr);
	ft_free();
	return (ret);
}

int	ft_exit_output(char **args)
{
	int		ret;
	int		i;

	i = 0;
	if (ft_strncmp(args[i], "exit", ft_strlen(args[i])) != 0)
		return (EXIT_FAILURE);
	i++;
	if (args[i])
		ret = ft_atoi(args[i]);
	else
		ret = ft_get_exit_status();
	printf("exit\n");
	return (ret);
}

int	ft_exit_ctrld(void *ptr, int ret)
{
	char	**args;

	if (ret == EXIT_CTRL_D)
	{
		args = ft_calloc(3, sizeof(*args));
		args[0] = ft_strdup("exit");
		args[1] = ft_itoa(ft_get_exit_status());
		ret = ft_exit_output(args);
		ft_tabfree(args);
	}
	ft_exit_error(ptr, ret);
	return (ret);
}
