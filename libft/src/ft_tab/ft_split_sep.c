/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:03:53 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:29 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_str(char **split, char const *str,
		char const *sep, int size)
{
	int			start;
	int			end;
	int			i;

	start = 0;
	end = 0;
	i = 0;
	while (i < size)
	{
		while (ft_strchr(sep, str[start]))
			start++;
		end = start;
		while (!ft_strchr(sep, str[end]))
			end++;
		split[i] = ft_substr(str, start, (end - start));
		if (split[i] == NULL)
		{
			ft_split_free(split);
			return (NULL);
		}
		start = end;
		i++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split_sep(char const *str, char const *sep)
{
	char		**split;
	int			size;

	size = 0;
	if (str == NULL || sep == NULL)
		return (NULL);
	size = ft_split_size(str, sep);
	split = (char **)malloc(sizeof(str) * (size + 1));
	if (split == NULL)
		return (NULL);
	ft_split_str(split, str, sep, size);
	if (split == NULL)
		return (NULL);
	return (split);
}
