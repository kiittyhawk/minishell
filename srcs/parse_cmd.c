/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:44:19 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/28 17:49:07 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_redirect(char ch)
{
	if (ch == '>' || ch == '<')
		return (1);
	return (0);
}

int	count_elems(char **args)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (args && args[++i])
		len++;
	return (len);
}

char	**cmd_split(char **array, t_cmds *cmd)
{
	char	**args;
	int		i;

	i = 0;
	if (array && array[0])
	{
		cmd->cmd = ft_strdup(array[0]);
		args = malloc(sizeof(char *) * (count_elems(array) + 1));
		while (array[i])
		{
			args[i] = ft_strdup(array[i]);
			i++;
		}
		args[i] = NULL;
		return (args);
	}
	else
		return (NULL);
}
