/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_buildin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:41:26 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/18 17:38:16 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unset(t_all *data, char **args)
{
	t_env	*tmp;
	t_env	*tmp2;
	int		i;

	tmp = *data->env;
	tmp2 = *data->env;
	i = 0;
	while (args[i])
	{
		while (tmp->next->key)
		{
			if (!ft_strcmp(tmp->next->key, args[i]))
			{
				tmp2 = tmp->next->next;
				tmp->next = tmp2;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
		tmp = *data->env;
	}
	return (0);
}
