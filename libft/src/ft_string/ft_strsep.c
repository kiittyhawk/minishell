/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:19:37 by llornel           #+#    #+#             */
/*   Updated: 2022/03/10 02:46:11 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsep(const char *str, const char *sep)
{
	int	i;
	int	j;

	if (str == NULL || sep == NULL)
		return (-1);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (sep[j])
		{
			if (str[i] == sep[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
