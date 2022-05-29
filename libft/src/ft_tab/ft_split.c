/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:49:16 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:34 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_split_free2(char **str, int size)
{
	int	i;

	i = 0;
	while (str[i] && i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static int	ft_split_size2(char const *str, char c)
{
	int		i;
	int		size;
	int		check;

	i = 0;
	size = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == c) && (check == 1))
			check = 0;
		else if ((str[i] != c) && (check == 0))
		{
			check = 1;
			size++;
		}
		i++;
	}
	return (size);
}

static char	**ft_split_str2(char **split, char const *str, char c, int size)
{
	int			start;
	int			end;
	int			i;

	start = 0;
	end = 0;
	i = 0;
	while (i < size)
	{
		while (str[start] && str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		split[i] = ft_substr(str, start, (end - start));
		if (split[i] == NULL)
		{
			ft_split_free2(split, size);
			return (NULL);
		}
		start = end;
		i++;
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	int			size;

	size = 0;
	if (s && *s)
		size = ft_split_size2(s, c);
	split = (char **)malloc(sizeof(s) * (size + 1));
	if (split == NULL)
		return (NULL);
	ft_split_str2(split, s, c, size);
	if (split == NULL)
		return (NULL);
	return (split);
}
