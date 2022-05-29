/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_special.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 22:47:37 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 16:41:08 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_line_sep(t_list **lst, char *str, int *offset)
{
	char	*tmp;
	int		type;

	*offset = 1;
	if (ft_str_is_double_token(str))
		*offset += 1;
	tmp = ft_substr(str, 0, *offset);
	type = ft_get_code_word(tmp);
	ft_word_add(lst, type, tmp, tmp);
	ft_memdel(tmp);
}

static void	ft_line_special(t_list **lst, char *str, char *sep)
{
	char	*start;
	char	*tmp;
	int		offset;
	int		type;

	while (*str != '\0')
	{
		if (ft_strchr(sep, *str) != NULL )
		{
			ft_line_sep(lst, str, &offset);
			str += offset;
		}
		else
		{
			start = str;
			while (ft_strchr(sep, *str) == NULL)
				str++;
			tmp = ft_substr(start, 0, str - start);
			type = ft_get_code_word(tmp);
			ft_word_add(lst, type, tmp, tmp);
			ft_memdel(tmp);
		}
	}
}

t_list	*ft_lexer_special(t_list *words)
{
	t_list	*newlst;
	t_list	*tmplst;
	t_word	*word;

	newlst = (t_list *) NULL;
	tmplst = words;
	while (words)
	{
		word = (t_word *)words->content;
		if (word->data[0] == TOKEN_DQUOTE)
			ft_word_add(&newlst, TOKEN_DQUOTE, word->data, word->original);
		else if (word->data[0] == TOKEN_SQUOTE)
			ft_word_add(&newlst, TOKEN_SQUOTE, word->data, word->original);
		else
			ft_line_special(&newlst, word->data, BREAK_CHARS);
		words = words->next;
	}
	ft_lstclear(&tmplst, ft_word_free);
	return (newlst);
}
