/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:47:45 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/25 16:14:16 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_buildin(t_env **envp, char **args)
{
	t_env	*tmp;

	tmp = *envp;
	if (args && args == NULL)
		while (tmp)
		{
			printf("%s%s%s\n", tmp->key, tmp->sep, tmp->value);
			tmp = tmp->next;
		}
	else if (args && args[0])
	{
		printf("env: \'%s\': No such file or directory\n", args[0]);
	}
}
