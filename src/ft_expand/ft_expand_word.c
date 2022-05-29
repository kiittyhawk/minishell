/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:59:30 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 17:13:37 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_word(char *str)
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
