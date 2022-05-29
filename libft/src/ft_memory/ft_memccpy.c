/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:48:22 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:11:36 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	unsigned char		tmp_c;

	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	tmp_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		*(tmp_dst + i) = *(tmp_src + i);
		if (*(tmp_src + i) == tmp_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
