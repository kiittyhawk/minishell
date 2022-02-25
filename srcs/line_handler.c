/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:27:55 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/24 15:44:23 by jgyles           ###   ########.fr       */
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
	// int		start;
	// int		j;
	// char	*new_line;

	// start = *i;
	// j = start;
	// new_line = malloc(ft_strlen(line) - 1);
	(*i)++;
	// while (j < start)
	// {
		// new_line[j] = line[j];
		// j++;/
	// }
	while (line[*i] != '\'')
	{
		// new_line[j] = line[*i];
		(*i)++;
		// j++;
	}
	// start = j;
	// (*i)++;
	// while (line[*i])
	// {
		// new_line[j] = line[*i];
	// 	(*i)++;
	// 	j++;
	// }
	// new_line[j] = '\0';
	// *i = start - 1;
	// return (new_line);
}

// void	remove_double_quotes(char *line, int *i)
// {
// 	int		start;
// 	int		j;
// 	// char	*new_line;

// 	start = *i;
// 	j = 0;
// 	// new_line = malloc(ft_strlen(line) - 1);
// 	(*i)++;
// 	while (j < start)
// 	{
// 		// new_line[j] = line[j];
// 		j++;
// 	}
// 	while (line[*i] != '"')
// 	{
// 		// new_line[j] = line[*i];
// 		(*i)++;
// 		j++;
// 	}
// 	start = *i;
// 	// (*i)++;
// 	// while (line[*i])
// 	// {
// 		// new_line[j] = line[*i];
// 	// 	(*i)++;
// 	// 	j++;
// 	// }
// 	// new_line[j] = '\0';
// 	*i = start - 1;
// 	// return (new_line);
// }

char	*double_quotes_handler(char *line, int *i, t_all *data)
{
	// int	start;

	// start = *i;
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
	// *i = start;
	// remove_double_quotes(line, i);
	return (line);
}
