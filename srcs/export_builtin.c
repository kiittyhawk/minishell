/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:04:37 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 19:37:24 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	sorting(t_env **env, int marker)
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
	while (i < count)
	{
		keys[i] = find_next(keys, &tmp, i);
		if (!ft_strcmp(keys[i], find_last(&tmp)))
			break ;
		i++;
	}
	if (marker == 1)
		export_output(keys, &tmp);
	free(keys);
}

int	count_sym(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		count++;
		i++;
	}
	return (count);
}

int	skip_empty(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i] && line[i] != '=')
	{
		if (line[i] && line[i] == ' ')
			flag = 1;
		i++;
	}
	return (flag);
}

void	export_buildin(t_all *data, char **args)
{
	int	i;

	i = 1;
	if (args && args[1] == NULL)
		sorting(data->env, 1);
	else
	{
		while (args && args[i])
		{
			if (skip_empty(args[i]) || ft_isdigit(args[i][0]))
			{
				ft_putstr_fd("minishell: export: `", STDERR_FILENO);
				ft_putstr_fd(args[i], STDERR_FILENO);
				ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
				data->err = 1;
			}
			else
			{
				add_env(args[i], data->env, data);
				sorting(data->env, 0);
			}
			i++;
		}
	}
}
