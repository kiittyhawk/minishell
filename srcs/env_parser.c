/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:15:52 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 19:37:40 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*init_elem(char *key, char *sep, char *val, t_all *data)
{
	t_env	*elem;

	elem = (t_env *)malloc(sizeof(t_env));
	if (!elem)
		malloc_err(errno, data);
	elem->key = key;
	elem->sep = sep;
	elem->value = val;
	elem->pos = 0;
	elem->next = NULL;
	return (elem);
}

void	add_elem(t_env **head, t_env *elem)
{
	t_env	*tmp;

	tmp = *head;
	if (*head)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		*head = elem;
}

int	key_is(char *key, t_env **envp)
{
	t_env	*tmp;

	tmp = *envp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	add_value(char *key, char *sep, char *value, t_env **envp)
{
	t_env	*tmp;

	tmp = *envp;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			break ;
		tmp = tmp->next;
	}
	if (tmp->value)
		free(tmp->value);
	tmp->value = value;
	if (tmp->sep)
		free(tmp->sep);
	tmp->sep = sep;
}

/*принимает строку и добавляет ее к структуре envp*/
void	add_env(char *env, t_env **envp, t_all *data)
{
	int		i;
	char	*key;
	char	*sep;
	char	*val;

	i = 0;
	sep = NULL;
	val = NULL;
	while (env[i] && (env[i] == '_' || ft_isalnum(env[i])))
		i++;
	key = ft_substr(env, 0, i);
	if (ft_strchr(env, '='))
		sep = ft_substr(env, i, 1);
	if (env[i + 1])
		val = ft_strdup(&env[i + 1]);
	if (!key_is(key, envp))
		add_elem(envp, init_elem(key, sep, val, data));
	else
		add_value(key, sep, val, envp);
}

/*перебирает переменные окружения и передает их парсеру*/
void	parse_env(char **env, t_all *data)
{
	int	i;
	t_all	*tmp;

	i = -1;
	tmp = data;
	while (env[++i])
	{
		add_env(env[i], data->env, data);
		tmp = data;
	}
	data = tmp;
}
