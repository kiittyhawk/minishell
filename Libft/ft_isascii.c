#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= (char)0 && c <= (char)127)
		return (1);
	else
		return (0);
}
