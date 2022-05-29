/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:20:45 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 13:20:47 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_redirection_filename(t_list **lst)
{
	t_word	*word;
	char	*filename;

	filename = (char *) NULL;
	*lst = (*lst)->next;
	while (*lst && ft_strisempty(((t_word *)(*lst)->content)->data) == 1)
		*lst = (*lst)->next;
	while (*lst && ft_strisempty(((t_word *)(*lst)->content)->data) == 0)
	{
		word = (t_word *)(*lst)->content;
		if (ft_str_is_special_token(word->data) || ft_strisempty(word->data))
			break ;
		if (filename == NULL)
			filename = ft_strdup(word->data);
		else
			ft_strset((void **)&filename, ft_strjoin(filename, word->data));
		*lst = (*lst)->next;
	}
	return (filename);
}

int	ft_parcer_heredoc(t_list **lst, t_list **redirects, int type)
{
	t_redirect	*redirect_new;
	char		*filename;
	char		*here_doc_eof;
	char		*here_doc_str;
	int			ret;

	filename = ft_get_redirection_filename(lst);
	if (filename == NULL || *filename == '\0')
		return (EXIT_FAILURE);
	here_doc_eof = ft_expand_heredoc_eof(filename);
	ret = ft_handle_heredoc(here_doc_eof, &here_doc_str);
	redirect_new = ft_redirect_new(type, here_doc_str, filename, here_doc_eof);
	ft_lstadd_back(redirects, ft_lstnew(redirect_new));
	return (ret);
}

int	ft_parcer_redirect(t_list **lst, t_list **redirects, int type)
{
	t_redirect	*redirect_new;
	char		*filename;
	char		*original;

	filename = ft_get_redirection_filename(lst);
	if (filename == NULL || *filename == '\0')
		return (EXIT_FAILURE);
	original = ft_strdup(filename);
	redirect_new = ft_redirect_new(type, filename, original, NULL);
	ft_lstadd_back(redirects, ft_lstnew(redirect_new));
	return (EXIT_SUCCESS);
}
