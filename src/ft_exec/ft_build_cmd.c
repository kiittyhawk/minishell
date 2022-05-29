/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:45:03 by llornel           #+#    #+#             */
/*   Updated: 2022/03/26 19:11:25 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_cmd(t_list **words, int *type)
{
	t_word	*word;
	char	*str;
	int		is_quote;

	str = (char *) NULL;
	is_quote = 0;
	while (*words && (ft_strisempty(((t_word *)(*words)->content)->data) == 0
		|| ((t_word *)(*words)->content)->type != 0))
	{
		word = (t_word *)(*words)->content;
		if (ft_is_quote(word->type) == 1)
		{
			*type = TOKEN_NONE;
			is_quote = 1;
		}
		else if (is_quote == 0)
			*type = word->type;
		if (str == NULL)
			str = ft_strdup(word->data);
		else
			ft_strset((void **)&str, ft_strjoin(str, word->data));
		*words = (*words)->next;
	}
	return (str);
}

static t_list	*ft_join_cmds(t_list *words)
{
	t_list	*new_words;
	t_list	*tmp_words;
	char	*str;
	int		type;

	tmp_words = words;
	new_words = (t_list *) NULL;
	while (words)
	{
		while (words && ft_strisempty(((t_word *)words->content)->data) == 1
			&& ((t_word *)words->content)->type == 0)
			words = words->next;
		str = ft_get_cmd(&words, &type);
		if (str != NULL)
		{
			ft_word_add(&new_words, type, str, str);
			ft_memdel(str);
		}
	}
	ft_lstclear(&tmp_words, ft_word_free);
	ft_memdel(tmp_words);
	return (new_words);
}

static void	ft_split_words(t_list **words, char *data, int flag)
{
	char	**tab;
	int		type;
	int		i;

	tab = ft_split(data, ' ');
	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		if (ft_striswildcard(tab[i]))
			type = TOKEN_WILDCARD;
		else
			type = ft_find_code_in_list(tab[i]);
		if (i != 0 && (flag & CH_WORD))
			ft_word_add(words, TOKEN_EMPTY, WORD_EMPTY, WORD_EMPTY);
		ft_word_add(words, type, tab[i], tab[i]);
		i++;
	}
	ft_tabfree(tab);
}

static t_list	*ft_split_cmds(t_list *words, int flag)
{
	t_list	*new_words;
	t_list	*tmp_words;
	t_word	*word;

	tmp_words = words;
	new_words = (t_list *) NULL;
	while (words)
	{
		word = (t_word *)words->content;
		if (ft_iswildcard(word->type) && (flag & CH_WILDCARD))
			ft_split_words(&new_words, word->data, CH_WILDCARD);
		else if (word->type == TOKEN_WORD && (flag & CH_WORD))
			ft_split_words(&new_words, word->data, CH_WORD);
		else
			ft_word_add(&new_words, word->type, word->data, word->original);
		words = words->next;
	}
	ft_lstclear(&tmp_words, ft_word_free);
	ft_memdel(tmp_words);
	return (new_words);
}

int	ft_build_cmd(t_list **exec_cmds, t_command *command)
{
	t_exec_cmd	*exec_cmd;
	int			ret;
	char		**cmd;
	t_list		*redirects;

	ret = EXIT_SUCCESS;
	ft_lstiter(command->words, ft_expand_word_iter);
	command->words = ft_split_cmds(command->words, CH_WORD);
	command->words = ft_join_cmds(command->words);
	ft_lstiter(command->words, ft_expand_wildcard_iter);
	command->words = ft_split_cmds(command->words, CH_WILDCARD);
	cmd = ft_list_to_tab(command->words, ft_copy_data_from_word);
	redirects = ft_lstdup(command->redirects, ft_redirect_dup);
	ft_lstiter(redirects, ft_expand_redirect_iter);
	exec_cmd = ft_exec_cmd_new(cmd, command->type, 0, redirects);
	ft_lstadd_back(exec_cmds, ft_lstnew(exec_cmd));
	return (ret);
}
