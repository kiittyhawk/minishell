/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:45:03 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 21:53:13 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parcer_command(t_list **wordlist, t_list *words)
{
	t_list	*new_words;
	t_word	*word;
	int		type;

	new_words = (t_list *) NULL;
	while (words)
	{
		word = (t_word *)words->content;
		type = ft_get_code_word(word->data);
		if (ft_str_is_command_sep(word->data))
		{
			ft_wordlist_add(wordlist, new_words, type);
			ft_lstclear(&new_words, ft_word_free);
		}
		else
			ft_word_add(&new_words, type, word->data, word->original);
		words = words->next;
	}
	if (ft_lstsize(new_words) > 0)
	{
		ft_wordlist_add(wordlist, new_words, TOKEN_WORD);
		ft_lstclear(&new_words, ft_word_free);
	}
	return (EXIT_SUCCESS);
}
