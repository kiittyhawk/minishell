/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:27:57 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/18 17:01:26 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**set_array(t_env **env, int *count)
{
	char	**keys;
	t_env	*tmp;

	tmp = *env;
	while(tmp)
	{
		if (ft_strcmp("_", tmp->key))
			(*count)++;
		tmp = tmp->next;
	}
	keys = malloc(sizeof(char *) * (*count) + 1);
	return (keys);
}

int	is_more(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] > str2[i])
			return (1);
		if (str1[i] < str2[i])
			return (2);
		if (!str1 && str2)
			return (2);
		if (!str2 && str1)
			return (1);
		i++;
	}
	return (0);
}

void	export_output(char **keys, t_env **env)
{
	t_env	*tmp;
	int		i;
	char	*str;

	tmp = *env;
	i = 0;
	while (keys[i] && ft_strcmp(keys[i], find_last(&tmp)))
	{
		while (tmp)
		{
			if (!is_more(keys[i], tmp->key))
			{
				str = ft_strdup(tmp->key);
				if (tmp->sep)
				{
					str = ft_strjoin(str, tmp->sep);
					if (tmp->value)
					{
						str = ft_strjoin(str, "\"");
						str = ft_strjoin(str, tmp->value);
						str = ft_strjoin(str, "\"");
					}
					else
					{
						str = ft_strjoin(str, "\"\"");
					}
				}
				printf("declare -x %s\n", str);
				i++;
			}
			tmp = tmp->next;
		}
		tmp = *env;
	}
	while (tmp)
	{
		if (keys[i] && !is_more(keys[i], tmp->key))
		{
			str = ft_strdup(tmp->key);
			if (tmp->sep)
			{
				str = ft_strjoin(str, tmp->sep);
				if (tmp->value)
				{
					str = ft_strjoin(str, "\"");
					str = ft_strjoin(str, tmp->value);
					str = ft_strjoin(str, "\"");
				}
				else
				{
					str = ft_strjoin(str, "\"\"");
				}
			}
			printf("declare -x %s\n", str);
			break ;
		}
		tmp = tmp->next;
	}
}
