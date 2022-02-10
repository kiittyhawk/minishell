/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env_finders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:31:39 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/10 16:59:22 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_first(t_env **env)
{
	char	*str;
	t_env	*tmp;

	tmp = *env;
	str = ft_strdup(tmp->key);
	tmp = tmp->next;
	while (tmp)
	{
		if (is_more(str, tmp->key) == 1 && ft_strcmp("_", tmp->key))
		{
			free(str);
			str = ft_strdup(tmp->key);
		}
		tmp = tmp->next;
	}
	// printf("%s\n", str);
	return (str);
}

char	*find_last(t_env **env)
{
	t_env	*tmp;
	char	*str;

	tmp = *env;
	str = ft_strdup(tmp->key);
	while (tmp)
	{
		if (is_more(str, tmp->key) == 2 && ft_strcmp("_", tmp->key))
		{
			free(str);
			str = ft_strdup(tmp->key);
		}
		tmp = tmp->next;
	}
	return (str);
}

char	*find_next(char **keys, t_env **env, int i)
{
	char	*str;
	t_env	*tmp;

	tmp = *env;
	str = find_last(&tmp);
	while (tmp)
	{
		if ((is_more(str, tmp->key) == 1) && (is_more(tmp->key, keys[i - 1]) == 1) && ft_strcmp("_", tmp->key))
		{
			free(str);
			str = ft_strdup(tmp->key);
		}
		tmp = tmp->next;
	}
	return (str);
}
