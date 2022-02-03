/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:30:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/03 19:28:51 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax(char *line)
{
	if (search_err(line))
	{
		printf("minishell: unexpected EOF while looking for matching `%s\'\n", search_err(line));
		return (1);
	}
	else if (check_quot(line))
	{
		printf("minishell: syntax error near unexpected token `%s'\n", check_quot(line));
		return (1);
	}
	return (0);
}

t_cmds	*new_cmd(void)
{
	t_cmds	*node;

	node = malloc(sizeof(t_cmds));
	node->cmd = NULL;
	node->built = 0;
	node->next = NULL;
	return (node);
}

char	*line_handler(char *line, t_all *data)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '|')
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '\'')
		{
			line = quotes_handler(line, &i);
		}
		if (line[i] == '"')
		{
			line = double_quotes_handler(line, &i, data);
		}
		if (line[i] == '$' && line[i + 1] == '?')
		{
			// return_err();
		}
		if (line[i] == '$' && (line[i + 1] == '_' || ft_isalpha(line[i + 1])))
		{
			line = get_env(line, *data->env, &i);
		}
		i++;
	}
	return (line);
}

char	*parse_line(char *line, t_all *data)
{
	line = line_handler(line, data);
	return (line);
}

int	parser(char *line, t_all *data)
{
	// t_cmds	*tmp;

	if (!line)
		return (1);
	printf("%s\n", line);
	if (check_syntax(line))
		return (1);
	data->cmd = new_cmd();
	// tmp = data->cmd;
	line = parse_line(line, data);
	printf("%s\n", line);
	return (0);
}
