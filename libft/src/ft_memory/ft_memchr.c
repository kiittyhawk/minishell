/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:30:51 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:11:38 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp_s;
	unsigned char		tmp_c;

	tmp_s = (unsigned char *) s;
	tmp_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*(tmp_s + i) == tmp_c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
