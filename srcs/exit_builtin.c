/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:41:27 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/04 17:07:07 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	isalldigit(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) || ft_strlen(str) >= 19)
			return (1);
	}
	return (0);
}

int	exit_cmd(t_all *data, t_cmds *cmd)
{
	if (data->cmd_count == 1)
		ft_putstr_fd("exit\n", 1);
	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	if (cmd->args[1] && !isalldigit(cmd->args[1]))
		ft_exit(ft_atoi(data->cmd->args[1]), NULL);
	else if (cmd->args[1])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		ft_exit(255, NULL);
	}
	else
		ft_exit(0, NULL);
	return (0);
}

int	ft_exit(int errnum, char *msg)
{
	char	*errmsg;

	if (msg)
	{
		errmsg = strerror(errnum);
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(errmsg, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	exit(errnum);
}
