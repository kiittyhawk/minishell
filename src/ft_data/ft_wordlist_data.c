/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlist_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:45:33 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 14:44:12 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_wordlist	*ft_wordlist_new(int type, t_list *words)
{
	t_wordlist	*wordlist;

	wordlist = malloc(sizeof(t_wordlist));
	if (wordlist == NULL)
		return (NULL);
	wordlist->type = type;
	wordlist->words = words;
	return (wordlist);
}

t_wordlist	*ft_wordlist_copy(t_wordlist *wordlist)
{
	t_wordlist	*copy;
	t_list		*words;

	if (wordlist == NULL)
		return (NULL);
	words = ft_lstdup(wordlist->words, ft_word_dup);
	copy = ft_wordlist_new(wordlist->type, words);
	if (copy == NULL)
	{
		ft_lstclear(&words, ft_word_free);
		return (NULL);
	}
	return (copy);
}

void	*ft_wordlist_dup(void *ptr)
{
	t_wordlist	*wordlist;
	t_wordlist	*copy;

	wordlist = (t_wordlist *)ptr;
	copy = ft_wordlist_copy(wordlist);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_wordlist_free(void *ptr)
{
	t_wordlist	*wordlist;

	wordlist = (t_wordlist *)ptr;
	if (wordlist == NULL)
		return ;
	ft_lstclear(&wordlist->words, ft_word_free);
	ft_memdel(wordlist->words);
	ft_memdel(wordlist);
}

void	ft_wordlist_add(t_list **wordlist, t_list *words, int type)
{
	t_wordlist	*wordlist_new;
	t_list		*words_copy;

	words_copy = ft_lstdup(words, ft_word_dup);
	wordlist_new = ft_wordlist_new(type, words_copy);
	ft_lstadd_back(wordlist, ft_lstnew(wordlist_new));
}
