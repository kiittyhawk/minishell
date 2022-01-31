#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	set_len = ft_strlen(set);
	while (*s1)
	{
		if (ft_memchr(set, *s1, set_len) == 0)
			break ;
		s1++;
	}
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_memchr(set, s1[len - 1], set_len) == 0)
			break ;
		len--;
	}
	return (ft_substr(s1, 0, len));
}
