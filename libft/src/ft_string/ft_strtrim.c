/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 02:06:00 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:16 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*tmp;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (str[start] && ft_strchr(set, str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_strchr(set, str[end - 1]))
		end--;
	tmp = (char *)malloc(sizeof(char) * (end - start + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		tmp[i++] = str[start++];
	tmp[i] = 0;
	return (tmp);
}
