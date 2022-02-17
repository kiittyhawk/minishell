/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:13:52 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/16 17:14:08 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	increment(t_env *envp)
{
	int	lvl;

	lvl = ft_atoi(envp->value) + 1;
	free(envp->value);
	envp->value = ft_itoa(lvl);
}

/*когда мы запускаем свой баш в системной баше, shlvl должен инкрементироваться*/
void	shlvl_increment(t_env *envp)
{
	t_env	*env;

	env = envp;
	while (env)
	{
		if (!ft_strcmp(env->key, "SHLVL"))
		{
			increment(env);
			break ;
		}
		env = env->next;
	}
}
