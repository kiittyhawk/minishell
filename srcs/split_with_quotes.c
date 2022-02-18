/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgyles <jgyles@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:56:52 by jgyles            #+#    #+#             */
/*   Updated: 2022/02/18 16:34:33 by jgyles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			len++;
			if (s[i] && (s[i] == '\'' || s[i] == '"'))
			{
				i++;
				while (s[i] && s[i] != '\'' && s[i] != '"')
					i++;
				i++;
			}
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (len);
}

static char	**ft_clean(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
	return (NULL);
}

static size_t	ft_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	if ((*s == '"' || *s == '\'') && *s)
	{
		s++;
		i++;
		while (*s && *s != '"' && *s != '\'')
		{
			i++;
			s++;
		}
		i++;
		return (i);
	}
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

char *is_quotes(const char *s)
{
	int			i;
	int			j;
	char		*str;
	// char const	*tmp;

	i = 0;
	// s++;
	j = 1;
	// tmp = s;
	while (s[j] && s[j] != '\'' && s[j] != '"')
	{
		i++;
		j++;
		// s++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 1;
	// s = tmp;
	while (s[j] && s[j] != '\'' && s[j] != '"')
	{
		str[j - 1] = s[j];
		// printf("%c = %c\n", str[j - 1], s[j]);
		// str++;
		j++;
		// s++;
	}
	str[j] = '\0';
	// free(tmp);
	return (str);
}

char	**split_with_quotes(char const *s, char c)
{
	char		**array;
	size_t		len_str;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	len_str = ft_count_words(s, c);
	array = ft_calloc(sizeof(char *), (len_str + 1));
	if (!array)
		return (NULL);
	while (i < len_str)
	{
		while (*s == c && *s)
			s++;
		if (*s == '"' || *s == '\'')
		{
			array[i] = is_quotes(s);
		}
		else
			array[i] = ft_substr(s, 0, ft_words_len(s, c));
		if (array[i] == NULL)
			return (ft_clean(array));
		s = s + ft_words_len(s, c);
		i++;
	}
	return (array);
}
