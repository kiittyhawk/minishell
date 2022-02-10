/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_buildin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:41:26 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/10 16:54:52 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unset(t_all *data, char *arg)
{
	t_env	*tmp;
	t_env	*tmp2;
	int		flag;

	tmp = *data->env;
	tmp2 = *data->env;
	flag = 0;
	if (arg)
	{
		while (tmp->next->key)
		{
			if (!ft_strcmp(tmp->next->key, arg))
			{
				tmp2 = tmp->next->next;
				tmp->next = tmp2;
				flag = 1;
				break ;
			}
			tmp = tmp->next;
		}
		if (!flag)
		{
			printf("minishell: unset: `%s': not a valid identifier\n", arg);
			return (1);
		}
		else
			return (0);
		data->env = &tmp;
	}
	else
		return (0);
}
