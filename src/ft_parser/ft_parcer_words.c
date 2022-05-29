/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 20:33:38 by llornel           #+#    #+#             */
/*   Updated: 2022/03/25 13:43:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_lstadd_command(t_list **commands, int type, t_list *words,
						t_list *redirects)
{
	t_command	*command_new;

	if (ft_lstsize(words) > 0 || ft_lstsize(redirects) > 0)
	{
		command_new = ft_command_new(type, words, redirects);
		if (command_new == NULL)
			return (EXIT_FAILURE);
		ft_lstadd_back(commands, ft_lstnew(command_new));
	}
	return (EXIT_SUCCESS);
}

static int	ft_parcer_words_loop(t_list *words, t_list **new_words,
							t_list **newredirects)
{
	t_word	*word;
	int		ret;

	ret = EXIT_SUCCESS;
	while (words)
	{
		word = (t_word *)words->content;
		if (ft_str_is_redirect(word->data))
			ret = ft_parcer_redirect(&words, newredirects, word->type);
		else if (ft_str_is_heredoc(word->data))
			ret = ft_parcer_heredoc(&words, newredirects, word->type);
		else
		{
			ft_word_add(new_words, word->type, word->data, word->original);
			words = words->next;
		}
		if (ret != EXIT_SUCCESS)
			return (ret);
	}
	return (ret);
}

int	ft_parcer_words(t_list **commands, t_list *words, int type)
{
	t_list	*new_words;
	t_list	*new_redirects;
	int		ret;

	new_words = (t_list *) NULL;
	new_redirects = (t_list *) NULL;
	ret = ft_parcer_words_loop(words, &new_words, &new_redirects);
	if (ret != EXIT_SUCCESS)
		return (ret);
	ret = ft_lstadd_command(commands, type, new_words, new_redirects);
	return (ret);
}
