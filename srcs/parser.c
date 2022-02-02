/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:30:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/02 20:14:08 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax(char *line)
{
	char	*err;

	err = search_err(line);
	if (!ft_strcmp(err, "\'") || !ft_strcmp(err, "\""))
	{
		printf("minishell: unexpected EOF while looking for matching `%s\'\n", err);
		return (1);
	}
	else
	{
		printf("minishell: syntax error near unexpected token `%s'\n", err);
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

char	*replace_env(char *line, int start, char *key, char *value)
{
	int		i;
	int		j;
	int		k;
	int		res_len;
	char	*result;

	i = 0;
	j = 0;
	res_len = ft_strlen(line) - ft_strlen(key) + ft_strlen(value);
	result = malloc(sizeof(char) * res_len + 1);
	while (i < start)
	{
		result[i] = line[i];
		i++;
	}
	k = i + ft_strlen(key) + 1;
	while (value[j])
		result[i++] = value[j++];
	while (line[k])
		result[i++] = line[k++];
	result[i] = '\0';
	return (result);
}

char	*get_env(char *line, t_env *env, int i) /* нужно передавать индекс через указатель, чтобы вернуть конечное
значение индекса обратно вызывающей функции*/
{
	char	*key;
	char	*value;
	int		len;
	int		start;

	i++;
	len = 0;
	start = i;
	while (line[i] && (line[i] == '_' || ft_isalpha(line[i])))
		len++;
	key = ft_substr(line, start, len);
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			value = env->value;
			break ;
		}
		env = env->next;
	}
	line = replace_env(line, start, key, value);
	free(key);
	return (line);
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
			quotes_handler();
		}
		if (line[i] == '\"')
		{
			double_quotes_handler();
		}
		if (line[i] == '$' && line[i + 1] == '?')
		{
			return_err();
		}
		if (line[i] == '$' && (line[i + 1] == '_' || ft_isalpha(line[i + 1])))
		{
			get_env(line, &data->env, i);
		}
		i++;
	}
	return (line);
}

char	*parse_line(char *line, t_all *data)
{
	line = line_handler(line, data);
}

int	parser(char *line, t_all *data)
{
	t_cmds	*tmp;

	if (!line)
		return (1);
	if (check_syntax(line))
		return (1);
	data->cmd = new_cmd();
	tmp = data->cmd;
	line = parse_line(line, data);
	return (0);
}
