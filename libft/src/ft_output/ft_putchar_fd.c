/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:46:07 by llornel           #+#    #+#             */
/*   Updated: 2022/02/19 18:36:28 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putchar(char c)
{
	return (ft_putchar_fd(STDOUT, c));
}

int	ft_putnchar_fd(int fd, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(fd, c);
		i++;
	}
	return (i);
}

int	ft_putnchar(char c, int n)
{
	return (ft_putnchar_fd(STDOUT, c, n));
}
