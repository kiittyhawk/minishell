/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:30:41 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/01 19:07:24 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_syntax(char *line)
{
	char	*err;

	err = search_err(line);
	if (!ft_strcmp(err, "\'") || !ft_strcmp(err, "\""))
	{
		printf("minishell: unexpected EOF while looking for matching `%s\'\n", err);
		return (1);
	}
	else
	{
		printf("minishell: syntax error near unexpected token `%s'\n", err);
		return (1);
	}
	return (0);
}

int	parser(char *line)
{
	if (!line)
		return (1);
	if (check_syntax(line))
		return (1);
	return (0);
}
