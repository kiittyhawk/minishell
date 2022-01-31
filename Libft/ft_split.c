#include "libft.h"

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
			len++;
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
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
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
		array[i] = ft_substr(s, 0, ft_words_len(s, c));
		if (array[i] == NULL)
			return (ft_clean(array));
		s = s + ft_words_len(s, c);
		i++;
	}
	return (array);
}
