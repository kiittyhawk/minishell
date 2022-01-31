#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n >= 0)
			num = n;
		else
		{
			num = -n;
			ft_putchar_fd('-', fd);
		}
		if (num > 9)
			ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd(num % 10 + '0', fd);
	}
}
