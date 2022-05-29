/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:56:19 by llornel           #+#    #+#             */
/*   Updated: 2022/02/19 18:59:00 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(int fd, unsigned long n, char *base)
{
	unsigned long	base_len;
	unsigned long	num;
	int				i;

	i = 0;
	if (n == 0)
	{
		i += ft_putchar_fd(fd, '0');
		return (i);
	}
	num = n;
	base_len = ft_strlen(base);
	if (num >= base_len)
	{
		i += ft_putnbr_base_fd(fd, num / base_len, base);
		i += ft_putchar_fd(fd, base[num % base_len]);
	}
	else if (num < base_len)
		i += ft_putchar_fd(fd, base[num]);
	return (i);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	return (ft_putnbr_base_fd(STDOUT, n, base));
}
