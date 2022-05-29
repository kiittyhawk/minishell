/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:12:07 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 19:04:48 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_expand_redirect_str(t_redirect *redirect, char *data)
{
	if (redirect->original[0] == TOKEN_DQUOTE
		|| redirect->original[0] == TOKEN_SQUOTE)
		ft_strset((void **)&redirect->data, data);
	else if (ft_strlen(data) == 0)
	{
		ft_strset((void **)&redirect->data, NULL);
		ft_memdel(data);
	}
	else
		ft_strset((void **)&redirect->data, data);
}

void	ft_expand_word_iter(void *ptr)
{
	t_word	*word;
	char	*tmp;

	word = (t_word *)ptr;
	if (word == NULL || word->data == NULL)
		return ;
	tmp = ft_expand_dollar(word->data);
	if (word->original[0] == TOKEN_DQUOTE || word->original[0] == TOKEN_SQUOTE)
		ft_strset((void **)&word->data, tmp);
	else
	{	
		if (ft_strlen(tmp) == 0)
			word->type = 0;
		else if (ft_strchr(tmp, '=') != NULL)
			word->type = -1;
		ft_strset((void **)&word->data, tmp);
	}
}

void	ft_expand_redirect_iter(void *ptr)
{
	t_redirect	*redirect;
	char		*tmp;

	redirect = (t_redirect *)ptr;
	if (redirect == NULL || redirect->data == NULL)
		return ;
	if (ft_is_redirect(redirect->type))
	{
		tmp = ft_expand_dollar(redirect->data);
		ft_expand_redirect_str(redirect, tmp);
	}
	else if (ft_is_heredoc(redirect->type))
	{
		if (ft_strsep(redirect->original, QUOTE_CHARS) != -1)
			return ;
		tmp = ft_expand_heredoc_data(redirect->data);
		ft_expand_redirect_str(redirect, tmp);
	}
}

void	ft_expand_wildcard_iter(void *ptr)
{
	t_word	*word;
	char	*tmp;

	word = (t_word *)ptr;
	if (word == NULL)
		return ;
	if (ft_striswildcard(word->data) && ft_iswildcard(word->type))
	{
		tmp = word->data;
		word->data = ft_get_dir_items(".");
		ft_memdel(tmp);
	}
}
