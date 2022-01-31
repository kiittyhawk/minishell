#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str2;
	size_t		i;
	size_t		len2;

	i = 0;
	len2 = len;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len2 = ft_strlen(s) - start;
	str2 = malloc(sizeof(char) * len2 + 1);
	if (str2 == NULL)
		return (NULL);
	while (i < len && s[i])
	{
		str2[i] = s[start + i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
