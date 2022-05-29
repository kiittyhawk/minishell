/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:55:07 by llornel           #+#    #+#             */
/*   Updated: 2022/02/19 18:52:52 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(int fd, char *str)
{
	int	i;

	i = 0;
	i += ft_putstr_fd(fd, str);
	i += ft_putchar_fd(fd, '\n');
	return (i);
}

int	ft_putendl(char *str)
{
	return (ft_putendl_fd(STDOUT, str));
}
