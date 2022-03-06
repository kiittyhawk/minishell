/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:27:55 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 15:38:17 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*replace_env(char *line, int start, char *key, char *value)
{
	int		i;
	int		j;
	int		k;
	int		res_len;
	char	*result;

	i = 0;
	j = 0;
	if (value)
		res_len = ft_strlen(line) - ft_strlen(key) + ft_strlen(value);
	else
		res_len = ft_strlen(line) - ft_strlen(key);
	result = malloc(sizeof(char) * res_len);
	if (!result)
		return (NULL);
	while (i < start)
	{
		result[i] = line[i];
		i++;
	}
	k = i + ft_strlen(key) + 1;
	while (value && value[j])
		result[i++] = value[j++];
	while (line[k])
		result[i++] = line[k++];
	result[i] = '\0';
	return (result);
}

char	*get_env(char *line, t_env *env, int *i)
{
	char	*key;
	char	*value;
	int		start;

	start = *i;
	(*i)++;
	value = NULL;
	while (line[*i] && (line[*i] == '_' || ft_isalpha(line[*i])))
		(*i)++;
	key = ft_substr(line, start + 1, *i - start - 1);
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
	if (value)
		*i = start - 2 + ft_strlen(value);
	else
		*i = start - 2 + ft_strlen(key);
	free(key);
	return (line);
}

void	quotes_handler(char *line, int *i)
{
	(*i)++;
	while (line[*i] != '\'')
		(*i)++;
}

char	*double_quotes_handler(char *line, int *i, t_all *data)
{
	(*i)++;
	while (line[*i] && line[*i] != '"')
	{
		if (line[*i] == '$' && (line[*i + 1] == '_' || ft_isalpha(line[*i + 1])))
		{
			line = get_env(line, *data->env, i);
		}
		if (line[*i] == '$' && line[*i + 1] == '?')
		{
			line = return_err(line, i, data);
		}
		(*i)++;
	}
	return (line);
}
