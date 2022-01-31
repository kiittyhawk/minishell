#include "libft.h"

void	*ft_memcpy(void *dst, const void *str, size_t n)
{
	unsigned char				*str1;
	const unsigned char			*str2;
	size_t						i;

	str1 = (unsigned char *)dst;
	str2 = (const unsigned char *)str;
	i = 0;
	if (!str1 && !str2)
		return (0);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
