/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:19:50 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 16:57:48 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_special(char *str, char *sep, int flag)
{
	char	*tmp;
	char	*word;
	int		start;

	if (str == NULL)
		return (NULL);
	word = ft_strdup("");
	start = 0;
	while (str[start])
	{
		if (str[start] == DOLLAR_CHAR && (flag & CH_DOLLAR))
			tmp = ft_get_expand_dollar(str, &start);
		else
			tmp = ft_get_line_others(str, &start, sep);
		if (tmp != NULL)
			ft_strset((void **)&word, ft_strjoin(word, tmp));
		ft_memdel(tmp);
		start++;
	}
	return (word);
}

char	*ft_expand_line(char *str, char *sep, int flags)
{
	char	*tmp;
	int		size;

	size = ft_strlen(str);
	if (ft_strncmp(str, WORD_DQUOTE, 1) == 0)
		tmp = ft_substr(str, 1, size - 2);
	else if (ft_strncmp(str, WORD_SQUOTE, 1) == 0)
		tmp = ft_substr(str, 1, size - 2);
	else
		tmp = ft_substr(str, 0, size);
	if (ft_strncmp(str, WORD_SQUOTE, 1) != 0 && flags != 0)
		ft_strset((void **)&tmp, ft_expand_special(tmp, sep, flags));
	return (tmp);
}
