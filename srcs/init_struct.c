/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:16:28 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/25 15:57:30 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_struct(t_all **data)
{
	(*data) = (t_all *)malloc(sizeof(t_all));
	if (!(*data))
		return ;
	(*data)->env = (t_env **)malloc(sizeof(t_env *));
	(*data)->cmd = NULL;
	(*data)->cmd_count = 0;
	(*data)->err = 0;
	(*data)->out = 0;
	(*data)->fd = NULL;
}

t_env	**init_env()
{
	t_env	**tmp;

	tmp = (t_env **)malloc(sizeof(t_env *));
	if (!tmp)
	{
		exit(1);
	}
	return (tmp);
}
