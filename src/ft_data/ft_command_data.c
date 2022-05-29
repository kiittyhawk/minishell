/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:45:33 by llornel           #+#    #+#             */
/*   Updated: 2022/03/16 20:54:26 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_command_new(int type, t_list *words, t_list *redirects)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->words = words;
	new->redirects = redirects;
	return (new);
}

t_command	*ft_command_copy(t_command *command)
{
	t_command	*copy;
	t_list		*redirects;
	t_list		*words;

	if (command == NULL)
		return (NULL);
	words = ft_lstdup(command->words, ft_word_dup);
	redirects = ft_lstdup(command->redirects, ft_redirect_dup);
	copy = ft_command_new(command->type, words, redirects);
	if (copy == NULL)
	{
		ft_lstclear(&words, ft_word_free);
		ft_lstclear(&redirects, ft_redirect_free);
		return (NULL);
	}
	return (copy);
}

void	*ft_command_dup(void *ptr)
{
	t_command	*command;
	t_command	*copy;

	command = (t_command *)ptr;
	copy = ft_command_copy(command);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_command_free(void *ptr)
{
	t_command	*command;

	command = (t_command *)ptr;
	if (command == NULL)
		return ;
	ft_lstclear(&command->words, ft_word_free);
	ft_lstclear(&command->redirects, ft_redirect_free);
	ft_memdel(command->words);
	ft_memdel(command->redirects);
	ft_memdel(command);
}

void	ft_command_add(t_list **command, int type, t_list *words,
						t_list *redirects)
{
	t_command	*command_new;
	t_list		*words_copy;
	t_list		*redirects_copy;

	words_copy = ft_lstdup(words, ft_word_dup);
	redirects_copy = ft_lstdup(redirects, ft_redirect_dup);
	command_new = ft_command_new(type, words_copy, redirects_copy);
	ft_lstadd_back(command, ft_lstnew(command_new));
}
