/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:52:03 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:08 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *sep)
{
	static char		*ptr;
	char			*tmp;

	if (!str)
		str = *ptr;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str == '\0')
		return (NULL);
	tmp = str;
	while (*str && !ft_strchr(sep, *str))
		++str;
	if (*str)
		*str++ = '\0';
	*ptr = str;
	return (tmp);
}
