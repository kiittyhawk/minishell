#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	s;
	size_t			i;

	str = (unsigned char *)b;
	s = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i] = s;
		i++;
	}
	return (str);
}
