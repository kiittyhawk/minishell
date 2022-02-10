/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_buildin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:04:37 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/10 16:55:53 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

static void	sorting(t_env **env)
{
	t_env	*tmp;
	char	**keys;
	int		i;
	int		count;

	tmp = *env;
	i = 1;
	count = 0;
	keys = set_array(&tmp, &count);
	keys[0] = find_first(&tmp);
	// printf("%s\n", keys[0]);
	while (i < count)
	{
		keys[i] = find_next(keys, &tmp, i);
		// printf("%s\n", keys[i]);
		if (!ft_strcmp(keys[i], find_last(&tmp)))
			break ;
		i++;
	}
	export_output(keys, &tmp);
	free(keys);
}

char	*skip_empty(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strdup(line);
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		str[j] = line[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

void	export_buildin(t_all *data, char *arg)
{
	if (!arg)
		sorting(data->env);
	else
	{
		arg = skip_empty(arg);
		add_env(arg, data->env);
		sorting(data->env);
	}
}
