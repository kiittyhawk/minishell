/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:44:19 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/24 18:44:51 by jgyles           ###   ########.fr       */
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
	while (args && args[++i] && !is_redirect(args[i][0]))
		len++;
	return (len);
}

char	**check_redir(char **array)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (is_redirect(array[i][j]))
			{
				array[i][j] = '\0';
				flag = 1;
				break ;
			}
			j++;
		}
		i++;
		if (flag)
			break ;
	}
	if (flag)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	return (array);
}

char	**cmd_split(char **array, t_cmds *cmd)
{
	char	**args;
	int		i;

	i = 1;
	if (array)
	{
		array = check_redir(array);
		args = malloc(sizeof(char *) * (count_elems(array) + 1));
		cmd->cmd = array[0];
		while (array[i] && !is_redirect(array[i][0]))
		{
			args[i - 1] = ft_strdup(array[i]);
			i++;
		}
		args[i] = NULL;
		return (args);
	}
	else
		return (NULL);
}
