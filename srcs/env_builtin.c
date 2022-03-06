/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:47:45 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/04 18:12:11 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	env_buildin(t_env **envp, char **args)
{
	t_env	*tmp;

	tmp = *envp;
	if (args && args[1] == NULL)
		while (tmp)
		{
			printf("%s%s%s\n", tmp->key, tmp->sep, tmp->value);
			tmp = tmp->next;
		}
	else if (args && args[0])
	{
		ft_putstr_fd("env: \'", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putstr_fd("\': No such file or directory\n", STDERR_FILENO);
		return (127);
	}
	return (0);
}
