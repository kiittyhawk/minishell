#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	unsigned int	len;

	str = (unsigned char *)s;
	len = (unsigned int)n;
	while (len != 0)
	{
		*str++ = '\0';
		len--;
	}
	return (str);
}
