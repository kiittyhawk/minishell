#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	if (!s)
		return (NULL);
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
