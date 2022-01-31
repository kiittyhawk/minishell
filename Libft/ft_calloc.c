#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buff;

	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, nmemb * size);
	return (buff);
}
