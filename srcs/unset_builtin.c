/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_buildin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:41:26 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/21 16:55:59 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	unset(t_all *data, char **args)
{
	(void)data;
	(void)args;
	// t_env	*tmp;
	// t_env	*tmp2;
	// int		i;

	// tmp = *data->env;
	// tmp2 = tmp->next;
	// i = 0;
	// while (args[i])
	// {
	// 	while (tmp && tmp->next->next != NULL)
	// 	{
	// 		if (!ft_strcmp(tmp->key, args[i]))
	// 		{
	// 			// printf("%s\n", tmp->next->key);
	// 			tmp2
	// 		}
	// 		// if (tmp->next->next == NULL && !ft_strcmp(tmp->next->key, args[i]))
	// 		// {
	// 		// 	tmp->next = NULL;
	// 		// }
	// 		tmp = tmp->next;
	// 		tmp2 = tmp->next->next;
	// 	}
	// 	i++;
	// 	tmp = *data->env;
	// 	// printf("%s\n", tmp->key);
	// }
	return (0);
}
