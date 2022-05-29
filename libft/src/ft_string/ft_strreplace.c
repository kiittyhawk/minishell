/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:29:32 by llornel           #+#    #+#             */
/*   Updated: 2022/03/22 05:07:33 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char const *str, char const *set)
{
	char	*tmp;
	char	*sub;
	size_t	start;
	size_t	end;

	start = 0;
	tmp = ft_strdup("");
	while (str[start] != '\0')
	{
		while (str[start] != '\0' && ft_strchr(set, str[start]))
			start++;
		end = start;
		while (str[end] != '\0' && !ft_strchr(set, str[end]))
			end++;
		sub = ft_substr(str, start, end - start);
		if (sub != NULL)
		{
			ft_strset((void **)&tmp, ft_strjoin(tmp, sub));
			ft_memdel(sub);
		}
		start = end;
	}
	return (tmp);
}
