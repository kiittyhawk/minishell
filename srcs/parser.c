/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:30:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/25 14:18:25 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*проверка на ошибке в синтаксисе*/
int	check_syntax(char *line, t_all *data)
{
	if (search_err(line))
	{
		data->err = 127;
		printf("minishell: unexpected EOF while looking for matching `%s\'\n", search_err(line));
		return (1);
	}
	else if (check_quot(line))
	{
		data->err = 127;
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
	node->redirect = NULL;
	node->flag = 0;
	node->args = NULL;
	node->next = NULL;
	return (node);
}

/*экранирование*/
char	*line_handler(char *line, t_all *data, int *i)
{
	while (line[*i] && line[*i] != '|')
	{
		while (line[*i] && line[*i] == ' ')
			(*i)++;
		if (line[*i] == '\'')
			quotes_handler(line, i);
		if (line[*i] == '"')
			line = double_quotes_handler(line, i, data);
		if (line[*i] == '$' && (line[*i + 1] == '_' || ft_isalpha(line[*i + 1])))
			line = get_env(line, *data->env, i);
		if (line[*i] == '$' && line[*i + 1] == '?')
			line = return_err(line, i, data);
		if (line[*i] == '>' || line[*i] == '<')
			parse_redir(line, i, data);
		if (line[*i] == '|')
			data->cmd_count++;
		else
			(*i)++;
	}
	return (line);
}

/*парсит на строки до пайпа, потом отправляет все в списки*/
char	*parse_line(char *line, t_all *data, t_cmds *cmd)
{
	int		i;
	int		start;
	char	*new_cmd;
	char	*str;
	int		j;

	i = 0;
	start = 0;
	str = NULL;
	if (line[i] && line[i] == '|')
	{
		i++;
		start++;
	}
	line = line_handler(line, data, &i);
	if (line[i] && line[i] == '|')
		new_cmd = ft_substr(line, start, i - 1);
	else
		new_cmd = ft_substr(line, start, i);
	cmd->args = cmd_split(split_with_quotes(new_cmd, ' '), cmd);
	free(new_cmd);
	j = i;
	while (line[j])
		j++;
	str = ft_substr(line, i, j - i);
	return (str);
}

int	parser(char *line, t_all *data)
{
	t_cmds	*tmp;

	if (!line && !(*line))
		return (1);
	if (check_syntax(line, data))
		return (1);
	data->cmd = new_cmd();
	data->cmd_count = 1;
	tmp = data->cmd;
	line = parse_line(line, data, data->cmd);
	while (line[0] && line[0] == '|')
	{
		data->cmd->next = new_cmd();
		data->cmd = data->cmd->next;
		data->cmd_count++;
		line = parse_line(line, data, data->cmd);
	}
	data->cmd = tmp;
	free(line);
	return (0);
}
