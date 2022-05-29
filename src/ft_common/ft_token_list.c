/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:58:33 by llornel           #+#    #+#             */
/*   Updated: 2022/03/23 20:48:51 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_list	g_token_list[] = {
{TOKEN_WILDCARD, WORD_WILDCARD},
{TOKEN_DQUOTE, WORD_DQUOTE},
{TOKEN_SQUOTE, WORD_SQUOTE},
{TOKEN_LESS, WORD_LESS},
{TOKEN_GREAT, WORD_GREAT},
{TOKEN_PIPE, WORD_PIPE},
{TOKEN_SEMI, WORD_SEMI},
{TOKEN_AND, WORD_AND},
{TOKEN_NEWLINE, WORD_NEWLINE},
{TOKEN_LBRACE, WORD_LBRACE},
{TOKEN_RBRACE, WORD_RBRACE},
{TOKEN_LPAREN, WORD_LPAREN},
{TOKEN_RPAREN, WORD_RPAREN},
{TOKEN_AND_AND, WORD_AND_AND},
{TOKEN_OR_OR, WORD_OR_OR},
{TOKEN_DGREAT, WORD_DGREAT},
{TOKEN_DLESS, WORD_DLESS},
{TOKEN_LESS_AND, WORD_LESS_AND},
{TOKEN_DLESS_LESS, WORD_DLESS_LESS},
{TOKEN_GREAT_AND, WORD_GREAT_AND},
{TOKEN_DSEMI, WORD_DSEMI},
{TOKEN_SEMI_AND, WORD_SEMI_AND},
{TOKEN_DSEMI_AND, WORD_DSEMI_AND},
{TOKEN_DLESS_DASH, WORD_DLESS_DASH},
{TOKEN_AND_GREAT, WORD_AND_GREAT},
{TOKEN_AND_DGREAT, WORD_AND_DGREAT},
{TOKEN_LESS_GREAT, WORD_LESS_GREAT},
{TOKEN_GREAT_PIPE, WORD_GREAT_PIPE},
{TOKEN_PIPE_AND, WORD_PIPE_AND},
{TOKEN_EOF, WORD_EOF},
{0, (char *) NULL}
};

char	*ft_find_word_in_list(int code)
{
	int	i;

	if (code == 0)
		return (WORD_EMPTY);
	if (code == 1)
		return (WORD_WORD);
	i = 0;
	while (g_token_list[i].word)
	{
		if (g_token_list[i].code == code)
			return (g_token_list[i].word);
		i++;
	}
	return (WORD_WORD);
}

int	ft_find_code_in_list(char *word)
{
	int	i;

	if (word == NULL || ft_strisempty(word))
		return (TOKEN_EMPTY);
	i = 0;
	while (g_token_list[i].code)
	{
		if (ft_strcmp(g_token_list[i].word, word) == 0)
			return (g_token_list[i].code);
		i++;
	}
	return (TOKEN_WORD);
}

int	ft_get_code_word(char *word)
{
	int		code;
	char	*name;

	if (word == NULL || ft_strisempty(word))
		return (TOKEN_EMPTY);
	if (word[0] == TOKEN_DQUOTE)
		return (TOKEN_DQUOTE);
	else if (word[0] == TOKEN_SQUOTE)
		return (TOKEN_SQUOTE);
	name = ft_strdup(word);
	code = ft_find_code_in_list(name);
	ft_memdel(name);
	return (code);
}

char	*ft_get_word_code(int code)
{
	char	*name;

	if (code == -1)
		return (WORD_NONE);
	if (code == 0)
		return (WORD_EMPTY);
	if (code == 1)
		return (WORD_WORD);
	if (code == TOKEN_DQUOTE)
		return (WORD_DQUOTE);
	else if (code == TOKEN_SQUOTE)
		return (WORD_SQUOTE);
	name = ft_find_word_in_list(code);
	return (name);
}
