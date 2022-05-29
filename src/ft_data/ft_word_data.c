/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:31:35 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 03:20:33 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*ft_word_new(int type, char *data, char *original)
{
	t_word	*word;

	word = malloc(sizeof(t_word));
	if (word == NULL)
		return (NULL);
	word->type = type;
	word->data = data;
	word->original = original;
	return (word);
}

t_word	*ft_word_copy(t_word *word)
{
	t_word	*copy;
	char	*data;
	char	*original;

	if (word == NULL)
		return (NULL);
	data = ft_strdup(word->data);
	original = ft_strdup(word->original);
	copy = ft_word_new(word->type, data, original);
	if (copy == NULL)
	{
		ft_memdel(data);
		ft_memdel(original);
		return (NULL);
	}
	return (copy);
}

void	*ft_word_dup(void *ptr)
{
	t_word	*word;
	t_word	*copy;

	word = (t_word *)ptr;
	copy = ft_word_copy(word);
	if (copy == NULL)
		return (NULL);
	return ((void *)copy);
}

void	ft_word_free(void *ptr)
{
	t_word	*word;

	word = (t_word *)ptr;
	if (word == NULL)
		return ;
	ft_memdel(word->data);
	ft_memdel(word->original);
	ft_memdel(word);
}

void	ft_word_add(t_list **words, int type, char *data, char *original)
{
	t_word	*word_new;
	char	*data_copy;
	char	*original_copy;

	data_copy = ft_strdup(data);
	original_copy = ft_strdup(original);
	word_new = ft_word_new(type, data_copy, original_copy);
	ft_lstadd_back(words, ft_lstnew(word_new));
}
