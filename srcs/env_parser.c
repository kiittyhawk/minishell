/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:15:52 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/16 17:17:20 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*init_elem(char *key, char *sep, char *val)
{
	t_env	*elem;

	elem = (t_env *)malloc(sizeof(t_env));
	if (!elem)
		return (NULL);
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

/*принимает строку и добавляет ее к структуре envp*/
void	add_env(char *env, t_env **envp)
{
	int		i;
	char	*key;
	char	*sep;
	char	*val;

	i = 0;
	sep = NULL;
	val = NULL;
	while (env[i] && (env[i] == '_' || ft_isalnum(env[i])))
	{
		i++;
	}
	key = ft_substr(env, 0, i);
	if (ft_strchr(env, '='))
	{
		sep = ft_substr(env, i, 1);
	}
	if (env[i + 1])
	{
		val = ft_strdup(&env[i + 1]);
	}
	add_elem(envp, init_elem(key, sep, val));
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
		add_env(env[i], data->env);
		tmp = data;
	}
	data = tmp;
}
