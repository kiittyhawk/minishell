/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:47:45 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/09 13:01:32 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_buildin(t_env **envp)
{
	t_env	*tmp;

	tmp = *envp;
	while (tmp)
	{
		printf("%s%s%s\n", tmp->key, tmp->sep, tmp->value);
		tmp = tmp->next;
	}
}
