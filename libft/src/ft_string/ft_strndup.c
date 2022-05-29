/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:49:35 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:12:54 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	len;

	if (src == NULL || n == 0)
		return (NULL);
	len = ft_strlen(src);
	if (len > n)
		len = n;
	dst = (char *)malloc(sizeof(*src) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len + 1);
	dst[len] = '\0';
	return (dst);
}
