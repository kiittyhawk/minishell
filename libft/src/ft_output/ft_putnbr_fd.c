/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:16:43 by llornel           #+#    #+#             */
/*   Updated: 2022/02/19 18:54:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int fd, int n)
{
	int	i;

	i = 0;
	if (n == MIN_INT)
	{
		i += ft_putnbr_fd(fd, n / 10);
		i += ft_putnbr_fd(fd, -(n % 10));
	}
	else if (n < 0)
	{
		i += ft_putchar_fd(fd, '-');
		i += ft_putnbr_fd(fd, -n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd(fd, n / 10);
		i += ft_putnbr_fd(fd, n % 10);
	}
	else
	{
		i += ft_putchar_fd(fd, n + 48);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	return (ft_putnbr_fd(STDOUT, n));
}
