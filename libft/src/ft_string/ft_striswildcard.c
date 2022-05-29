/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striswildcard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:27:53 by llornel           #+#    #+#             */
/*   Updated: 2022/03/11 14:51:45 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_striswildcard(char *str)
{
	int	i;

	i = 0;
	if (ft_strisempty(str))
		return (false);
	while (str[i])
	{
		if (!ft_iswildcard(str[i]))
			return (false);
		i++;
	}
	return (true);
}
