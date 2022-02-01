/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_regirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:52:09 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/01 17:52:39 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*first_redirect(char *line)
{
	if (line[1] && line[0] == '<' && line[1] == '<')
		return ("<<");
	else if (line[1] && line[0] == '>' && line[1] == '>')
		return (">>");
	else if (line[0] == '<')
		return ("<");
	else if (line[0] == '>')
		return (">");
	else
		return (NULL);
}

char	*wrong_redirects(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '<' || line[i] == '>')
		{
			i++;
			if (line[i] == '<' || line[i] == '>')
				i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '<' || line[i] == '>')
				return (first_redirect(&line[i]));
		}
	}
	return (NULL);
}

int	empty_redirects(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '>' || line[i] == '<')
		{
			i++;
			if (line[i] == '>' || line [i] == '<')
				i++;
			while (line[i] == ' ')
				i++;
			if (line[i] == '\0')
				return (1);
		}
	}
	return (0);
}
