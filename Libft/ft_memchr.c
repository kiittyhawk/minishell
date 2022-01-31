#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		sym;
	size_t				i;

	str = (const unsigned char *)s;
	sym = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == sym)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
