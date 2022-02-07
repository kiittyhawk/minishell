/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:11:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/04 14:16:50 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*return_err(char *line, int *i, t_all *data)
{
	// char	*new_line;
	char	*err;
	// int		j;
	// int		index;

	err = ft_itoa(data->err);
	line = replace_env(line, *i, "?", err);
	// new_line = malloc(ft_strlen(line) - 1 + ft_strlen(err));
	// j = -1;
	// while (j < *i)
	// {
	// 	new_line[j] = line[j];
	// 	j++;
	// }
	// new_line = ft_strjoin(new_line, err);
	// j += ft_strlen(err);
	// index = j;
	// *i += 2;
	// while (line[*i])
	// {
	// 	new_line[j] = line[*i];
	// 	j++;
	// 	(*i)++;
	// }
	// new_line[j] = '\0';
	// *i = index;
	return (line);
}
