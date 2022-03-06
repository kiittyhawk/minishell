/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:55:56 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 18:49:09 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_str(char **envp)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while(envp[++i])
		len++;
	return (len);
}

char	**create_array_envp(char **envp, t_all *data)
{
	int		i;
	char	**array;

	i = -1;
	array = malloc(sizeof(char *) * (count_str(envp) + 1));
	if (!array)
		malloc_err(errno, data);
	while (envp[++i])
		array[i] = ft_strdup(envp[i]);
	array[i] = NULL;
	return (array);
}
