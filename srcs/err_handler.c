/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:11:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/02 20:01:56 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*return_err(char *line, int *i, t_all *data)
{
	char	*err;

	err = ft_itoa(data->err);
	line = replace_env(line, *i, "?", err);
	return (line);
}
