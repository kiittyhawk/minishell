/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:45:33 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 14:43:37 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirect	*ft_redirect_new(int type, char *data, char *original,
								char *here_doc_eof)
{
	t_redirect	*redirect;

	redirect = malloc(sizeof(t_redirect));
	if (redirect == NULL)
		return (NULL);
	redirect->type = type;
	redirect->data = data;
	redirect->original = original;
	redirect->here_doc_eof = here_doc_eof;
	return (redirect);
}

t_redirect	*ft_redirect_copy(t_redirect *redirect)
{
	t_redirect	*copy;
	char		*data;
	char		*original;
	char		*here_doc_eof;

	if (redirect == NULL)
		return (NULL);
	data = ft_strdup(redirect->data);
	original = ft_strdup(redirect->original);
	here_doc_eof = ft_strdup(redirect->here_doc_eof);
	copy = ft_redirect_new(redirect->type, data, original, here_doc_eof);
	if (copy == NULL)
	{
		ft_memdel(data);
		ft_memdel(original);
		ft_memdel(here_doc_eof);
		return (NULL);
	}
	return (copy);
}

void	*ft_redirect_dup(void *ptr)
{
	t_redirect	*redirect;
	t_redirect	*copy;

	redirect = (t_redirect *)ptr;
	copy = ft_redirect_copy(redirect);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_redirect_free(void *ptr)
{
	t_redirect	*redirect;

	redirect = (t_redirect *)ptr;
	if (redirect == NULL)
		return ;
	ft_memdel(redirect->data);
	ft_memdel(redirect->original);
	ft_memdel(redirect->here_doc_eof);
	ft_memdel(redirect);
}
