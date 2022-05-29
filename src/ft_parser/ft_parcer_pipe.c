/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:45:03 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 14:42:25 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_handle_pipe_end(t_list **commands, t_list *words, int type)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (ft_lstsize(words) > 0)
	{
		ret = ft_parcer_words(commands, words, type);
		ft_lstclear(&words, ft_word_free);
	}
	return (ret);
}

static int	ft_handle_pipe(t_list **commands, t_list *lst)
{
	t_word	*word;
	t_list	*words;
	t_list	*redirects;
	int		ret;

	words = (t_list *) NULL;
	redirects = (t_list *) NULL;
	while (lst)
	{
		word = (t_word *)lst->content;
		if (ft_str_is_pipe(word->data))
		{
			ret = ft_parcer_words(commands, words, word->type);
			ft_lstclear(&words, ft_word_free);
			if (ret != EXIT_SUCCESS)
				return (ret);
		}
		else
			ft_word_add(&words, word->type, word->data, word->original);
		lst = lst->next;
	}
	ret = ft_handle_pipe_end(commands, words, TOKEN_NONE);
	return (ret);
}

int	ft_parcer_pipe(t_list **cmdlist, t_list *wordslist)
{
	t_wordlist	*curr_wordlist;
	t_list		*commands;
	int			ret;

	commands = (t_list *) NULL;
	ret = EXIT_SUCCESS;
	while (wordslist)
	{
		curr_wordlist = (t_wordlist *)wordslist->content;
		ret = ft_handle_pipe(&commands, curr_wordlist->words);
		ft_cmdlist_add(cmdlist, commands, curr_wordlist->type);
		ft_lstclear(&commands, ft_command_free);
		if (ret != EXIT_SUCCESS)
			break ;
		wordslist = wordslist->next;
	}
	return (ret);
}
