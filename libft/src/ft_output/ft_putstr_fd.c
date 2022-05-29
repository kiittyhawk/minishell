/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:47:42 by llornel           #+#    #+#             */
/*   Updated: 2022/02/19 18:43:05 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(int fd, char *str)
{
	size_t	size;

	if (str == NULL)
		return (0);
	size = ft_strlen(str);
	write(fd, str, size);
	return (size);
}

int	ft_putstr(char *str)
{
	return (ft_putstr_fd(STDOUT, str));
}
