/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:50:42 by jgyles            #+#    #+#             */
/*   Updated: 2022/03/06 17:11:05 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	wrong_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n'))
		i++;
	if (line[i] && line[i] == '|')
		return (1);
	while (line[i])
	{
		if (line[i] == '|')
		{
			i++;
			if (line[i] && line[i] == '|')
				return (0);
			while (line[i] == ' ')
				i++;
			if (line[i] == '|' || line [i] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	double_semicolon(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ';' && line[i + 1] == ';')
			return (1);
	}
	return (0);
}

int	wrong_semicolon(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n'))
		i++;
	if (line[i] && line[i] == ';')
		return (1);
	return (0);
}

int	unclose_quotes(char *line)
{
	int	i;

	i = -1;
	while (line [++i])
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] && line[i] != '\'')
				i++;
			if (line[i] != '\'')
				return (1);
		}
	}
	return (0);
}

int	unclose_double_quotes(char *line)
{
	int	i;

	i = -1;
	while (line [++i])
	{
		if (line[i] == '\"')
		{
			i++;
			while (line[i] != '\"' && line[i])
				i++;
			if (line[i] != '\"')
				return (1);
		}
	}
	return (0);
}

char	*check_quot(char *line)
{
	if (unclose_quotes(line))
		return ("\'");
	else if (unclose_double_quotes(line))
		return ("\"");
	else
		return (NULL);
}

char	*search_err(char *line)
{
	if (line[0] == '|' && line[1] == '|')
		return ("||");
	else if (wrong_pipe(line))
		return ("|");
	else if (double_semicolon(line))
		return (";;");
	else if (wrong_semicolon(line))
		return (";");
	else if (wrong_redirects(line))
		return (wrong_redirects(line));
	else if (empty_redirects(line))
		return ("newline");
	else
		return (NULL);
}
