/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:52:47 by llornel           #+#    #+#             */
/*   Updated: 2022/03/24 17:05:30 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_expand_dollar(char *str, int *start)
{
	char	*tmp;

	if (str == NULL || str[*start] != DOLLAR_CHAR)
		return (str);
	*start += 1;
	if (str[*start] == BANG_CHAR)
		tmp = ft_itoa(ft_get_exit_status());
	else if (ft_isdigit(str[*start]))
		tmp = ft_strdup("");
	else if (ft_is_name_starter(str[*start]))
		tmp = ft_get_expand_env(str, start);
	else
	{
		*start -= 1;
		tmp = ft_substr(str, *start, 1);
	}
	return (tmp);
}

char	*ft_expand_dollar(char *str)
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
		ft_strset((void **)&tmp, ft_expand_line(tmp, "$", CH_DOLLAR));
		ft_strset((void **)&word, ft_strjoin(word, tmp));
		ft_memdel(tmp);
		start++;
	}
	return (word);
}
