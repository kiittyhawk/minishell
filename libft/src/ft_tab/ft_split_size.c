/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:29:29 by llornel           #+#    #+#             */
/*   Updated: 2022/02/18 12:13:32 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_size(char const *str, char const *sep)
{
	int		i;
	int		size;
	int		check;

	i = 0;
	size = 0;
	check = 0;
	while (str[i])
	{
		if (ft_strchr(sep, str[i]) && (check == 1))
			check = 0;
		else if ((!ft_strchr(sep, str[i])) && (check == 0))
		{
			check = 1;
			size++;
		}
		i++;
	}
	return (size);
}
