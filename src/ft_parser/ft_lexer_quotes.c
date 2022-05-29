/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:47:14 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:05:30 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_line_others(char *str, int *start, char *token_name)
{
	char	*tmp;
	int		end;
	int		non_token;

	if (str == NULL)
		return (NULL);
	non_token = 0;
	end = ft_strnsep(str, token_name, *start);
	if (end == -1)
	{
		end = ft_strlen(str) - 1;
		non_token = 1;
	}
	tmp = NULL;
	if (*start <= end)
	{
		tmp = ft_substr(str, *start, end - *start + non_token);
		if (non_token == 0)
			*start = end - 1;
		else
			*start = end;
	}
	return (tmp);
}

char	*ft_get_line_quotes(char *str, int *start, char *token_name)
{
	char	*tmp;
	int		end;
	int		is_token;

	if (str == NULL)
		return (NULL);
	is_token = 1;
	end = ft_strnsep(str, token_name, (*start + 1));
	if (end == -1)
	{
		end = ft_strlen(str) - 1;
		is_token = 0;
	}
	tmp = NULL;
	if (*start <= end)
	{
		tmp = ft_substr(str, *start, end - *start + is_token);
		if (is_token == 0)
			*start = end - 1;
		else
			*start = end;
	}
	return (tmp);
}

char	*ft_get_line_word(char *str, int *start)
{
	char	*tmp;

	if (str[*start] == TOKEN_DQUOTE)
		tmp = ft_get_line_quotes(str, start, WORD_DQUOTE);
	else if (str[*start] == TOKEN_SQUOTE)
		tmp = ft_get_line_quotes(str, start, WORD_SQUOTE);
	else
		tmp = ft_get_line_others(str, start, QUOTE_CHARS);
	return (tmp);
}

t_list	*ft_lexer_quotes(char *input)
{
	t_list	*words;
	char	*data;
	int		type;
	int		start;

	words = (t_list *) NULL;
	start = 0;
	while (input[start])
	{
		data = ft_get_line_word(input, &start);
		type = ft_get_code_word(data);
		ft_word_add(&words, type, data, data);
		ft_memdel(data);
		start++;
	}
	return (words);
}
