/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:52:47 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:05:30 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_heredoc_data(char *str)
{
	char	*tmp;

	if (str == NULL)
		return (NULL);
	tmp = ft_expand_special(str, "$", CH_DOLLAR);
	return (tmp);
}

char	*ft_expand_heredoc_eof(char *str)
{
	char	*tmp;
	char	*word;
	int		start;

	if (str == NULL)
		return (NULL);
	start = 0;
	word = ft_strdup("");
	while (str[start])
	{
		tmp = ft_get_line_word(str, &start);
		ft_strset((void **)&tmp, ft_expand_line(tmp, NULL, 0));
		ft_strset((void **)&word, ft_strjoin(word, tmp));
		ft_memdel(tmp);
		start++;
	}
	return (word);
}
